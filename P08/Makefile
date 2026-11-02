CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = dfa2grammar

OBJS = dfa2grammar.o alphabet.o string.o state.o automaton.o production.o grammar.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

dfa2grammar.o: dfa2grammar.cc alphabet.h string.h state.h automaton.h production.h grammar.h
	$(CXX) $(CXXFLAGS) -c dfa2grammar.cc

alphabet.o: alphabet.cc alphabet.h
	$(CXX) $(CXXFLAGS) -c alphabet.cc

string.o: string.cc string.h
	$(CXX) $(CXXFLAGS) -c string.cc

state.o: state.cc state.h
	$(CXX) $(CXXFLAGS) -c state.cc

automaton.o: automaton.cc automaton.h
	$(CXX) $(CXXFLAGS) -c automaton.cc

production.o: production.cc production.h
	$(CXX) $(CXXFLAGS) -c production.cc

grammar.o: grammar.cc grammar.h
	$(CXX) $(CXXFLAGS) -c grammar.cc

clean:
	rm -f $(OBJS) $(TARGET)