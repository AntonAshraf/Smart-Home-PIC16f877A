# Happy-Smart-Home-PIC16f877A

## Description
This is a project for a smart home system using PIC16f877A microcontroller. The system is designed to control home for ease of life and happiness. 

## Features
- RFID based door lock
- Fire alarm system
- Theft detection system with laser security with alarm
- Screen status display
- Indication of status with LEDs

## Components
- PIC16f877A microcontroller
- Arduino UNO
- RFID module
- Fire sensor
- Laser module
- LEDs
- LDR sensor
- Buzzer
- LCD display 16x2
- servo motor
- DC Fan motor
- 5v power supply
- Resistors
- Capacitors
- Relay

## Tools
- MikroC for PIC
- Proteus
- Arduino IDE
- Pic Programmer k150

## Circuit Diagram
Main Circuit Diagram

![Circuit Diagram]()

More detailed circuit diagram can be found in the Proteus file.
## Working Scenario

### Scenario 1: RFID based door lock
- The system will be in the locked state initially.
- When the RFID card is scanned, the system will check the card number with the stored card number.
- If the card number matches, the system will unlock the door using servo, show the card number on the LCD display, buzzer accepted tone, and turn on the green LED.
- If the card number does not match, the system will show the card number on the LCD display, buzzer rejected tone, and turn on the red LED.

### Scenario 2: Fire alarm system
- The system will continuously check the fire sensor.
- If the fire sensor detects fire, the system will show the fire detected message on the LCD display, turn on the blue LED, turn on the fan using relay, and buzzer fire alarm tone.

### Scenario 3: Theft detection system with laser security with alarm
- The system will continuously check the LDR sensor.
- If the LDR sensor detects any interruption in the laser beam, the system will show the theft detected message on the LCD display"Theft detected, Call 911", turn on all LEDs blinking, and buzzer theft alarm tone.

## Pin Configuration with PIC16f877A

#### LCD Display
- RS -> B4
- EN -> B5
- D4 -> B0
- D5 -> B1
- D6 -> B2
- D7 -> B3
- VSS -> GND
- VDD -> 5v
- V0 -> Potentiometer 10k
- A -> 5v
- K -> GND

#### Servo Motor
- VCC -> 5v
- GND -> GND
- Signal -> B2

#### LEDs
- Blue -> D5
- Red -> D6
- Green -> D7

#### Buzzer
- Buzzer -> D4

#### LDR Sensor
- Signal -> A0

#### Fire Sensor
- VCC -> 5v
- GND -> GND
- DO -> B6

#### Fan with Relay
- Fan -> Relay NO
- Relay COM -> 5v
- signal -> D3

#### Laser Module
- VCC -> 5v
- GND -> GND
- Signal -> 5v

### RFID Module
Connect the RFID module with the Arduino UNO as follows:
- VCC -> 5v
- GND -> GND
- RST -> D9
- SDA -> D10
- MOSI -> D11
- MISO -> D12
- SCK -> D13
- IRQ -> Not Connected
- RST -> Not Connected

## How to run
clone the repository and open the project in MikroC for PIC. Compile the project and load the hex file into the PIC16f877A microcontroller using the PIC programmer. Connect the components as per the circuit diagram. Run the project and enjoy the smart home system.

## Author
- [Mahmoud Hany Fathallah]()
- [Nouran Mostafa]()
- [Salma Ismail]()
- [Anton Ashraf]()

