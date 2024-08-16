
# exec name
TARGET = visualizer

# source files
SRCS = main.cpp visualizer.cpp ../Utils/utils.cpp ../bubleSort.cpp

# compiler
CXX = g++

# flags
CXXFLAGS = -I/path/to/SFML/include

# libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

# libraries path
LDFLAGS = -L/path/to/SFML/lib

# idk
all: $(TARGET) 

# 
$(TARGET): $(SRCS)
	$(CXX) -o $(TARGET) $(SRCS) $(CXXFLAGS) $(LDFLAGS) $(LIBS)
	./$(TARGET)

# clean
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
