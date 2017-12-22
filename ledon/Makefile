PROG = ledon

C_SRC =  \
	$(SDKDIR)/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.c \
	$(SDKDIR)/hardware/kit/common/bsp/bsp_bcc.c \
	$(SDKDIR)/hardware/kit/common/bsp/bsp_stk.c \
	$(SDKDIR)/hardware/kit/common/bsp/bsp_stk_leds.c \
	$(SDKDIR)/hardware/kit/common/bsp/bsp_trace.c \
	$(SDKDIR)/platform/emlib/src/em_assert.c \
	$(SDKDIR)/platform/emlib/src/em_cmu.c \
	$(SDKDIR)/platform/emlib/src/em_ebi.c \
	$(SDKDIR)/platform/emlib/src/em_emu.c \
	$(SDKDIR)/platform/emlib/src/em_gpio.c \
	$(SDKDIR)/platform/emlib/src/em_system.c \
	$(SDKDIR)/platform/emlib/src/em_usart.c \
	./ledon.c

S_SRC =  \
	$(SDKDIR)/platform/Device/SiliconLabs/EFM32GG11B/Source/GCC/startup_efm32gg11b.S

include ../gg11.prog.mk
