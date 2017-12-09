GNUTOOLS = D:\Program\ Files\ \(x86\)\GNU\ Tools\ ARM\ Embedded\6\ 2017-q2-update
CC = $(GNUTOOLS)/bin/arm-none-eabi-gcc
OBJCOPY = $(GNUTOOLS)/bin/arm-none-eabi-objcopy

SRC = blinky.c
OBJ = $(SRC:.c=.o)
LIB = -lc -lnosys

# TODO CFLAGS = -mcpu=cortex-m4 etc?

all: blinky.bin

# Binary file
blinky.bin: blinky.out
	$(OBJCOPY) -O binary blinky.out blinky.bin

# Linking
blinky.out: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LIB) -o blinky.out

.c.o:
	$(CC) -c -o $@ $<

clean:
	rm -rf *.o *.out *.bin
