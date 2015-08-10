/*
 * Freetronics 8 channel relay driver library
 * Author: John Servinis
 *
 * A super simple library for controlling the relay driver channels of
 * the Freetronics relay driver board http://tron.cc/r8
 */

#include <Wire.h>
#include <Arduino.h>
#include "RelayShield.h"

#define I2C_ADDR  0x20  // 0x20 is the address with all jumpers removed

RelayShield::RelayShield()
{
  // Init relay controller
  Wire.begin(); // Wake up I2C bus

  // Set I/O bank A to outputs
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x00); // IODIRA register
  Wire.write(0x00); // Set all of bank A to outputs
  Wire.endTransmission();
}

void RelayShield::on(int relay)
{
  if (!(relay > 0 && relay <= 8)) return;
  bitWrite(_relayState, relay - 1, 1);
  _sendValueToLatch(_relayState);
}

void RelayShield::off(int relay)
{
  if (!(relay > 0 && relay <= 8)) return;
  bitWrite(_relayState, relay - 1, 0);
  _sendValueToLatch(_relayState);
}

void RelayShield::_sendValueToLatch(int latchValue)
{
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x12);        // Select GPIOA
  Wire.write(latchValue);  // Send value to bank A
  Wire.endTransmission();
}
