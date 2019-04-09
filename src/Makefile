# source file
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

# target you can change test to what you want
TARGET  := main

#compile and lib parameter
LIBS    := -lm

LDFLAGS := -L. -L/usr/local/lib/

DEFINES := -fpic -Wl,-rpath=.
INCLUDE := -I. -I/usr/local/include/
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)

CXXFLAGS:= $(CFLAGS)

$(TARGET) : $(OBJS)
	    $(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
.PHONY : install everything objs clean veryclean rebuild install

everything : $(TARGET)

all : $(TARGET)

objs : $(OBJS)

rebuild: veryclean everything

clean :
	rm -rf *.o
	rm $(TARGET)

veryclean : clean
	rm -rf $(TARGET)

