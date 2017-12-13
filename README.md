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



# MicriumOS USB Device Code
I know that the micrium usbhidmouse example could really help me.
The alternative is writing a lot of driver code myself.
That would be devastatingly time consuming.
I'll see if there's a student edition of the source code or something gratis.

    micrium.com

"Downloading µC/OS for Makers".
Life is tedious without a simple `git clone ...`.
Registrating and providing my life details.

"We will be in touch with you as soon as possible."
Great.
I'll read up on the USB standard in the
[meantime](https://youtu.be/mWwhdINdMs8).

# Getting Cut on Bare Metal
I'm on my last breath.
The autogenerated madness has taken it's toll on me.
If I must die today, let it rather be as a pulp mangled by the bare metal.

I wanna do blinky on my own.
A simple hand-written makefile.
Compiling and explicitly linking to all the runtime code.
I want full control.

    startup_efm32gg11b.S

Everything out, except for you; You may come in handy.

## Writing a Makefile
I'm following the provided blinky makefile closely.
But I'm trying to cut away anything that I cannot see a clear purpose for.

I've created a blinky.c with just a forever-lasting loop.
It now compiles to a .bin file.
Let's try and flash it.

Success?
It does flash, but it doesn't do anything, of course.

## Enabling LED
Let's get a spec sheet or reference up.
I'm looking for addresses relating to the LED status.
A web search for "gg11" takes me right to the starter kit documentation.
Nice.

First, what does the example blink.c do?
It calls `BSP_LedToggle()`.
The online api reference mentions `BSP_LedSet()`, let's find that.
Ah, it's actually on the web page!

    uint32_t tmp;
    tmp = BSP_RegisterRead(BSP_LED_PORT) & BSP_LED_MASK;
    tmp |= 1 << ledNo;
    BSP_RegisterWrite(BSP_LED_PORT, tmp);

`BSP_RegisterWrite()` refers further to `SpiRegisterRead()`.
I guess thats as far as I got on my own.
I could either copy or implement those features on my own, but I'd rather use
the provided bsp.
At least I still control my own makefile and such.

## Utilizing the Provided BSP
Ill call the `BSP_LedsInit()` and include files until the compiler stops
whining.

### BSP Include Files
I'm including `bsp.h`.
It complains about missing part number.
Allright, including everything that blink.c does.
Still no part number.
Checking the Makefile.
`DEVICE` is defined, but that didn't help either.
Of course, I must `-D$(DEVICE)`.

This makefile is growing big.
But maybe - maybe - its cause is inherent complixity of the problem domain.

### BSP Source Files
I'm adding source files as needed.
This turns out to be a bit cumbersome with windows file paths and trying to
conform to standard makefiles (no gnu extensions).
And the long paths of the sdk makes it hard to stay both reasonable and within
80 characters line width.
And I had to yield to the `-mcpu=cortex-m4` to enable `wfi`.

Finally, a `.bin` file!
I'm gonna flash it to the chip.

Oopsa! No blinky yet.

### Fixing the Executable
I'm looking for the missing piece to get my already compiling code to function
as intended.

I noticed that CHIP_Init uses a lot of ifdefs which i probably haven't defined.
The relevant ones aren't easy to find either.

In my quest for extreme minimalism, I have neglected `startup_efm32gg11b.S`
and `efm32gg11b.ld`.
I also neglected i.a. a linker flags `-mcpu=cortex-m4`.
Some of the options of the example makefile seems to be essential, while others
are superfluous.
--------........--------........--------........--------........--------........
