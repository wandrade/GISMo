EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "G.I.S.Mo"
Date "06/09"
Rev "0.1"
Comp "https://github.com/wandrade/gismo"
Comment1 "Werner Thomassen Andrade"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DRV8876:DRV8876RGTR U1
U 1 1 5F2569A2
P 5200 3100
F 0 "U1" H 6100 3250 50  0000 C CNN
F 1 "DRV8876RGTR" H 6500 3250 50  0000 C CNN
F 2 "TI DRV:Texas_Instruments-RGT0016C-0-0-MFG" H 5200 3500 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8876.pdf" H 5200 3600 50  0001 L CNN
F 4 "+125°C" H 5200 3700 50  0001 L CNN "ambient temperature range high"
F 5 "-40°C" H 5200 3800 50  0001 L CNN "ambient temperature range low"
F 6 "No" H 5200 3900 50  0001 L CNN "automotive"
F 7 "IC" H 5200 4000 50  0001 L CNN "category"
F 8 "Integrated Circuits (ICs)" H 5200 4100 50  0001 L CNN "device class L1"
F 9 "Power Management ICs" H 5200 4200 50  0001 L CNN "device class L2"
F 10 "Motor Drivers" H 5200 4300 50  0001 L CNN "device class L3"
F 11 "1mm" H 5200 4400 50  0001 L CNN "height"
F 12 "Yes" H 5200 4500 50  0001 L CNN "lead free"
F 13 "6bcdda277d4bb50d" H 5200 4600 50  0001 L CNN "library id"
F 14 "Texas Instruments" H 5200 4700 50  0001 L CNN "manufacturer"
F 15 "+150°C" H 5200 4800 50  0001 L CNN "max junction temp"
F 16 "37V" H 5200 4900 50  0001 L CNN "max supply voltage"
F 17 "4.5V" H 5200 5000 50  0001 L CNN "min supply voltage"
F 18 "Brushed" H 5200 5100 50  0001 L CNN "motor type"
F 19 "595-DRV8876RGTR" H 5200 5200 50  0001 L CNN "mouser part number"
F 20 "2" H 5200 5300 50  0001 L CNN "number of outputs"
F 21 "3.5A" H 5200 5400 50  0001 L CNN "output current"
F 22 "VQFN16" H 5200 5500 50  0001 L CNN "package"
F 23 "Yes" H 5200 5600 50  0001 L CNN "rohs"
F 24 "0mm" H 5200 5700 50  0001 L CNN "standoff height"
F 25 "100kHz" H 5200 5800 50  0001 L CNN "switching frequency"
F 26 "+150°C" H 5200 5900 50  0001 L CNN "temperature range high"
F 27 "-40°C" H 5200 6000 50  0001 L CNN "temperature range low"
	1    5200 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4300 5050 4300
Wire Wire Line
	5050 4300 5050 4500
Wire Wire Line
	6800 4600 6850 4600
Wire Wire Line
	6850 5300 6050 5300
$Comp
L power:GND #PWR0108
U 1 1 5F257E7A
P 6050 5300
F 0 "#PWR0108" H 6050 5050 50  0001 C CNN
F 1 "GND" H 6055 5127 50  0000 C CNN
F 2 "" H 6050 5300 50  0001 C CNN
F 3 "" H 6050 5300 50  0001 C CNN
	1    6050 5300
	1    0    0    -1  
$EndComp
Connection ~ 6050 5300
Wire Wire Line
	6050 5300 5050 5300
$Comp
L Device:R R7
U 1 1 5F258823
P 6900 3650
F 0 "R7" H 6970 3696 50  0000 L CNN
F 1 "10K" H 6970 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6830 3650 50  0001 C CNN
F 3 "~" H 6900 3650 50  0001 C CNN
	1    6900 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0109
U 1 1 5F2591E8
P 6900 3900
F 0 "#PWR0109" H 6900 3750 50  0001 C CNN
F 1 "+3V3" H 6915 4073 50  0000 C CNN
F 2 "" H 6900 3900 50  0001 C CNN
F 3 "" H 6900 3900 50  0001 C CNN
	1    6900 3900
	-1   0    0    1   
$EndComp
Wire Wire Line
	5300 4500 5050 4500
Connection ~ 5050 4500
Wire Wire Line
	5050 4500 5050 5300
$Comp
L Device:R R6
U 1 1 5F25C897
P 4850 5100
F 0 "R6" H 4780 5054 50  0000 R CNN
F 1 "2K" H 4780 5145 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4780 5100 50  0001 C CNN
F 3 "~" H 4850 5100 50  0001 C CNN
	1    4850 5100
	-1   0    0    1   
