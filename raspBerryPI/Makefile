

TARGET = helloRasp switch_led device_gpio test interrupt hard_tone_buzzer i2c_rgb_led soft_tone_buzzer quest_i2c_rgb i2c_servo
LEGACY = -lwiringPi
all: ${TARGET}

${TARGET} : $@ ${LEGACY}


clean:
	rm ${TARGET}