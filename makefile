
#------------------------------------
#Define the variables
CXX := g++ #Defines the compiler
SRCDIR :=src#source directory [Contains your .h and .cpp files]
BUILDDIR :=build#object files and other generated files will be put in the build folder
TARGET := bin/run #run will the name of the of the executable that make will produce and will be stored in bin

SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(subst .cpp,.o,$(subst $(SRCDIR),$(BUILDDIR),$(SOURCES)))#$(subst %src, %build, $(SOURCES))
CXXFLAGS := -g

$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@

clean:
	rm build/*.o
	rm bin/run
