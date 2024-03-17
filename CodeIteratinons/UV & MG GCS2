#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize the radio module
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    // Read the data received from the CubeSat
    char payload[64] = "";
    radio.read(&payload, sizeof(payload));

    // Print received data
    Serial.print("Received data: ");
    Serial.println(payload);
  }

  // Delay to slow down the loop
  delay(10); // Adjust the delay time as needed
}
