//*****************************************************************************************************
//
//		File:			    Huffman.h
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #9
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    April 4, 2025
//
//
//		This file defines and implements a Huffman class.
//
//
//*****************************************************************************************************

#ifndef HUFFMAN_H
#define HUFFMAN_H

//*****************************************************************************************************

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//*****************************************************************************************************

struct Node
{
    char letter;
    int frequency;
    Node * left;
    Node * right;

    Node(char c, int f)
    {
        letter = c;
        frequency = f;
        left = nullptr;
        right = nullptr;
    }
};

//*****************************************************************************************************

class Huffman
{
private:
    string text;
    map <char, int> frequency;
    Node * root;
    map <char, string> huffman_codes;

    void calculateFrequencies();
    void buildTree();
    void generateCodes(Node * node, string str, map<char, string> & huffmanCodes);
    void deleteTree(Node * node);

public:
    Huffman(const string& txt);
    ~Huffman();
    string encode();
    string decode(const string& encodedText);
};

//*****************************************************************************************************

Huffman :: Huffman(const string& txt)
{
    text = txt;
    root = nullptr;
    calculateFrequencies();
    buildTree();
    generateCodes(root, "", huffman_codes);
}

//*****************************************************************************************************

Huffman :: ~Huffman()
{
    deleteTree(root);
}

//*****************************************************************************************************

string Huffman :: encode()
{
    string encodedString = "";
    for (char c : text)
    {
        encodedString += huffman_codes[c];
    }
    return encodedString;
}

//*****************************************************************************************************

string Huffman :: decode(const string& encodedText)
{
    Node * current = root;
    string decodedString = "";

    for (char c : encodedText)
    {
        if (c == '0')
        {
            current = current -> left;
        }
        else if (c == '1')
        {
            current = current -> right;
        }

        if (current -> left == nullptr && current -> right == nullptr)
        {
            decodedString += current -> letter;
            current = root;
        }
    }
    return decodedString;
}

//*****************************************************************************************************

void Huffman :: calculateFrequencies()
{
    for (char c : text)
    {
        frequency[c]++;
    }
}

//*****************************************************************************************************

void Huffman :: buildTree()
{
    multimap <int, Node *> nodes;

    for (auto const& pair : frequency)
    {
        nodes.insert({pair.second, new Node(pair.first, pair.second)});
    }

    while (nodes.size() > 1)
    {
        auto it = nodes.begin();
        Node * left = it -> second;
        nodes.erase(it);

        it = nodes.begin();
        Node * right = it -> second;
        nodes.erase(it);

        Node * parent = new Node('\0', left -> frequency + right -> frequency);
        parent -> left = left;
        parent -> right = right;

        nodes.insert({parent -> frequency, parent});
    }

    root = nodes.begin() -> second;
}

//*****************************************************************************************************

void Huffman :: generateCodes(Node * node, string str, map<char, string> & huffmanCodes)
{
    if (node != nullptr)
    {
        if (node -> letter != '\0')
        {
            huffmanCodes[node -> letter] = str;
        }
        generateCodes(node -> left, str + "0", huffmanCodes);
        generateCodes(node -> right, str + "1", huffmanCodes);
    }
}

//*****************************************************************************************************

void Huffman :: deleteTree(Node * node)
{
    if (node != nullptr)
    {
        deleteTree(node -> left);
        deleteTree(node -> right);
        delete node;
    }
}

//*****************************************************************************************************

#endif
