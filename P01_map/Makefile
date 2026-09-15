CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
OBJETOS = cya-P01-student.o student.o
TARGET = ejecutable

all: $(TARGET)

$(TARGET): $(OBJETOS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJETOS)

cya-P01-student.o: cya-P01-student.cc student.h
	$(CXX) $(CXXFLAGS) -c cya-P01-student.cc

student.o: student.cc student.h
	$(CXX) $(CXXFLAGS) -c student.cc

clean:
	rm -f *.o $(TARGET)