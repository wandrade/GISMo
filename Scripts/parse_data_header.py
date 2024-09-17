#!/usr/bin/env python3

import sys
import re
import json

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

if __name__ == "__main__":
    default_file_path = './Firmware/GISMo/Inc/data.h'
    file_path = sys.argv[1] if len(sys.argv) > 1 else default_file_path
    process_file(file_path)
