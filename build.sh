#!/bin/bash
make ergodox_ez:ymizushi-default
sudo teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_ymizushi-default.hex
