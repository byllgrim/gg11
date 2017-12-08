# gg11
Experimenting with a giant gecko

This text documents my play-sessions with a [gg11](https://www.silabs.com/products/development-tools/mcu/32-bit/efm32-giant-gecko-gg11-starter-kit).

# Initial encounter.
Technically not my first encounter with a gg11, but I remember little of it and
'm choosing a different angle this time.

## Connecting the USB
I suspect highest compatibily on a Windows(tm) computer, so that's where I am.

Upon connecting the usb, the gg11's display lights up with the previously
flashed program.
Is shows some static, b/w graphics.

Windows(tm) recognized the gecko as a storage device, thanks to the hospitable
proactiveness of the gecko's makers.

### Exploring the storage device
There's a README:
"Copying a binary file here will flash it to the MCU".
It details accepted binary formats, COM port, etc.

There's also some links to i.a. Simplicity Studio 4(tm), which I wish to avoid
since I dislike non-free software and big, corporate megablock monoliths.

### Testing the COM port
With Windows' Device Manager, I find the COM port number.
And using the README's port speed, PuTTY let's me connect to the device.

Hitting the physical reset button, the gg's output is printed on my computer.
