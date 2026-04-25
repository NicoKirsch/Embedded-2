# STM32L432 Cross-Compilation Makefile
CXX = arm-none-eabi-g++
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# STM32L432 - Cortex-M4
CPU_FLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=soft

CXXFLAGS = $(CPU_FLAGS) -I./include -Wall -Wextra -std=c++11 -g -O2
LDFLAGS = $(CPU_FLAGS)

SOURCES = src/main.cpp src/heartbeat.cpp src/mock_hal.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = heartbeat_sensor
HEX = $(TARGET).hex
BIN = $(TARGET).bin

all: $(TARGET) $(HEX) $(BIN) size

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(HEX): $(TARGET)
	$(OBJCOPY) -O ihex $< $@

$(BIN): $(TARGET)
	$(OBJCOPY) -O binary $< $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

size: $(TARGET)
	@$(SIZE) $<

clean:
	rm -f $(OBJECTS) $(TARGET) $(HEX) $(BIN)

.PHONY: all clean size
