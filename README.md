# Gecko Quest
I'm playing with a
[gg11](https://www.silabs.com/products/development-tools/mcu/32-bit/efm32-giant-gecko-gg11-starter-kit).

The SDK can be downloaded via Simplicity Studio.

udev rules can be found from SEGGER JLink or Simplicity Studio.

[SEGGER JLink software](https://www.segger.com/downloads/jlink/)

[Simplicity Studio](https://www.silabs.com/products/development-tools/software/simplicity-studio)

## Flashing with J-Link on Linux
Linux binaries can be found from SEGGER's JLink.

    $ /usr/bin/JLinkExe
    J-Link> connect
    Device> EFM32GG11B820F2048
    TIF> SWD
    Speed> 12000
    J-Link> loadbin foobar.bin, 0

Press the physical reset button and marvel.

## Using VCOM on linux
The following reads printfs and such from VCOM on my linux computer.
I haven't tried writing yet.

    $cat /dev/ttyACM0
    EFM32 Giant Gecko 11 USART4 example
    Virtual COM port enabled.
