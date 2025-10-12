//*****************************************************************************************************
//
//		File:			    AVLDriver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #8
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    March 26, 2025
//
//
//		This file defines and implements an AVL Tree.
//
//
//*****************************************************************************************************

#include "AVLTree.h"
#include <iostream>
using namespace std;

//*****************************************************************************************************

int main()
{
    AVLTree <int> avlTree;
    int findVal;

    avlTree.insert(30);
    avlTree.insert(20);
    avlTree.insert(40);
    avlTree.insert(10);
    avlTree.insert(25);
    avlTree.insert(35);
    avlTree.insert(50);

    cout << "height is: " << avlTree.height() << endl;
    cout << "inorder traversal: ";
    avlTree.inorder();
    cout << "preorder traversal: ";
    avlTree.preOrder();
    cout << "postorder traversal: ";
    avlTree.postOrder();

    cout << "remove one by one in the original order:" << endl;
    avlTree.remove(10);
    avlTree.inorder();
    avlTree.remove(20);
    avlTree.inorder();
    avlTree.remove(30);
    avlTree.inorder();
    avlTree.remove(40);
    avlTree.inorder();
    avlTree.remove(50);
    avlTree.inorder();

    findVal = 30;
    if(avlTree.retrieve(findVal))
    {
        cout << "found " << findVal << endl;
    }
    else
    {
        cout << "try to find " << findVal << " not found" << endl;
    }

    return 0;
}

//*****************************************************************************************************

/*

height is: 3
inorder traversal: 10 20 25 30 35 40 50
preorder traversal: 30 20 10 25 40 35 50
postorder traversal: 10 25 20 35 50 40 30
remove one by one in the original order:
20 25 30 35 40 50
25 30 35 40 50
25 35 40 50
25 35 50
25 35
try to find 30 not found

 */