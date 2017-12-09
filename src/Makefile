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
	@echo OBJCOPY $@
	@$(OBJCOPY) -O binary blinky.out blinky.bin

# Linking
blinky.out: $(OBJ)
	@echo CC $@
	@$(CC) $(LDFLAGS) $(OBJ) $(LIB) -o blinky.out

.c.o:
	@echo CC $<
	@$(CC) -c -o $@ $<

clean:
	rm -rf *.o *.out *.bin
