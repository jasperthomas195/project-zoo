
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Executable name
TARGET = Sim

# Source files
SRCS = Enclosure.cpp Finances.cpp Living_Animal_Amphibian.cpp Living_Animal_Mammal.cpp Living_Animal_Avian.cpp Living_Animal.cpp Living_Zookeeper.cpp Living.cpp main.cpp Visitor.cpp Zoo.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HDRS = Enclosure.h Finances.h Living_Animal_Amphibian.h Living_Animal_Mammal.h Living_Animal_Avian.h Living_Zookeeper.h Living.h Visitor.h Zoo.h

# Default rule to build the target
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)