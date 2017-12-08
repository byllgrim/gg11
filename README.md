# gg11
Experimenting with a giant gecko

This text documents, very casually, my play-sessions with a [gg11](https://www.silabs.com/products/development-tools/mcu/32-bit/efm32-giant-gecko-gg11-starter-kit).



# Initial Encounter
Technically not my first encounter with a gg11, but I remember little of it and
'm choosing a different angle this time.

## Connecting the USB
I suspect highest compatibily on a Windows(tm) computer, so that's where I am.

Upon connecting the usb, the gg11's display lights up with the previously
flashed program.
Is shows some static, b/w graphics.

Windows(tm) recognized the gecko as a storage device, thanks to the hospitable
proactiveness of the gecko's makers.

### Exploring the Storage Device
There's a README:
"Copying a binary file here will flash it to the MCU".
It details accepted binary formats, COM port, etc.

There's also some links to i.a. Simplicity Studio 4(tm), which I wish to avoid
since I dislike non-free software and big, corporate megablock monoliths.

### Testing the COM Port
With Windows' Device Manager, I find the COM port number.
And using the README's port speed, PuTTY let's me connect to the device.

Hitting the physical reset button, the gg's output is printed on my computer.



# Hello World
I want to make a simple hello world or LED blinking program, to test if I can
manage to control this device in any way.

**But** I will not use the _recommended_ way of doing it.
I'll use gcc and documentation.
No "click here and let automagic do it".

Hang on...
The LEDs seem damaged.
I'll try Simplicity Studio to assert the LEDs' integrity.

## Installing Simplicity on Windows
Searching the web for gg11 grants me the Starter Kit webpage.
Here I, of course, find convenient link to a Windows installer.

Not so convenient, though, a login is required.

### Obtaining Access to Simplicity Studio
This should not even be a step.

I have a registered user.
"Forgot your password?" you bet.

"Username"?
I guess my usuall nick?
No, red text informs me that usernames are email addresses, ok.
Now, got my reset-your-password email.

### Continuing Installation
Navigating, again, to the windows installer download button.
200 MB?
I guess thats "fair" for whatever this software package contains.

I accept the agreement.
Let's login again.
I hope this big, corporate megablock monolith is a good one.
"Checking for installed packages" for a while.

"Connect your board".
Ok.
"Device Inspector is required".
Ok.
The device is recognized.
I have a certain span of access bestowed.
I get to download 1GB of options, or untick all the boxes.
Oh, most boxes are uncheckable, 1GB here I come.
I accept this licence also.

Some time later, all SDKs and everything is gotten.

### Testing a LED Blink Demo
I select the device (which thankfully is autodetected).

An overview of resources starts loading.
Among which, I find a blinky!

Wait a sec micriumos_shell?
I was part of writing that!
Cool.

At last, the blink demo works fine.
No damage to the LEDs.

## Doing it The Hard Way
TODO

Not sure if I'll bother after all.

