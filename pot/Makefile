PROG = pot

C_SRC =  \
	$(SDKDIR)/hardware/kit/common/drivers/retargetio.c \
	$(SDKDIR)/hardware/kit/common/drivers/retargetserial.c \
	$(SDKDIR)/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.c \
	$(SDKDIR)/platform/emlib/src/em_adc.c \
	$(SDKDIR)/platform/emlib/src/em_assert.c \
	$(SDKDIR)/platform/emlib/src/em_cmu.c \
	$(SDKDIR)/platform/emlib/src/em_core.c \
	$(SDKDIR)/platform/emlib/src/em_gpio.c \
	$(SDKDIR)/platform/emlib/src/em_usart.c \
	./pot.c

S_SRC =  \
	$(SDKDIR)/platform/Device/SiliconLabs/EFM32GG11B/Source/GCC/startup_efm32gg11b.S

BUILDOPTS = -DRETARGET_VCOM

include ../gg11.prog.mk
