/*
 * Freetronics 8 channel relay driver library
 * Author: John Servinis
 *
 * A super simple library for controlling the relay driver channels of
 * the Freetronics relay driver board http://tron.cc/r8
 */

#ifndef RELAYSHIELD_H
#define RELAYSHIELD_H

#include <Arduino.h>

class RelayShield {
  public:

    // Constructor
    RelayShield();

    // Turn a relay on (1-8)
    void on(int relay);

    // Turn a relay off (1-8)
    void off(int relay);

  private:

    // The current relay states, stored in a byte
    char _relayState;

    // Sends the current state to the relay controller
    void _sendValueToLatch(int latchValue);
};

#endif
