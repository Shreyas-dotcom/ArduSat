// Tranismitter Side UV only 
// libs
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//consts
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

unsigned long previousTransmissionTime = 0;
const unsigned long transmissionInterval = 1 * 6 * 10; // 10 minutes in milliseconds
//setuploop
void setup() {
  Serial.begin(9600); // Initialize the serial monitor
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
//running loop
void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousTransmissionTime >= transmissionInterval) {
    // Read UV light sensor value
    int uvValue = analogRead(A7);

    // Convert sensor value to a string
    String uvString = String(uvValue);

    // Convert string to a character array
    char uvCharArray[uvString.length() + 1];
    uvString.toCharArray(uvCharArray, sizeof(uvCharArray));

    // Send UV sensor reading through the radio
    radio.write(&uvCharArray, sizeof(uvCharArray));

    // Print UV sensor reading to the serial monitor
    Serial.print("UV Sensor Reading: ");
    Serial.println(uvValue);

    previousTransmissionTime = currentMillis;
  }
}
