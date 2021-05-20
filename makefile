
#Define the variables
CC := g++ #Defines the compiler
SRCDIR := src #source directory [Contains your .h and .cpp files]
BUILDDIR := build #object files and other generated files will be put in the build folder
TARGET := bin/run #run will the name of the of the executable that make will produce and will be stored in bin

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) -o $(TARGET)



#$(TARGET): main.o program.o runner.o
#	$(CC) -o run main.o program.o runner.o
#comment out below line if you dont want to remove object files
#	$(RM) *.o

#main.o: main.cpp program.h runner.h
#	$(CC) -c main.cpp

#program.o: program.h

#runner.o: runner.h program.h

#clean:
#	$(RM) *.o
