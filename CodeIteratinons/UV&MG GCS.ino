#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize the radio module
  radio.begin();
  radio.openWritingPipe(address);

  // Set the pins connected to the sensors
  pinMode(21, INPUT); // SLC port
  pinMode(20, INPUT); // SDA port
  pinMode(A7, INPUT); // UV light sensor on Analog port 7
}

void loop() {
  // Read data from the sensors
  int magnetometerData1 = analogRead(A0); // Magnetometer data point 1
  int magnetometerData2 = analogRead(A1); // Magnetometer data point 2
  int magnetometerData3 = analogRead(A2); // Magnetometer data point 3
  int uvLightData = analogRead(A7); // UV light sensor data

  // Prepare the data to be sent
  String dataToSend = String(magnetometerData1) + "," + String(magnetometerData2) + "," + String(magnetometerData3) + "," + String(uvLightData);

  // Convert the data to a char array
  char payload[64];
  dataToSend.toCharArray(payload, 64);

  // Send the data over the RF24 module
  radio.write(&payload, sizeof(payload));

  // Print sent data
  Serial.print("Sent data: ");
  Serial.println(payload);

  // Delay before sending next data
  delay(1000);
}
