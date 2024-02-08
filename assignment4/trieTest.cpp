#include <iostream>
#include <fstream>
#include <vector>
#include "trie.h"
using namespace std;



int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <words_file> <queries_file>" << endl;
        return 1;
    }
    
    ifstream trieFile(argv[1]);
    ifstream queryFile(argv[2]);
    string line;

    if (!trieFile.is_open()) {
        cout << "Unable to open the words file" << endl;
        return 1;
    }

    if (!queryFile.is_open()) {
        cout << "Unable to open the queries file" << endl;
        return 1;
    }

    // Create a trie object
    trie testTrie;

    // Read the words file
    while (getline(trieFile, line)) {
        for(char c : line) {
            if(c < 'a' || c > 'z') {
                cout << "Invalid character " + string(1, c) + " in the words file, should only be a-z and lowercase" << endl;
                return 1;
            }
            testTrie.addWord(line);
        }
    }

    // Read the queries file
    vector<string> queries;
    while (getline(queryFile, line)) {
        vector<string> words = testTrie.allWordsStartingWithPrefix(line);
        cout << "Checking " + line + ":" << endl;
        if (words.size() == 0) {
            cout << "No words found" << endl;
        } 
        cout << "Word found" << endl;
        for (string word : words) {
            cout << word + " ";
        }
        cout << endl;
    }

    trieFile.close();
    queryFile.close();

    // ==========================================================================
    // rule of three tests

    // Create a new trie
    trie smallTrie;

    // Add a word to the original trie
    smallTrie.addWord("apple");
    smallTrie.addWord("apples");
    smallTrie.addWord("app");
    smallTrie.addWord("applesauce");

    // Copy the original trie
    trie copiedTrie = smallTrie;

    // Check if the word appears in the copied trie
    vector<string> copiedWords = copiedTrie.allWordsStartingWithPrefix("app");
    if (copiedWords.size() == 0) {
        cout << "Word not found in copied Trie" << endl;
    } else {
        cout << "Word found in copied Trie" << endl;
    }

    // Assign the original Trie to a new trie
    trie assignedTrie = copiedTrie;

    // Add a word to the original trie
    smallTrie.addWord("banana");

    // Check if the word appears in the assigned trie
    vector<string> assignedWords = assignedTrie.allWordsStartingWithPrefix("banana");
    if (assignedWords.size() == 0) {
        cout << "Word not found in assigned Trie" << endl;
    } else {
        cout << "Word found in assigned Trie" << endl;
    }
    

    return 0;
    }