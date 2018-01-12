#include <Wire.h>

// MCP23017_I2CR16G5LE I2C Addr_relay is 0x20(32)
#define Addr_relay 0x20
void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);
  
  // Start I2C Transmission
 Wire.beginTransmission(Addr_relay);
  // Select IODIRA register
  Wire.write(0x00);
  // All pins of port-A are configured as output
  Wire.write(0x00);
//  // Stop I2C transmission
  Wire.endTransmission();
//  // Start I2C Transmission
  delay(300);

  Wire.beginTransmission(Addr_relay);
  Wire.write(0x01);  //Select IODIRB register
  Wire.write(0x00);  //all pins of port-B are configured as output
  Wire.endTransmission();
  delay(500);
}

void loop()
{
          Wire.beginTransmission(Addr_relay);
 // Select GPIOA register
          Wire.write(0x12);
  // All pins of port-A are set to logic HIGH
         Wire.write(0xff);
  // Stop I2C transmission
         Wire.endTransmission();
  // Output data to serial monitor
        Serial.println("Turning all Relays of Port-A ON");
        delay(500);
              Wire.beginTransmission(Addr_relay);
              Wire.write(0x13); // Select GPIOB register
              Wire.write(0xff);// All pins of port-B are set to logic HIGH
              Wire.endTransmission();
              Serial.println("Turning all Relays of Port-B ON");
              delay(500);
}
