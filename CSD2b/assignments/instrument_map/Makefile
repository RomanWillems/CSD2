CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE=instrument.o instrument_main.o bongo.o flute.o
TARGET=instrument

$(TARGET): $(SOURCE)
    $(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
    $(CXX) -c $(CXXFLAGS) $<
clean:
    rm -f $(TARGET) *.o
