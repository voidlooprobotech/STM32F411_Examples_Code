
#include <Wire.h>

void setup() {
  Wire.begin(0x0C);                // join I2C bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write("Hello voidloop"); // respond with message of  14 bytes
  // as expected by master
}