$EndComp
Wire Wire Line
	5300 4900 4850 4900
Wire Wire Line
	4850 4900 4850 4950
Wire Wire Line
	4850 5250 4850 5300
Wire Wire Line
	4850 5300 5050 5300
Connection ~ 5050 5300
Wire Wire Line
	6850 4600 6850 5300
Wire Wire Line
	6800 4700 7050 4700
Wire Wire Line
	7050 4700 7050 5300
$Comp
L power:GNDPWR #PWR0110
U 1 1 5F25DEB7
P 7050 5300
F 0 "#PWR0110" H 7050 5100 50  0001 C CNN
F 1 "GNDPWR" H 7054 5146 50  0000 C CNN
F 2 "" H 7050 5250 50  0001 C CNN
F 3 "" H 7050 5250 50  0001 C CNN
	1    7050 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5F25E5DF
P 4600 4500
F 0 "R4" H 4530 4454 50  0000 R CNN
F 1 "1.5K" H 4530 4545 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4530 4500 50  0001 C CNN
F 3 "~" H 4600 4500 50  0001 C CNN
	1    4600 4500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5F25EC09
P 4600 4900
F 0 "R5" H 4530 4854 50  0000 R CNN
F 1 "50K" H 4530 4945 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4530 4900 50  0001 C CNN
F 3 "~" H 4600 4900 50  0001 C CNN
	1    4600 4900
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR0111
U 1 1 5F25F781
P 4600 4350
F 0 "#PWR0111" H 4600 4200 50  0001 C CNN
F 1 "+3V3" H 4615 4523 50  0000 C CNN
F 2 "" H 4600 4350 50  0001 C CNN
F 3 "" H 4600 4350 50  0001 C CNN
	1    4600 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4650 4600 4700
Wire Wire Line
	4600 4700 5300 4700
Connection ~ 4600 4700
Wire Wire Line
	4600 4700 4600 4750
Wire Wire Line
	4600 5050 4600 5300
Wire Wire Line
	4600 5300 4850 5300
Connection ~ 4850 5300
$Comp
L Device:C C3
U 1 1 5F266FE2
P 5050 3400
F 0 "C3" V 5000 3500 50  0000 C CNN
F 1 "0.022uf" V 5000 3200 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5088 3250 50  0001 C CNN
F 3 "~" H 5050 3400 50  0001 C CNN
	1    5050 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	5200 3400 5300 3400
Wire Wire Line
	4900 3400 4900 3500
Wire Wire Line
	4900 3500 5300 3500
Wire Wire Line
	4900 3100 4900 3200
Wire Wire Line
	4900 3200 5300 3200
$Comp
L Device:C C2
U 1 1 5F26A285
P 5050 3100
F 0 "C2" V 5000 3200 50  0000 C CNN
F 1 "0.1uF" V 5000 2900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5088 2950 50  0001 C CNN
F 3 "~" H 5050 3100 50  0001 C CNN
	1    5050 3100
	0    1    1    0   
$EndComp
$Comp
L Device:C C4
U 1 1 5F26BF66
P 5600 2600
F 0 "C4" H 5550 2700 50  0000 C CNN
F 1 "0.1uF" H 5500 2500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5638 2450 50  0001 C CNN
F 3 "~" H 5600 2600 50  0001 C CNN
	1    5600 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C5
U 1 1 5F26C81A
P 5850 2600
F 0 "C5" H 5800 2700 50  0000 C CNN
F 1 "47uF" H 5750 2500 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5888 2450 50  0001 C CNN
F 3 "~" H 5850 2600 50  0001 C CNN
F 4 " https://uk.farnell.com/tdk/c3216x5r1e476m160ac/cap-47-f-25v-20-x5r-1206/dp/2522121" V 5850 2600 50  0001 C CNN "Farnell"
	1    5850 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C6
U 1 1 5F26CCD0
P 6050 2600
F 0 "C6" H 6000 2700 50  0000 C CNN
F 1 "47uF" H 5950 2500 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 6088 2450 50  0001 C CNN
F 3 "~" H 6050 2600 50  0001 C CNN
F 4 " https://uk.farnell.com/tdk/c3216x5r1e476m160ac/cap-47-f-25v-20-x5r-1206/dp/2522121" V 6050 2600 50  0001 C CNN "Farnell"
	1    6050 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C7
