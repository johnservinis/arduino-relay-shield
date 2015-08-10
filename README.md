# arduino-relay-shield
A simple library for controlling the Freetronics 8-Channel Relay Driver Shield http://tron.cc/r8

### Usage
To include in your project, clone this repo into `/Documents/Arduino/libraries/RelayShield`

`#include <Wire.h>` in your project
`#include "RelayShield.h"`

Instantiate the library with `RelayShield* relay = new RelayShield();`

To turn a relay 1 on, use `relay->on(1)`
To turn it off, use `relay->off(1)`

Refer to the example to see it in action.

**Relays can be used for switching high voltages. Be careful when tinkering. Never touch a live wire and be aware of residual charge from capacitors even after a circuit has been opened!**
