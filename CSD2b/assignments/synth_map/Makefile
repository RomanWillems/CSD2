CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=-ljack
SOURCE= sine.o writeToFile.o jack_module.o main.o

sine: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f sine *.o
