Arduino examples for avr-gcc with added Flake
=============================================

This project is a very basic demonstration of how to compile and flash an
Arduino Uno program utilising the `avr-*` tooling in the context
of a Nix flake.

![](demo.gif)

## tl;dr

0. Configure nix (this is an exercise left to the reader)
   1. Install with the nix-installer
   2. Configure nix-direnv
1. `direnv allow` in project repository
2. Plug in an Arduino & find its port
3. Change `ARDUINO_PORT` in `.env` file (e.g. `ARDUINO_PORT=/dev/ttyACM0`)
4. `make program`


## References

[Programming Arduino Uno in pure C](https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/)

[My Nix Journey - Use Nix on Ubuntu](https://tech.aufomm.com/my-nix-journey-use-nix-with-ubuntu/)

[shepmaster/rust-arduino-blink-led-no-core](https://github.com/shepmaster/rust-arduino-blink-led-no-core/tree/master)


