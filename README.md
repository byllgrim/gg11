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



# Starting Development
My plan is to make a computer mouse with the joysticks from an xbox controller
and some microswitches.

And looky here!
Simplicity Studio has example code for micriumos_usbhidmouse!

The demo works fine.
After connecting a micro usb, my mouse jitters all over the screen.

I just need to install that micriumos source that i ticked off earlier.
Apparently, I have "Access: 1 of 5".
Ominous.

The program still wont compile.
Lets try micriumos_blink.
That works.

But micriumos_usbhidmouse can't find "usbd_core.h".
Neither can windows explorer.
There are no more logically relevant SDKs to download.

## Where's the Missing USB drivers?
Comparing the Micrium API reference and my computers directories, I find that
I am missing at least the file system component, network and usb drivers.

Searching in simplicity directs me to the forum pages.
Seemingly, no one has had this problem before me.
Neither can I find a "post a question" button.

Micrium.org has no downloads for me.
Silabs.com refers to all the steps I have already taken.
Maybe I gain access after registering my product?
In times like these, I miss the free software communities.

### Registering My Product
I think I saw a "register" text somewhere in Simplicity.

Under settings?
Not as far as I can tell.
Under the SDK manager?
Nope.
At the launcher frontpage?
Cant see it.
Selecting the device?
No.

Maybe I remembered incorectly.



# Doing it the hard way after all
I yield!

Let me first check if there is emlib support for usb devices for gg11.
The API reference mentions em_usbd.c only for giant gecko, not for gg11.

I'll continue tomorrow...

## Building Blinky with GCC
I find my way, through oceans of directory levels, to gg11 blink example source
code.

There is an `armgcc` directory with a Makefile.

Of course it won't run because they've hardcoded the path to the gnu tools.
And they also assume that I have the 5.2 2015q4 version.
That's slightly funny because 4.9 is provided by Simplicity Studio.

At least, arm.com has binaries available (McAfee was tripped up by
developer.arm.com, though).
I've now got the "6 2017-q2-update".

## Back to The Spaghetti Makefile
    WINDOWSCS  ?= GNU Tools ARM Embedded\5.2 2015q4

No, I don't think so.

    TOOLDIR ?= $(PROGRAMFILES)/$(WINDOWSCS)

PROGRAMFILES assumes that I've installed gnu tools to drive C:/!
I have them on D:.
Let's try to force the correct directory...

    TOOLDIR ?= D:\Program Files (x86)\GNU Tools ARM Embedded\6 2017-q2-update

Woop woop!
Building file!
Creating binary!

## Flashing the chip
I hope I can trust that README from the gg11 storage device.
I'll upload the generated `blink.bin` file and see if the chip gets programmed.

*Suspense*

I load a glib example to unload the previously running blinky.
The storage device opened in windows.
And bippety bappety copy paste the .bin file.
The LCD display darkens, storage device disappears, reappears and...
A file named "FAIL" tells me "Error while connecting to CPU".

Trying the `blink.out` file.
Renaming it to `test.bin`.
Nothing.

## Flashing with Unecessarily Necessary Tools
I remember seeing a "tools" button in Simplicity.

Ah!
Simplicity Commander, perhaps?

There's a "Flash" button.
Selecting the binary.
Connecting to target.
Flash.
Finished.
And we have blinking action!

Sadly, I have to use this idiosyncratic tool, but it's simply enough and works.

