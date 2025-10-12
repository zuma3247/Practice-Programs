//*****************************************************************************************************
//
//		File:			    driver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #6
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    February 26, 2025
//
//
//		This is a driver program for a Binary Tree.
//
//		Other files required:
//                       1.   BinaryTree.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "BinaryTree.h"

//*****************************************************************************************************

int main()
{
    BinaryTree <int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(13);
    tree.insert(17);

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder();
    cout << endl;

    cout << "Tree Height: " << tree.height() << endl;
    cout << "Total Nodes: " << tree.numNodes() << endl;
    cout << "Total Leaves: " << tree.numLeaves() << endl;

    return 0;
}

//*****************************************************************************************************

/*

Inorder Traversal: 3 5 7 10 13 15 17
Preorder Traversal: 10 5 3 7 15 13 17
Postorder Traversal: 3 7 5 13 17 15 10
Tree Height: 3
Total Nodes: 7
Total Leaves: 4

 */