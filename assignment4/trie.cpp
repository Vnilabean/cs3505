

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

trie& trie::operator= (const trie& rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete root;
    root = new Node();
    *root = *rhs.root;
    return *this;
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
    // set isword to true
    currentNode->isWord = true;
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
    return currentNode->isWord;
}

std::vector<std::string> trie::allWordsStartingWithPrefix(std::string prefix) {
    std::vector<std::string> words;
    Node* currentNode = root;
    // get the the node of the last char then add every recursive char
    // in the node to the prefix and add that to the words vector

    // prefix validation
    for(char c : prefix) {
        if(c < 'a' || c > 'z') {
            return words;
        }
    }
    
    // recurse through the trie to find all the words with the prefix
    findAllPrefixes(currentNode, prefix, words);

    return words;
}

void trie::findAllPrefixes (Node* node, std::string prefix, std::vector<std::string>& words) {
    // if the node is null, return
    if (node == NULL) {
        return;
    }

    if(node->isWord) {
        words.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
    findAllPrefixes(node->children[i], prefix + (char)('a' + i), words);
    }

}
