# this makefile takes inspiration from silabs makefiles
.POSIX:
.PHONY: all clean
DEVICE = EFM32GG11B820F2048GL192

PROGRAMFILES = D:/Program\ Files\ \(x86\)/
BINDIR = $(PROGRAMFILES)/GNU\ Tools\ ARM\ Embedded/6\ 2017-q2-update/bin/
BINDIR = #empty for linux
SDKDIR = D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.0
SDKDIR = /mnt/D/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.0

BUILDFLAGS = -DDEBUG #-DNDEBUG for release
CC = $(BINDIR)arm-none-eabi-gcc
LD = $(BINDIR)arm-none-eabi-ld
AR = $(BINDIR)arm-none-eabi-ar
OBJCOPY = $(BINDIR)arm-none-eabi-objcopy

DEPFLAGS = -MMD -MP -MF $(@:.o=.d)

CFLAGS = -D$(DEVICE) -Wall -Wextra -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp \
	-mfpu=fpv4-sp-d16 -ffunction-sections -fdata-sections -Os -g \
	-fomit-frame-pointer -std=c99 -DDEBUG_EFM $(DEPFLAGS) $(BUILDFLAGS) \
	$(BUILDOPTS)

ASMFLAGS = -x assembler-with-cpp -D$(DEVICE) -Wall -Wextra -mcpu=cortex-m4 \
	-mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -DDEBUG_EFM $(DEPFLAGS)

LDFLAGS = -Xlinker -Map=$(PROG).map -mcpu=cortex-m4 \
	-mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 \
	-T$(SDKDIR)/platform/Device/SiliconLabs/EFM32GG11B/Source/GCC/efm32gg11b.ld \
	--specs=nano.specs -Wl,--gc-sections 

LDLIBS = -lc -lgcc -lm -lnosys

INC = \
	-I. \
	-I$(SDKDIR)/platform/CMSIS/Include \
	-I$(SDKDIR)/platform/Device/SiliconLabs/EFM32GG11B/Include \
	-I$(SDKDIR)/platform/emlib/inc \
	-I$(SDKDIR)/platform/middleware/glib \
	-I$(SDKDIR)/platform/middleware/glib/dmd \
	-I$(SDKDIR)/platform/middleware/glib/glib \
	-I$(SDKDIR)/hardware/kit/common/bsp \
	-I$(SDKDIR)/hardware/kit/common/drivers \
	-I$(SDKDIR)/hardware/kit/SLSTK3701A_EFM32GG11/config
# TODO -I.$(PROG) ?

OBJ = $(C_SRC:.c=.o) $(S_SRC:.S=.o)

all: $(PROG).bin

.c.o:
	@echo CC `basename $<`
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

.S.o:
	@echo CC `basename $<`
	@$(CC) $(ASMFLAGS) $(INC) -c -o $@ $<

$(PROG).out: $(OBJ)
	@echo linking $@
	@$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PROG).out

$(PROG).bin: $(PROG).out
	@echo OBJCOPY $@
	@$(OBJCOPY) -O binary $(PROG).out $(PROG).bin

clean:
	@echo cleaning
	@rm -rf $(PROG).bin $(PROG).out $(OBJ) $(OBJ:.o=.d) *.map

#TODO include $(OBJ:.o=.d)
