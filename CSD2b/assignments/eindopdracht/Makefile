CXX= g++
CXXFLAGS= -I/usr/local/include -Wall -std=c++14
LDFLAGS= -ljack
SOURCE=sine.o saw.o square.o oscillator.o writeToFile.o jack_module.o main.o
TARGET=synth

$(TARGET): $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS) 
clean:
	rm -f $(TARGET) *.o
