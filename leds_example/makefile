#
# Copyright (c) 2021-2022 Arm Limited. All rights reserved.
#

# Uncomment to enable debugging with modeldebugger
#DEBUG=1

PLATFORM_NAME ?= VHT_MPS3_Corstone_SSE-300_Ethos-U55

include makefile.common

TARGET_APP=example-leds.axf
TARGET_DIS=example-leds.dis

DEFINES += -DTEST_VIO

all: $(TARGET_APP) $(TARGET_DIS)

clean:
	$(call RM,*.o)
	$(call RM,$(TARGET_DIS))
	$(call RM,$(TARGET_APP))

main.o: main.c
	$(CC) -c $(CFLAGS) $(DEFINES) $<

serial.o: serial.c
	$(CC) -c $(CFLAGS) $(DEFINES) $<

uart_stdout.o: uart_stdout.c
	$(CC) -c $(CFLAGS) $(DEFINES) $<

startup.o: startup.c
	$(CC) -c $(CFLAGS) $(DEFINES) $<

OBJ_FILES = main.o serial.o uart_stdout.o startup.o

$(TARGET_APP): $(OBJ_FILES) $(LINKFILE)
	$(LD) --scatter=$(LINKFILE) $(OBJ_FILES) $(LDFLAGS) -o $@

$(TARGET_DIS): $(TARGET_APP)
	$(FE) -c $(TARGET_APP) > $(TARGET_DIS)
