
LIBPNG = ./libpng-1.6.40/
CC = g++
CFLAGS = -g -Wall
TARGET = fernPNG

fernPNG: transform.o point.o pngWriter.o fernPNG.o
	$(CC) -I$(LIBPNG) $(CFLAGS) -o $(TARGET) fernPNG.o transform.o point.o pngWriter.o -L$(LIBPNG) -lpng 

fernPNG.o: fernPNG.cpp
	$(CC) -I$(LIBPNG) $(CFLAGS) -c fernPNG.cpp

transform.o: transform.cpp

point.o: point.cpp
	$(CC) -I$(LIBPNG) $(CFLAGS) -c point.cpp

pngWriter.o: pngWriter.cpp
	$(CC) -I$(LIBPNG) $(CFLAGS) -c pngWriter.cpp

clean:
	$(RM) *.o $(TARGET) 


