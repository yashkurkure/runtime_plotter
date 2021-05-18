CC = g++

main: main.o program.o runner.o
	$(CC) -o run main.o program.o runner.o
#comment out below line if you dont want to remove object files
	$(RM) *.o

main.o: main.cpp program.h runner.h
	$(CC) -c main.cpp

program.o: program.h

runner.o: runner.h program.h

clean:
	$(RM) *.o