U 1 1 5F26D061
P 6250 2600
F 0 "C7" H 6200 2700 50  0000 C CNN
F 1 "47uF" H 6150 2500 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 6288 2450 50  0001 C CNN
F 3 "~" H 6250 2600 50  0001 C CNN
F 4 " https://uk.farnell.com/tdk/c3216x5r1e476m160ac/cap-47-f-25v-20-x5r-1206/dp/2522121" V 6250 2600 50  0001 C CNN "Farnell"
	1    6250 2600
	-1   0    0    1   
$EndComp
Wire Wire Line
	6250 2750 6050 2750
Connection ~ 5850 2750
Connection ~ 6050 2750
Wire Wire Line
	5600 2450 5850 2450
Connection ~ 5850 2450
Wire Wire Line
	5850 2450 5900 2450
Connection ~ 6050 2450
Wire Wire Line
	6050 2450 6250 2450
Wire Wire Line
	5850 2750 6050 2750
Text HLabel 4250 4900 0    50   Input ~ 0
I_Sense
Wire Wire Line
	4250 4900 4850 4900
Connection ~ 4850 4900
Text HLabel 4250 3700 0    50   Input ~ 0
~Sleep
Wire Wire Line
	5300 3700 4250 3700
Text HLabel 7000 3400 2    50   Input ~ 0
~Fault
Text HLabel 4250 3900 0    50   Input ~ 0
MotPWM
Wire Wire Line
	4250 3900 5300 3900
Wire Wire Line
	4250 4100 5300 4100
Text HLabel 4250 4100 0    50   Input ~ 0
Direction
Wire Wire Line
	5600 2750 5850 2750
$Comp
L power:GNDPWR #PWR0112
U 1 1 5F29F5BC
P 5600 2800
F 0 "#PWR0112" H 5600 2600 50  0001 C CNN
F 1 "GNDPWR" H 5604 2646 50  0000 C CNN
F 2 "" H 5600 2750 50  0001 C CNN
F 3 "" H 5600 2750 50  0001 C CNN
	1    5600 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2800 5600 2750
Connection ~ 5600 2750
Wire Wire Line
	6900 3900 6900 3800
Wire Wire Line
	6900 3500 6900 3400
Wire Wire Line
	6900 3400 7000 3400
Wire Wire Line
	6800 3400 6900 3400
Connection ~ 6900 3400
Wire Wire Line
	5200 3100 5250 3100
Wire Wire Line
	5250 3100 5250 2450
Wire Wire Line
	5250 2450 5600 2450
Connection ~ 5250 3100
Wire Wire Line
	5250 3100 5300 3100
Connection ~ 5600 2450
$Comp
L power:VCC #PWR0122
U 1 1 5F301792
P 5900 2450
F 0 "#PWR0122" H 5900 2300 50  0001 C CNN
F 1 "VCC" H 5915 2623 50  0000 C CNN
F 2 "" H 5900 2450 50  0001 C CNN
F 3 "" H 5900 2450 50  0001 C CNN
	1    5900 2450
	1    0    0    -1  
$EndComp
Connection ~ 5900 2450
Wire Wire Line
	5900 2450 6050 2450
$Comp
L Connector_Generic:Conn_01x01 M0
U 1 1 5F54EA88
P 7100 3050
F 0 "M0" H 7180 3092 50  0000 L CNN
F 1 "M+" H 7180 3001 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_2.0x2.0mm" H 7100 3050 50  0001 C CNN
F 3 "~" H 7100 3050 50  0001 C CNN
	1    7100 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 3050 6900 3100
Wire Wire Line
	6900 3100 6800 3100
$Comp
L Connector_Generic:Conn_01x01 M1
U 1 1 5F550BA6
P 7100 3250
F 0 "M1" H 7180 3292 50  0000 L CNN
F 1 "M-" H 7180 3201 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_2.0x2.0mm" H 7100 3250 50  0001 C CNN
F 3 "~" H 7100 3250 50  0001 C CNN
	1    7100 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 3250 6900 3200
Wire Wire Line
	6900 3200 6800 3200
Text Label 6800 4900 0    50   ~ 0
HeatPad
Wire Wire Line
	6800 4900 7200 4900
$Comp
L Connector:TestPoint HS1
U 1 1 5F5E89A5
P 7200 4900
F 0 "HS1" V 7154 5088 50  0000 L CNN
F 1 "HeatSink" V 7245 5088 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_2.0x2.0mm" H 7400 4900 50  0001 C CNN
F 3 "~" H 7400 4900 50  0001 C CNN
	1    7200 4900
	0    1    1    0   
$EndComp
$EndSCHEMATC
