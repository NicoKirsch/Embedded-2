bin_PROGRAMS = heartbeat_sensor

heartbeat_sensor_SOURCES = main.cpp heartbeat.cpp mock_hal.cpp

heartbeat_sensor_CXXFLAGS = $(CPU_FLAGS) -I$(top_srcdir)/include -Wall -Wextra -std=c++11 -g -O2 -fno-exceptions -fno-rtti
heartbeat_sensor_LDFLAGS = $(CPU_FLAGS) -nostdlib

all-local: heartbeat_sensor.hex heartbeat_sensor.bin
	@$(SIZE) heartbeat_sensor$(EXEEXT)

heartbeat_sensor.hex: heartbeat_sensor$(EXEEXT)
	$(OBJCOPY) -O ihex $< $@

heartbeat_sensor.bin: heartbeat_sensor$(EXEEXT)
	$(OBJCOPY) -O binary $< $@

clean-local:
	rm -f *.hex *.bin