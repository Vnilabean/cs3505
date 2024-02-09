#ifndef Trie_H
#define Trie_H

/**
 * @brief A Trie class that represents a Trie data structure
 * @author Philippe Gonzalez
 */

#include <iostream>
#include <vector>

class Trie
{
public:
    /**
     * @brief Default constructor
     */
    Trie();

    /**
     * @brief Copy constructor
     * @param rhs The Trie object to be copied into the new object
     */
    Trie(const Trie &rhs);

    /**
     * @brief Destructor
     */
    ~Trie();

    /**
     * @brief Overloaded assignment operator
     * @param rhs The Trie object to be copied
     */
    Trie &operator=(const Trie &rhs);

    /**
     * @brief The word passed into the method should be added to the Trie object.
     *  Duplicate adds should not change the Trie.
     *  You may assume that the word is only made up of lower-case characters from a-z.
     * @param word The string to be added to the Trie object
     */
    void addWord(const std::string &word);

    /**
     * @brief  Any character in the string not made up of characters 'a'-'z' cause an immediate return of false.
     *  If the word is found in the Trie, the method should return true, otherwise return false.
     *   A Trie should report that an empty string is not in the Trie.
     * @param word The word passed into the method should be added to the Trie object.
     */
    bool isWord(const std::string &word);

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
     * @brief Node struct to represent each node in the Trie
     */
    struct Node
    {
        bool isWord;
        Node *children[26];
    };
    // must represent the branching as an array of C-style pointers to nodes
    Node *children[26];

    /**
     * @brief recursive function to copy a node to satisfy the rule of three
     * @param node The node to be copied
     */
    Node *copyNode(Node *node);

    /**
     * @brief recursive function to find all the prefixes in the Trie
     * @param node The current node
     * @param prefix The prefix to search for
     * @param words The vector to store the words, passed by reference to avoid copying everytime
     */
    void findAllPrefixes(Node *node, std::string prefix, std::vector<std::string> &words);

    // root node of the Trie
    Node *root;

    /**
     * @brief recursive function to delete a node
     * @param node The node to be deleted
     */
    void deleteNode(Node *node);
};

#endif