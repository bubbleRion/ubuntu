

TARGET = led_driver_native driver_exam_native switch_driver_native led_switch_native
LEGACY = -lwiringPi
all: ${TARGET}

${TARGET} : $@


clean:
	rm ${TARGET}

# interrupt

# CC = gcc
# obj-m := interrupt_check.o
# KDIR := /lib/modules/$(shell uname -r)/build
# PWD := $(shell pwd)
# default:
# 	$(MAKE) -C $(KDIR) M=$(PWD) modules

# clean:
# 	$(MAKE) -C $(KDIR) M=$(PWD) clean