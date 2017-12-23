PROG = draw

C_SRC =  \
	$(SDKDIR)/hardware/kit/common/drivers/display.c \
	$(SDKDIR)/hardware/kit/common/drivers/displayls013b7dh06.c \
	$(SDKDIR)/hardware/kit/common/drivers/displaypalemlib.c \
	$(SDKDIR)/hardware/kit/common/drivers/udelay.c \
	$(SDKDIR)/platform/Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.c \
	$(SDKDIR)/platform/emlib/src/em_assert.c \
	$(SDKDIR)/platform/emlib/src/em_cmu.c \
	$(SDKDIR)/platform/emlib/src/em_core.c \
	$(SDKDIR)/platform/emlib/src/em_ebi.c \
	$(SDKDIR)/platform/emlib/src/em_emu.c \
	$(SDKDIR)/platform/emlib/src/em_gpio.c \
	$(SDKDIR)/platform/emlib/src/em_lcd.c \
	$(SDKDIR)/platform/emlib/src/em_prs.c \
	$(SDKDIR)/platform/emlib/src/em_rtcc.c \
	$(SDKDIR)/platform/emlib/src/em_system.c \
	$(SDKDIR)/platform/emlib/src/em_usart.c \
	$(SDKDIR)/platform/middleware/glib/dmd/display/dmd_display.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_bitmap.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_circle.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_font_normal_8x8.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_font_narrow_6x8.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_font_number_16x20.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_line.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_polygon.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_rectangle.c \
	$(SDKDIR)/platform/middleware/glib/glib/glib_string.c \
	./draw.c

S_SRC =  \
	$(SDKDIR)/platform/Device/SiliconLabs/EFM32GG11B/Source/GCC/startup_efm32gg11b.S

include ../gg11.prog.mk
