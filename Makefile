CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17 
OBJECTS = main.o Row.o Cube2.o Side.o 
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp Row.h Cube2.h Side.h 
	$(CXX) $(CXXFLAGS) main.cpp 
Row.o: Row.cpp
	$(CXX) $(CXXFLAGS) Row.cpp
Cube2.o: Cube2.cpp
	$(CXX) $(CXXFLAGS) Cube2.cpp
Side.o: Side.cpp
	$(CXX) $(CXXFLAGS) Side.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
