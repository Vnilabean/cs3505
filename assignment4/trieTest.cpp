#include <iostream>
#include <fstream>
#include <vector>
#include "trie.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " <words_file> <queries_file>" << endl;
        return 1;
    }

    ifstream TrieFile(argv[1]);
    ifstream queryFile(argv[2]);
    string line;

    if (!TrieFile.is_open())
    {
        cout << "Unable to open the words file" << endl;
        return 1;
    }

    if (!queryFile.is_open())
    {
        cout << "Unable to open the queries file" << endl;
        return 1;
    }

    // Create a Trie object
    Trie testTrie;

    // Read the words file
    while (getline(TrieFile, line))
    {
        for (char c : line)
        {
            if (c < 'a' || c > 'z')
            {
                cout << "Invalid character " + string(1, c) + " in the words file, should only be a-z and lowercase" << endl;
                return 1;
            }
        }
        testTrie.addWord(line);
    }

    // Read the queries file
    vector<string> queries;
    while (getline(queryFile, line))
    {
        vector<string> words = testTrie.allWordsStartingWithPrefix(line);
        cout << "Checking " + line + ":" << endl;
        if (words.size() == 0)
        {
            cout << "No words found" << endl
                 << endl;
            continue;
        }
        cout << "Word found" << endl;
        for (string word : words)
        {
            cout << word + " ";
        }
        cout << endl
             << endl;
    }

    TrieFile.close();
    queryFile.close();

    // ==========================================================================
    // rule of three tests

    Trie smallTrie;

    // Add words to the original Trie
    smallTrie.addWord("apple");
    smallTrie.addWord("apples");
    smallTrie.addWord("app");
    smallTrie.addWord("applesauce");

    // Copy the original Trie
    Trie copiedTrie = smallTrie;

    // add new item to origninal and check copy
    smallTrie.addWord("test");
    // Check if the word appears in the copied Trie
    vector<string> copiedWords = copiedTrie.allWordsStartingWithPrefix("test");
    if (copiedWords.size() == 0)
    {
        cout << "Word was not found in copied Trie" << endl;
    }
    else
    {
        cout << "Word found in copied Trie" << endl;
    }

    // assign the original Trie to a new Trie
    Trie assignedTrie;
    assignedTrie = smallTrie;

    // add a word to the original Trie
    smallTrie.addWord("banana");

    // check if the word appears in the assigned Trie
    vector<string> assignedWords = assignedTrie.allWordsStartingWithPrefix("banana");
    if (assignedWords.size() == 0)
    {
        cout << "Word was not found in the assigned Trie" << endl;
    }
    else
    {
        cout << "Word found in the assigned Trie" << endl;
    }

    return 0;
}