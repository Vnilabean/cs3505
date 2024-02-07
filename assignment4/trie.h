#ifndef TRIE_H
#define TRIE_H

/**
 * @brief A trie class that represents a trie data structure
 * @author Philippe Gonzalez
*/

#include <iostream>
#include <vector>

class trie {
    public: 

        /**
         * @brief Default constructor
        */
        trie();

        /**
         * @brief Copy constructor
         * @param rhs The trie object to be copied into the new object
        */
        trie(const trie& rhs);

        /**
         * @brief Destructor
        */
        ~trie();

        /**
         * @brief Overloaded assignment operator
         * @param rhs The trie object to be copied
        */
        int operator= (const trie& rhs);

        /**
         * @brief The word passed into the method should be added to the Trie object. 
         *  Duplicate adds should not change the Trie.
         *  You may assume that the word is only made up of lower-case characters from a-z.
         * @param word The string to be added to the Trie object
        */
        void addWord(const std::string& word);

        /**
         * @brief  Any character in the string not made up of characters 'a'-'z' cause an immediate return of false.
         *  If the word is found in the Trie, the method should return true, otherwise return false.
         *   A Trie should report that an empty string is not in the Trie.
         * @param word The word passed into the method should be added to the Trie object.
        */
        bool isWord(const std::string& word);

        /**
         * @brief Characters in the prefix string should be tested to make sure they are only 'a'-'z'. 
         * If the prefix is a word, that should be included. 
         * An empty prefix should return all words in the Trie.
         * @param prefix String prefix to search for
         * @return returns a vector<std::string> that contains all the words in the Trie
         *  that begin with the passed in argument prefix string.
        */
        std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);

    private:
        /**
         * @brief Node struct to represent each node in the trie
        */
        struct Node {
            // must represent the branching as an array of C-style pointers to nodes
            Node* children[26];
        };
        
        Node* root;

};

#endif