bin_PROGRAMS = heartbeat_sensor
heartbeat_sensor_SOURCES = main.cpp heartbeat.cpp mock_hal.cpp
heartbeat_sensor_CPPFLAGS = -I$(top_srcdir)/include
heartbeat_sensor_CFLAGS = -I$(top_srcdir)/include
heartbeat_sensor_CXXFLAGS = -I$(top_srcdir)/include

# STM32L432 Post-build: Create HEX and BIN files
install-exec-hook:
	@echo "Creating HEX and BIN files for STM32 programming..."
	arm-none-eabi-objcopy -O ihex heartbeat_sensor heartbeat_sensor.hex
	arm-none-eabi-objcopy -O binary heartbeat_sensor heartbeat_sensor.bin
	arm-none-eabi-size heartbeat_sensor
	@echo "Done! Files: heartbeat_sensor.hex and heartbeat_sensor.bin"