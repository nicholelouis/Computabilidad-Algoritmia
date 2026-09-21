CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = cya-P02-strings

OBJS = cya-P02-strings.o alphabet.o string.o language.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

cya-P02-strings.o: cya-P02-strings.cc alphabet.h string.h language.h
	$(CXX) $(CXXFLAGS) -c cya-P02-strings.cc

alphabet.o: alphabet.cc alphabet.h
	$(CXX) $(CXXFLAGS) -c alphabet.cc

string.o: string.cc string.h
	$(CXX) $(CXXFLAGS) -c string.cc

language.o: language.cc language.h alphabet.h string.h
	$(CXX) $(CXXFLAGS) -c language.cc

clean:
	rm -f $(OBJS) $(TARGET)