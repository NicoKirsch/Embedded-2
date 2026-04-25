CXX = g++
CXXFLAGS = -I./include -Wall -Wextra -std=c++11

SOURCES = src/main.cpp src/heartbeat.cpp src/mock_hal.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = heartbeat_sensor

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
