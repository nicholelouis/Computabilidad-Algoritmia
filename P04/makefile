CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = p04_html_analyzer

OBJS = p04_html_analyzer.o html.o tag.o comment.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

p04_html_analyzer.o: p04_html_analyzer.cc html.h tag.h comment.h
	$(CXX) $(CXXFLAGS) -c p04_html_analyzer.cc

html.o: html.cc html.h tag.h comment.h
	$(CXX) $(CXXFLAGS) -c html.cc

tag.o: tag.cc tag.h
	$(CXX) $(CXXFLAGS) -c tag.cc

comment.o: comment.cc comment.h
	$(CXX) $(CXXFLAGS) -c comment.cc

clean:
	rm -f $(OBJS) $(TARGET)