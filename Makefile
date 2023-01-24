#Makefile for building code for avr microcontrollers

#------------------------------------------------------------------------------
# ------------------------YOU CAN(and NEED) TO CHANGE IT-----------------------
#------------------------------------------------------------------------------
# Name of target MCU (please write a full name)
MCU 		= atmega328p
# Name of your project
TARGET 		= relay
# Directory with all header files
INC_DIR 	= .
# Compilers flags
CFLAGS 		= -Wall -Os
# Name of programmer for flashing
PROGRAMMER 	= arduino
# Speed of flashing
SPEED 		= 115200
# Port with connected target device
PORT 		= /dev/ttyUSB0


#------------------------------------------------------------------------------
# ----------------------------INTERNAL PARAMS----------------------------------
#------------------------------------------------------------------------------
MEMTYPE 	= flash
CC 		= avr
REMOVER 	= rm
FLASHER 	= avrdude
FORMATTER 	= clang-format
src_files 	= $(shell find . -name '*.c')
hdr_files 	= $(addprefix -I, $(shell dirname $(shell find . -name "*.h")))
obj_files 	= $(src_files:.c=.o)

.PHONY: clean format flash all

open:
	code -n .

#------------------------------------------------------------------------------
all: clean build flash

#------------------------------------------------------------------------------
%.o: %.c
	$(CC)-gcc $(CFLAGS) $(hdr_files) -mmcu=$(MCU) -c $< -o $@

#------------------------------------------------------------------------------
$(TARGET).elf: $(obj_files)
	$(CC)-gcc -mmcu=$(MCU) -o $@ $^

#------------------------------------------------------------------------------
build: $(TARGET).elf
	@echo "Build..."
	$(CC)-objcopy -j .text -j .data -O ihex $^ $(TARGET).hex

#------------------------------------------------------------------------------
clean:
	@echo "Clean..."
	$(REMOVER) -f $(obj_files) $(TARGET).elf $(TARGET).hex

#------------------------------------------------------------------------------
format:
	$(FORMATTER) -verbose -i $(src_files) -style=file

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
flash:
	@echo "Flash..."
	sudo $(FLASHER) -v -p $(MCU) -b $(SPEED) -c $(PROGRAMMER) -P $(PORT) -U $(MEMTYPE):w:$(TARGET).hex
