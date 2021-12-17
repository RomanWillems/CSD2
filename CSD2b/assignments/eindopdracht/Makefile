CXX= g++
CXXFLAGS= -I/usr/local/include -Wall -std=c++14
LDFLAGS= -ljack
SOURCE=writeToFile.o jack_module.o oscillator.o sine.o saw.o square.o synth.o FM_synth.o Ring_synth.o main.o
TARGET=synth

$(TARGET): $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS) 
clean:
	rm -f $(TARGET) *.o
