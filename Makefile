# Define the compiler
CXX = g++

# Compiler flags (-MMD automatically tracks your .h header files)
CXXFLAGS = -std=c++17 -Wall -g -MMD

# 1. YOUR EXACT EXECUTABLE NAME
TARGET = hls_main.exe 

# 2. YOUR EXACT C++ SOURCE FILES (separated by spaces)
SRCS = hls_main.cpp formulas_planets.cpp Heat,Light,Sound.cpp

# Automatically generate object and dependency files
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

# Default rule
all: $(TARGET)

# Link object files into the final .exe
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Auto-include header dependencies
-include $(DEPS)

# 3. WINDOWS POWERSHELL CLEAN RULE
clean:
	Remove-Item -Force $(TARGET), $(OBJS), $(DEPS)
