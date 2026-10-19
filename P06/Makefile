CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = p06_DFA_simulator

OBJS = p06_DFA_simulator.o alphabet.o string.o state.o automaton.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

p06_DFA_simulator.o: p06_DFA_simulator.cc alphabet.h string.h state.h automaton.h
	$(CXX) $(CXXFLAGS) -c p06_DFA_simulator.cc

alphabet.o: alphabet.cc alphabet.h
	$(CXX) $(CXXFLAGS) -c alphabet.cc

string.o: string.cc string.h
	$(CXX) $(CXXFLAGS) -c string.cc

state.o: state.cc state.h
	$(CXX) $(CXXFLAGS) -c state.cc

automaton.o: automaton.cc automaton.h
	$(CXX) $(CXXFLAGS) -c automaton.cc

clean:
	rm -f $(OBJS) $(TARGET)