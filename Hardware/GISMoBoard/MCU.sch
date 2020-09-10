EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title "G.I.S.Mo"
Date "06/09"
Rev "0.1"
Comp ""
Comment1 "Werner Thomassen Andrade"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	6050 4950 6050 5000
Connection ~ 6050 4950
$Comp
L power:GND #PWR0113
U 1 1 5F2B0988
P 6050 5000
F 0 "#PWR0113" H 6050 4750 50  0001 C CNN
F 1 "GND" H 6055 4827 50  0000 C CNN
F 2 "" H 6050 5000 50  0001 C CNN
F 3 "" H 6050 5000 50  0001 C CNN
	1    6050 5000
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0114
U 1 1 5F2B1563
P 6700 2950
F 0 "#PWR0114" H 6700 2800 50  0001 C CNN
F 1 "+3V3" H 6715 3123 50  0000 C CNN
F 2 "" H 6700 2950 50  0001 C CNN
F 3 "" H 6700 2950 50  0001 C CNN
	1    6700 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3050 6000 3050
$Comp
L pspice:INDUCTOR L1
U 1 1 5F2B3749
P 6400 3000
F 0 "L1" H 6500 2950 50  0000 C CNN
F 1 "22uh" H 6500 3100 50  0000 C CNN
F 2 "Inductor_SMD:L_0603_1608Metric" H 6400 3000 50  0001 C CNN
F 3 "~" H 6400 3000 50  0001 C CNN
F 4 "https://www.mouser.co.uk/ProductDetail/TDK/KLZ1608MHR220WTD25?qs=5aG0NVq1C4xGlXA3NjQgYw%3D%3D" H 6400 3000 50  0001 C CNN "Mouser"
	1    6400 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 5F2B4980
P 6100 2800
F 0 "C14" H 6100 2900 50  0000 L CNN
F 1 "10nF" H 6100 2700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6138 2650 50  0001 C CNN
F 3 "~" H 6100 2800 50  0001 C CNN
	1    6100 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5F2B53E3
P 5700 2800
F 0 "C12" H 5700 2900 50  0000 L CNN
F 1 "10nF" H 5700 2700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5738 2650 50  0001 C CNN
F 3 "~" H 5700 2800 50  0001 C CNN
	1    5700 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5F2B5AF8
P 5900 2800
F 0 "C13" H 5900 2900 50  0000 L CNN
F 1 "10nF" H 5900 2700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5938 2650 50  0001 C CNN
F 3 "~" H 5900 2800 50  0001 C CNN
	1    5900 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2950 5900 3050
$Comp
L Device:C C11
U 1 1 5F2B68B6
P 5500 2800
F 0 "C11" H 5500 2900 50  0000 L CNN
F 1 "4.7uF" H 5500 2700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5538 2650 50  0001 C CNN
F 3 "~" H 5500 2800 50  0001 C CNN
	1    5500 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2950 5700 2950
Wire Wire Line
	5500 2650 5700 2650
$Comp
L power:GND #PWR0115
U 1 1 5F2B7856
P 5500 2650
F 0 "#PWR0115" H 5500 2400 50  0001 C CNN
F 1 "GND" H 5505 2477 50  0000 C CNN
F 2 "" H 5500 2650 50  0001 C CNN
F 3 "" H 5500 2650 50  0001 C CNN
	1    5500 2650
	0    1    1    0   
$EndComp
Connection ~ 5900 2950
Connection ~ 5700 2950
Wire Wire Line
	5700 2950 5900 2950
Wire Wire Line
	6700 2950 6700 3000
Wire Wire Line
	6700 3000 6650 3000
Wire Wire Line
	6150 3000 6100 3000
Wire Wire Line
	6100 3000 6100 3050
Wire Wire Line
	6100 3000 6100 2950
Connection ~ 6100 3000
Wire Wire Line
	6100 2650 5900 2650
Connection ~ 5700 2650
Connection ~ 5900 2650
Text HLabel 5400 4750 0    50   Input ~ 0
SDA
Text HLabel 5400 4650 0    50   Input ~ 0
SCL
Text HLabel 6600 4250 2    50   Input ~ 0
PWM_IN
$Comp
L Device:R R9
U 1 1 5F26E6A2
P 5250 3450
F 0 "R9" V 5150 3550 50  0000 C CNN
F 1 "10k" V 5150 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5180 3450 50  0001 C CNN
F 3 "~" H 5250 3450 50  0001 C CNN
	1    5250 3450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 5F26F2E1
