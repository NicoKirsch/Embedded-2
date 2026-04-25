CXX = arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

CPU = -mcpu=cortex-m4 -mthumb -mfloat-abi=soft
CXXFLAGS = $(CPU) -I./include -Wall -Wextra -std=c++11 -g -O2 -fno-exceptions -fno-rtti
LDFLAGS = $(CPU) -nostdlib

SOURCES = src/main.cpp src/heartbeat.cpp src/mock_hal.cpp
OBJS = $(SOURCES:.cpp=.o)
ELF = heartbeat_sensor
HEX = heartbeat_sensor.hex
BIN = heartbeat_sensor.bin

all: $(ELF) $(HEX) $(BIN) size

$(ELF): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

size: $(ELF)
	@$(SIZE) $<

clean:
	rm -f $(OBJS) $(ELF) $(HEX) $(BIN)

.PHONY: all clean size
