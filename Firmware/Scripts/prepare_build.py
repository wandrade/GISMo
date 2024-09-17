#!/usr/bin/env python3

import sys
import re
import json
import subprocess

size_map = {
    'uint8_t': 1,
    'int8_t': 1,
    'uint16_t': 2,
    'int16_t': 2,
    'uint32_t': 4,
    'int32_t': 4,
    'float': 4
}

def calculate_offset(data_type, current_offset):
    return current_offset + size_map.get(data_type, 0)

def process_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    struct_start = False
    current_offset = 0
    processed_lines = []
    register_info = []

    for line in lines:
        if 'typedef struct' in line:
            struct_start = True
        if struct_start and '}' in line:
            struct_start = False

        if struct_start and ';' in line:
            match = re.match(r'(\s*)(\w+)\s+(\w+);', line)
            if match:
                _, data_type, var_name = match.groups()
                comment = f'// 0x{current_offset:02X}'
                line = f'{"    "}{data_type}{" " * (5*4 - (4 + len(data_type)))}{var_name};'
                line = f'{line}{" " * ((4*20) - len(line))}{comment}\n'
                register_info.append({
                    'name': var_name,
                    'register': f'0x{current_offset:02X}',
                    'type': data_type,
                    'size': size_map[data_type]
                })
                current_offset = calculate_offset(data_type, current_offset)

        processed_lines.append(line)

    with open(file_path, 'w') as file:
        file.writelines(processed_lines)

    with open('./Firmware/registers.json', 'w') as json_file:
        json.dump(register_info, json_file, indent=4)

    # Read VERSION file and update variables in data.c
    version_file_path = './Firmware/VERSION'
    with open(version_file_path, 'r') as version_file:
        version = version_file.read().strip()

    data_c_file_path = './Firmware/GISMo/Src/data.c'
    with open(data_c_file_path, 'r') as data_c_file:
        data_c_lines = data_c_file.readlines()

    updated_data_c_lines = []
    for line in data_c_lines:
        if 'd->version_major' in line:
            line = re.sub(r'version_major\s*=\s*\d+', f'version_major = {version.split(".")[0]}', line)
        elif 'd->version_minor' in line:
            line = re.sub(r'version_minor\s*=\s*\d+', f'version_minor = {version.split(".")[1]}', line)
        updated_data_c_lines.append(line)
    
    # Get current git commit hash
    commit_hash = subprocess.check_output(['git', 'rev-parse', 'HEAD']).decode().strip()
    # Check if the repository is clean
    is_clean = subprocess.check_output(['git', 'status', '--porcelain']).decode().strip() == ''
    # Update d->commit_hash in data.c
    short_commit_hash = commit_hash[:7]  # Get the first 7 characters of the commit hash
    formatted_commit_hash = f'{"0x0" if is_clean else "0x1"}{short_commit_hash}'
    for i, line in enumerate(updated_data_c_lines):
        if 'd->commit_hash' in line:
            updated_data_c_lines[i] = re.sub(r'commit_hash\s*=\s*0x[0-9A-Fa-f]+', f'commit_hash = {formatted_commit_hash}', line)
    with open(data_c_file_path, 'w') as data_c_file:
        data_c_file.writelines(updated_data_c_lines)

    # Format data.c and data.h using .clang-format
    clang_format_command = ['clang-format', '-i', './Firmware/GISMo/Src/data.c', './Firmware/GISMo/Inc/data.h']
    subprocess.run(clang_format_command)


if __name__ == "__main__":
    default_file_path = './Firmware/GISMo/Inc/data.h'
    file_path = sys.argv[1] if len(sys.argv) > 1 else default_file_path
    process_file(file_path)