P 5100 3450
F 0 "#PWR0119" H 5100 3200 50  0001 C CNN
F 1 "GND" H 5105 3277 50  0000 C CNN
F 2 "" H 5100 3450 50  0001 C CNN
F 3 "" H 5100 3450 50  0001 C CNN
	1    5100 3450
	0    1    1    0   
$EndComp
Text HLabel 6600 3350 2    50   Input ~ 0
I_Sense
Text HLabel 6600 3550 2    50   Input ~ 0
PWM_OUT
Text HLabel 6600 3650 2    50   Input ~ 0
~SLEEP
Text HLabel 6600 3750 2    50   Input ~ 0
~FAULT
Text HLabel 6600 3450 2    50   Input ~ 0
Direction
$Comp
L Device:R R8
U 1 1 5F271AC3
P 5250 3250
F 0 "R8" V 5150 3350 50  0000 C CNN
F 1 "10k" V 5150 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5180 3250 50  0001 C CNN
F 3 "~" H 5250 3250 50  0001 C CNN
	1    5250 3250
	0    1    1    0   
$EndComp
Text HLabel 6600 4450 2    50   Input ~ 0
LED_R
Text HLabel 6600 4350 2    50   Input ~ 0
LED_G
Text HLabel 6600 4150 2    50   Input ~ 0
LED_B
$Comp
L Connector:TestPoint TP1
U 1 1 5F2B6E88
P 5400 4250
F 0 "TP1" V 5400 4750 50  0000 C CNN
F 1 "PB0" V 5400 4500 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 5600 4250 50  0001 C CNN
F 3 "~" H 5600 4250 50  0001 C CNN
	1    5400 4250
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR0123
U 1 1 5F30A0B4
P 5500 2950
F 0 "#PWR0123" H 5500 2800 50  0001 C CNN
F 1 "+3V3" H 5515 3123 50  0000 C CNN
F 2 "" H 5500 2950 50  0001 C CNN
F 3 "" H 5500 2950 50  0001 C CNN
	1    5500 2950
	0    -1   -1   0   
$EndComp
Connection ~ 5500 2950
Connection ~ 5500 2650
Wire Wire Line
	5700 2650 5900 2650
$Comp
L power:+3V3 #PWR0120
U 1 1 5F2721CB
P 5100 3250
F 0 "#PWR0120" H 5100 3100 50  0001 C CNN
F 1 "+3V3" H 5115 3423 50  0000 C CNN
F 2 "" H 5100 3250 50  0001 C CNN
F 3 "" H 5100 3250 50  0001 C CNN
	1    5100 3250
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR0125
U 1 1 5F2CB7E3
P 3850 5150
F 0 "#PWR0125" H 3850 5000 50  0001 C CNN
F 1 "+3V3" H 3865 5323 50  0000 C CNN
F 2 "" H 3850 5150 50  0001 C CNN
F 3 "" H 3850 5150 50  0001 C CNN
	1    3850 5150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3950 5300 3950 5200
Wire Wire Line
	3950 5150 3850 5150
Connection ~ 3950 5200
Wire Wire Line
	3950 5200 3950 5150
Wire Wire Line
	3950 5150 3950 5100
Connection ~ 3950 5150
Wire Wire Line
	3950 5100 3950 5000
