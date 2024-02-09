/**
 * Trie class implimntation
 * @author Philippe Gonzalez
 */

#include "trie.h"

Trie::Trie()
{
    root = new Node();
}

Trie::Trie(const Trie &rhs)
{
    root = copyNode(rhs.root);
}

Trie::Node *Trie::copyNode(Trie::Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    // copy the node and all its children
    Trie::Node *newNode = new Trie::Node();
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i] != NULL)
        {
            // copy the children and isWord
            newNode->isWord = node->isWord;
            newNode->children[i] = copyNode(node->children[i]);
        }
    }
    return newNode;
}

Trie::~Trie()
{
    deleteNode(root);
}

void Trie::deleteNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    // recursively delete all the children of the node
    for (int i = 0; i < 26; i++)
    {
        deleteNode(node->children[i]);
    }
    delete node;
    // not sure if setting to null is necessary
    node = NULL;
}

Trie &Trie::operator=(const Trie &rhs)
{
    if (this != &rhs)
    {
        deleteNode(root);
        root = copyNode(rhs.root);
    }
    return *this;
}

void Trie::addWord(const std::string &word)
{
    // set the current node to the root
    Node *currentNode = root;
    // loop through the word and try to add each character to the Trie
    for (char c : word)
    {
        // if the character is not in the Trie, add a new node
        if (currentNode->children[c - 'a'] == NULL)
        {
            currentNode->children[c - 'a'] = new Node();
        }
        // move to the next node
        currentNode = currentNode->children[c - 'a'];
    }
    // set isword to true
    currentNode->isWord = true;
}

bool Trie::isWord(const std::string &word)
{
    // set the current node to the root
    Node *currentNode = root;
    // check if the sting is empty
    if (word.length() == 0)
    {
        return false;
    }
    // loop through the word and try to find each character in the Trie
    for (char c : word)
    {
        // check if the char is valid
        if (c < 'a' || c > 'z')
        {
            return false;
        }
        // if the character is not in the Trie, return false
        if (currentNode->children[c - 'a'] == NULL)
        {
            return false;
        }
        // move to the next node
        currentNode = currentNode->children[c - 'a'];
    }
    return currentNode->isWord;
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix)
{
    std::vector<std::string> words;
    Node *currentNode = root;
    // get the the node of the last char then add every recursive char
    // in the node to the prefix and add that to the words vector
    if (prefix.length() == 0)
    {
        return words;
    }

    // prefix validation
    for (char c : prefix)
    {
        if (c < 'a' || c > 'z')
        {
            return words;
        }
    }

    // set the current node to the end of the prefix then recurse
    for (char c : prefix)
    {
        if (currentNode->children[c - 'a'] == NULL)
        {
            return words;
        }
        currentNode = currentNode->children[c - 'a'];
    }

    // recurse through the Trie to find all the words with the prefix
    findAllPrefixes(currentNode, prefix, words);

    return words;
}

void Trie::findAllPrefixes(Node *node, std::string prefix, std::vector<std::string> &words)
{
    // if the node is null, return
    if (node == NULL)
    {
        return;
    }
    if (node->isWord)
    {
        words.push_back(prefix);
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (node->children[c - 'a'] != NULL)
        {
            findAllPrefixes(node->children[c - 'a'], prefix + c, words);
        }
    }
}
