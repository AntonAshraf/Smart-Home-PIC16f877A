#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);

String rfidCard;
String lastRfidCard;
unsigned long lastReadTime = 0;  // Variable to store the time when the last card was read
const unsigned long resetTime = 2000;  // Time in milliseconds to reset the lastRfidCard (2000ms = 2s)

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}

void loop() {
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      rfidCard = String(rfid.serNum[0]) + String(rfid.serNum[1]) + String(rfid.serNum[2]) + String(rfid.serNum[3]);
      
      if (rfidCard != lastRfidCard) {  // Check if the current card is different from the last read card
        // Convert String to character array
        char rfidCardArray[rfidCard.length() + 1];
        rfidCard.toCharArray(rfidCardArray, rfidCard.length() + 1);
        
        // Send the character array via UART
        Serial.write(rfidCardArray);
        Serial.write('.');
        
        // Optionally also print to Serial Monitor
        // Serial.println(rfidCard);
        
        // Update the last read card
        lastRfidCard = rfidCard;
        
        // Update the time when the last card was read
        lastReadTime = millis();
      }
    }
    rfid.halt();
  }

  // Check if 2 seconds have passed since the last card was read
  if (millis() - lastReadTime > resetTime) {
    lastRfidCard = "";  // Reset the lastRfidCard to an empty value
  }
}