Connection ~ 3950 5100
Text Label 5400 4350 2    50   ~ 0
AD1
Text Label 5400 4450 2    50   ~ 0
AD2
Text Label 5400 4550 2    50   ~ 0
AD3
Text Label 4500 5100 0    50   ~ 0
AD1
Text Label 4500 5200 0    50   ~ 0
AD2
Text Label 4500 5300 0    50   ~ 0
AD3
Text Label 6600 4750 0    50   ~ 0
AD0
Text Label 4500 5000 0    50   ~ 0
AD0
$Comp
L Connector:TestPoint TP4
U 1 1 5F55A7DD
P 6600 3250
F 0 "TP4" V 6600 3750 50  0000 C CNN
F 1 "PA0" V 6600 3500 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 6800 3250 50  0001 C CNN
F 3 "~" H 6800 3250 50  0001 C CNN
	1    6600 3250
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP5
U 1 1 5F55B637
P 6600 3850
F 0 "TP5" V 6600 4350 50  0000 C CNN
F 1 "PA6" V 6600 4100 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 6800 3850 50  0001 C CNN
F 3 "~" H 6800 3850 50  0001 C CNN
	1    6600 3850
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP6
U 1 1 5F55BB5A
P 6600 3950
F 0 "TP6" V 6600 4450 50  0000 C CNN
F 1 "PA7" V 6600 4200 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 6800 3950 50  0001 C CNN
F 3 "~" H 6800 3950 50  0001 C CNN
	1    6600 3950
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP7
U 1 1 5F55BD8C
P 6600 4050
F 0 "TP7" V 6600 4550 50  0000 C CNN
F 1 "PA8" V 6600 4300 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 6800 4050 50  0001 C CNN
F 3 "~" H 6800 4050 50  0001 C CNN
	1    6600 4050
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP8
U 1 1 5F55C018
P 6600 4550
F 0 "TP8" V 6600 5050 50  0000 C CNN
F 1 "PA13" V 6600 4800 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 6800 4550 50  0001 C CNN
F 3 "~" H 6800 4550 50  0001 C CNN
	1    6600 4550
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP9
U 1 1 5F55C44A
P 6600 4650
F 0 "TP9" V 6600 5150 50  0000 C CNN
F 1 "PA14" V 6600 4900 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 6800 4650 50  0001 C CNN
F 3 "~" H 6800 4650 50  0001 C CNN
	1    6600 4650
	0    1    1    0   
$EndComp
Connection ~ 5900 3050
Connection ~ 6000 4950
Wire Wire Line
	6000 4950 6050 4950
Wire Wire Line
	5900 4950 6000 4950
Connection ~ 6100 4950
Wire Wire Line
	6050 4950 6100 4950
Wire Wire Line
	6200 4950 6100 4950
$Comp
L MCU_ST_STM32F3:STM32F302K8Ux U2
U 1 1 5F2E7570
P 6000 3950
F 0 "U2" H 6000 5031 50  0000 C CNN
F 1 "STM32F302K8Ux" H 6550 3000 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_5x5mm_P0.5mm_EP3.45x3.45mm" H 5500 3050 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00093333.pdf" H 6000 3950 50  0001 C CNN
	1    6000 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP3
U 1 1 5F560EA7
P 5400 4050
F 0 "TP3" V 5400 4550 50  0000 C CNN
F 1 "PF1" V 5400 4300 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 5600 4050 50  0001 C CNN
F 3 "~" H 5600 4050 50  0001 C CNN
	1    5400 4050
	0    -1   -1   0   
$EndComp
$Comp
L Connector:TestPoint TP2
U 1 1 5F5612A1
P 5400 3950
F 0 "TP2" V 5400 4450 50  0000 C CNN
F 1 "PF0" V 5400 4200 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D1.0mm" H 5600 3950 50  0001 C CNN
F 3 "~" H 5600 3950 50  0001 C CNN
	1    5400 3950
	0    -1   -1   0   
$EndComp
$Comp
L Device:Jumper_NO_Small AD1
U 1 1 5F56CE7F
P 4250 5000
F 0 "AD1" H 4350 5050 50  0000 C CNN
F 1 "AD0" H 4150 5050 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 4250 5000 50  0001 C CNN
F 3 "~" H 4250 5000 50  0001 C CNN
	1    4250 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 5000 4150 5000
Wire Wire Line
	4350 5000 4500 5000
$Comp
L Device:Jumper_NO_Small AD2
U 1 1 5F574C13
P 4250 5100
F 0 "AD2" H 4350 5150 50  0000 C CNN
F 1 "AD1" H 4150 5150 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 4250 5100 50  0001 C CNN
F 3 "~" H 4250 5100 50  0001 C CNN
	1    4250 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NO_Small AD3
U 1 1 5F574DE4
P 4250 5200
F 0 "AD3" H 4350 5250 50  0000 C CNN
F 1 "AD2" H 4150 5250 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 4250 5200 50  0001 C CNN
F 3 "~" H 4250 5200 50  0001 C CNN
	1    4250 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NO_Small AD4
U 1 1 5F575070
P 4250 5300
F 0 "AD4" H 4350 5350 50  0000 C CNN
F 1 "AD3" H 4150 5350 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 4250 5300 50  0001 C CNN
F 3 "~" H 4250 5300 50  0001 C CNN
	1    4250 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 5100 4150 5100
Wire Wire Line
	3950 5200 4150 5200
Wire Wire Line
	3950 5300 4150 5300
Wire Wire Line
	4350 5100 4500 5100
Wire Wire Line
	4350 5200 4500 5200
Wire Wire Line
	4350 5300 4500 5300
$EndSCHEMATC
