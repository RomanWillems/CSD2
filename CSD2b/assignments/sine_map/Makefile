CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE= sine.o writeToFile.o main.o

sine: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f sine *.o
