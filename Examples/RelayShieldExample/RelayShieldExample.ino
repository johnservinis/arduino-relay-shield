/*
 * Freetronics 8 channel relay driver library
 * Author: John Servinis
 * 
 * A super simple library for controlling the relay driver channels of
 * the Freetronics relay driver board http://tron.cc/r8
 */

#include <Wire.h>
#include <RelayShield.h>

// Keep a global pointer to the relay controller
RelayShield* relay;

void setup() {

  // Instantiate a RelayShield instance
  relay = new RelayShield();

  // Blink each relay in sequence
  for (int i = 1; i <= 8; i++) 
  {
    relay->on(i);
    delay(100);
    relay->off(i);
  }

  delete relay;
}

void loop() {
  // Nothing
}
