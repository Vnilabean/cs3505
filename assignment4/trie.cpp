

/**
 * Trie class impleemntation
 * @author Philippe Gonzalez
 */

#include "trie.h"

trie::trie() {
    root = new Node();
}

trie::trie(const trie& rhs) {
    root = new Node();
    *root = *rhs.root;
}

trie::~trie() {
    delete root;
}

int trie::operator= (const trie& rhs) {
    if (this == &rhs) {
        return 0;
    }
    delete root;
    root = new Node();
    *root = *rhs.root;
    return 0;
}

void trie::addWord(const std::string& word) {
    // set the current node to the root
    Node* currentNode = root;

    // loop through the word and try to add each character to the trie
    for (int i = 0; i < word.length(); i++) {
        char currentChar = word[i];
        // if the character is not in the trie, add a new node
        if (currentNode->children[currentChar - 'a'] == NULL) {
            currentNode->children[currentChar - 'a'] = new Node();
        }
        // move to the next node
        currentNode = currentNode->children[currentChar - 'a'];
    }   
}

bool trie::isWord(const std::string& word) {
    // set the current node to the root
    Node* currentNode = root;

    // check if the sting is empty
    if (word.length() == 0) {
        return false;
    }

    // loop through the word and try to find each character in the trie
    for (int i = 0; i < word.length(); i++) {
        char currentChar = word[i];

        // check if the char is valid
        if (currentChar < 'a' || currentChar > 'z') {
            return false;
        }

        // if the character is not in the trie, return false
        if (currentNode->children[currentChar - 'a'] == NULL) {
            return false;
        }
        // move to the next node
        currentNode = currentNode->children[currentChar - 'a'];
    }
}

std::vector<std::string> trie::allWordsStartingWithPrefix(std::string prefix) {
    std::vector<std::string> words;
    Node* currentNode = root;
    // get the the node of the last char then add every recursive char
    // in the node to the prefix and add that to the words vector
    for (int i = 0; i < prefix.length(); i++) {
        char currentChar = prefix[i];
        // check if the char is valid
        if (currentChar < 'a' || currentChar > 'z') {
            return words;
        }
        if (currentNode->children[currentChar - 'a'] == NULL) {
            // check all non null values in this currentnode children and add them to the prefix and add to words
            for (int j = 0; j < 26; j++) {
                if (currentNode->children[j] != NULL) {
                    std::string newPrefix = prefix + (char)('a' + j);
                    std::vector<std::string> newWords = allWordsStartingWithPrefix(newPrefix);
                    words.insert(words.end(), newWords.begin(), newWords.end());
                }
            }
        }
        currentNode = currentNode->children[currentChar - 'a'];
    }
    
}
