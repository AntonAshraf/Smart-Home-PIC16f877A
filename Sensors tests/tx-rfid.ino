#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);

String rfidCard;
String lastRfidCard;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the RFID Reader...");
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
        // Serial.write("\r\n"); // Add a newline for better readability in UART
        
        // Optionally also print to Serial Monitor
        // Serial.println(rfidCard);
        
        // Update the last read card
        lastRfidCard = rfidCard;
      }
    }
    rfid.halt();
  }
}
