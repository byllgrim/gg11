DEVICE = EFM32GG11B820F2048GL192
GNUTOOLS = D:\Program\ Files\ \(x86\)\GNU\ Tools\ ARM\ Embedded\6\ 2017-q2-update
SDK = D:\SiliconLabs\SimplicityStudio\v4\developer\sdks\gecko_sdk_suite\v2.0

INC = \
	-I $(SDK)/hardware/kit/common/bsp \
	-I $(SDK)/hardware/kit/SLSTK3701A_EFM32GG11/config \
	-I $(SDK)/platform/CMSIS/Include \
	-I $(SDK)/platform/Device/SiliconLabs/EFM32GG11B/Include \
	-I $(SDK)/platform/emlib/inc

CC = $(GNUTOOLS)/bin/arm-none-eabi-gcc
OBJCOPY = $(GNUTOOLS)/bin/arm-none-eabi-objcopy
LIB = -lc -lnosys
CPPFLAGS = -D $(DEVICE)
CFLAGS = $(INC) $(CPPFLAGS)

SRC = blinky.c
OBJ = $(SRC:.c=.o)

# TODO CFLAGS = -mcpu=cortex-m4 etc?

all: blinky.bin

# Binary file
blinky.bin: blinky.out
	@echo OBJCOPY $@
	@$(OBJCOPY) -O binary blinky.out blinky.bin

# Linking
blinky.out: $(OBJ)
	@echo CC $@
	@$(CC) $(LDFLAGS) $(OBJ) $(LIB) -o blinky.out

.c.o:
	@echo CC $<
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o *.out *.bin
