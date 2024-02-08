
test:
	./trieTest 

trieTest: trieTest.o trie.o
	g++ -o trieTest trieTest.o trie.o -Wall -fsanitize=address,undefined

trieTest.o: trieTest.cpp trie.h
	g++ -c trieTest.cpp -Wall

trie.o: trie.cpp trie.h
	g++ -c trie.cpp -Wall

clean:
	rm -f trieTest *.o *~