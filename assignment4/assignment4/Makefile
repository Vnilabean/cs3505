CC = g++
CFLAGS = -Wall -fsanitize=address,undefined
TARGET = trieTest

test:
	./trieTest 

trieTest: trieTest.o trie.o
	$(CC) -o $(TARGET) trieTest.o trie.o $(CFLAGS)

trieTest.o: trieTest.cpp 
	$(CC) -c trieTest.cpp $(CFLAGS)

trie.o: trie.cpp 
	$(CC) -c trie.cpp $(CFLAGS)

clean:
	rm -f trieTest *.o *~