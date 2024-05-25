# Happy-Smart-Home-PIC16f877A

## Description
This is a project for a smart home system using PIC16f877A microcontroller. The system is designed to control home for ease of life and happiness. 

![Project Image](https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/368ce15e-84a5-4550-b129-732cf5d7373e)


## Features
- RFID based door lock
- Fire alarm system
- Theft detection system with laser security with alarm
- Screen status display
- Indication of status with LEDs

## System Overview
|Level 1| Level 2| Top View|Back View|
|--------|---------|-----------|----|
|![Level 1](https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/a79618d0-93df-48ae-b04d-82cdfb650c8b)|![Level 2](https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/d84a73a3-c38e-4ad6-847a-d00772e220de)|![Top View](https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/ebd74ca5-9512-46f5-90af-cfc56e578aad)|![Back View](https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/d8c99dd7-2a5e-4006-ba89-c5edb532d2e0)|




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

![Circuit Diagram](https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/079085f0-52f1-47f0-a3ad-8f11228c28a2)


More detailed circuit diagram can be found in the Proteus file.

## Body Design
The body is designed in Autocad and cut using a laser cutting machine. The body is designed to hold all the components in place and provide a good look for the system. The material used is MDF 3mm thickness. [Here](https://github.com/AntonAshraf/Smart-Home-PIC16f877A/blob/main/Design%20Autocad.DWG) is the AutoCAD design for the body.

![Body Design](https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/d49c2954-5407-40ed-b56d-50e64c6b163e)



 
## Working Scenario
Let's dive into the working scenario of the system and see how it works in different situations.

### Scenario 1: RFID-based door lock
- The system will be in the locked state initially.
- When the RFID card is scanned, the system will check the card number with the stored card number.
- If the card number matches, the system will unlock the door using a servo, show the card number on the LCD display, buzzer accepted tone, and turn on the green LED.
- If the card number does not match, the system will show the card number on the LCD display, buzzer rejected tone, and turn on the red LED.

https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/62c33edd-5d8e-4c97-a59e-392416da48ae

--- 
### Scenario 2: Fire alarm system
- The system will continuously check the fire sensor.
- If the fire sensor detects a fire, the system will show the fire detected message on the LCD display, turn on the blue LED, turn on the fan using relay, and buzzer fire alarm tone.

https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/52715232-b21d-49a7-9b15-4a62e1261c12

https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/933f9f07-15ba-45f2-adfb-0668da3d1e70

---

### Scenario 3: Theft detection system with laser security with alarm
- The system will continuously check the LDR sensor.
- If the LDR sensor detects any interruption in the laser beam, the system will show the theft detected message on the LCD "Theft detected, Call 911", turn on all LEDs blinking, and buzzer theft alarm tone.



https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/d9564d32-4eec-461e-bdc3-c5bbbe391e33


https://github.com/AntonAshraf/Smart-Home-PIC16f877A/assets/51335125/51a08aa3-25fb-4069-948f-87ee2772900c

---

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
Connect the RFID module with the **Arduino UNO** as follows:
- VCC -> 5v
- GND -> GND
- RST -> D9
- SDA -> D10
- MOSI -> D11
- MISO -> D12
- SCK -> D13
- IRQ -> Not Connected
- RST -> Not Connected



## How to run the project
clone the repository and open the project in MikroC for PIC. Compile the project and load the hex file into the PIC16f877A microcontroller using the PIC programmer. Connect the components as per the circuit diagram. Run the project and enjoy the smart happy home system.

## Author
- [Mahmoud Hany Fathallah]()
- [Nouran Mostafa]()
- [Salma Ismail]()
- [Anton Ashraf]()

