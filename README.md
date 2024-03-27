Arduino *Hello world, blink* with added Flake
=============================================

This project is a very basic demonstration of how to compile and flash an
Arduino Uno program utilising the `avr-\*` tooling in the context
of a Nix flake.

## tl;dr

 0. Configure nix (this is an exercise left to the reader)
     a. Install with the nix-installer
     b. Configure nix-direnv
 1. `direnv allow` in project repository
 2. Plug in an Arduino & find its port
 3. Change `ARDUINO_PORT` in `.env` file (e.g. `ARDUINO_PORT=/dev/ttyACM0`)
 4. `make program`


## References

[Programming Arduino Uno in pure C](https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/)

[My Nix Journey - Use Nix on Ubuntu](https://tech.aufomm.com/my-nix-journey-use-nix-with-ubuntu/)

https://github.com/shepmaster/rust-arduino-blink-led-no-core/tree/master


