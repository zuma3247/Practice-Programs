//*****************************************************************************************************
//
//		File:			    BinaryTree.h
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
//		This header file defines a Binary Tree class.
//
//
//*****************************************************************************************************

#include "Node.h"

//*****************************************************************************************************

template <typename T>
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insert(const T & item);
    int height() const;
    void inorder(ostream & os = cout) const;
    void preorder(ostream & os = cout) const;
    void postorder(ostream & os = cout) const;
    int numNodes() const;
    int numLeaves() const;
private:
    Node <T> * root;
    void deleteTree(Node <T> * & r);
    int height(Node <T> * r) const;
    void inorder(Node <T> * r, ostream & os) const;
    void preorder(Node <T> * r, ostream & os) const;
    void postorder(Node <T> * r, ostream & os) const;
    int numNodes(Node <T> * r) const;
    int numLeaves(Node <T> * r) const;
    void insertHelper(Node <T> * & root, const T & item);
};

//*****************************************************************************************************

template <typename T>
BinaryTree <T> :: BinaryTree()
{
    root = nullptr;
}

//*****************************************************************************************************

template <typename T>
BinaryTree <T> :: ~BinaryTree()
{
    deleteTree(root);
}

//*****************************************************************************************************

template <typename T>
void BinaryTree <T> :: insert(const T & item)
{
    insertHelper(root, item);
}

//*****************************************************************************************************

template <typename T>
int BinaryTree <T> :: height() const
{
    return height(root);
}

//*****************************************************************************************************

template <typename T>
void BinaryTree <T> :: inorder(ostream & os) const
{
    inorder(root, os);
}

//*****************************************************************************************************

template <typename T>
void BinaryTree <T> :: preorder(ostream & os) const
{
    preorder(root, os);
}

//*****************************************************************************************************

template <typename T>
void BinaryTree <T> :: postorder(ostream & os) const
{
    postorder(root, os);
}

//*****************************************************************************************************

template <typename T>
int BinaryTree <T> :: numNodes() const
{
    return numNodes(root);
}

//*****************************************************************************************************

template <typename T>
int BinaryTree <T> :: numLeaves() const
{
    return numLeaves(root);
}

//*****************************************************************************************************

template <typename T>
void BinaryTree <T> :: deleteTree(Node <T> * & r)
{
    if (r != nullptr)
    {
        deleteTree(r -> left);
        deleteTree(r -> right);
        delete r;
        r = nullptr;
    }
}

//*****************************************************************************************************

template <typename T>
int BinaryTree <T> :: height(Node <T> * r) const
{
    int leftHeight,
        rightHeight;

    if (r != nullptr)
    {
        leftHeight = height(r -> left);
        rightHeight = height(r -> right);
    }

    if (r == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + std::max(height(r -> left), height(r -> right));
    }
}

//*****************************************************************************************************

template <typename T>
void BinaryTree <T> :: inorder(Node <T> * r, ostream & os) const
{
    if (r != nullptr)
    {
        inorder(r -> left, os);
        os << r -> data << " ";
        inorder(r -> right, os);
    }
}

//*****************************************************************************************************

template <typename T>
void BinaryTree <T> :: preorder(Node <T> * r, ostream & os) const
{
    if (r != nullptr)
    {
        os << r -> data << " ";
        preorder(r -> left, os);
        preorder(r -> right, os);
    }
}

//*****************************************************************************************************

template <typename T>
void BinaryTree <T> :: postorder(Node <T> * r, ostream & os) const
{
    if (r != nullptr)
    {
        postorder(r -> left, os);
        postorder(r -> right, os);
        os << r -> data << " ";
    }
}

//*****************************************************************************************************

template <typename T>
int BinaryTree <T> :: numNodes(Node <T> * r) const
{
    if (r == nullptr)
    {
        return 0;
    }
    return 1 + numNodes(r -> left) + numNodes(r -> right);
}

//*****************************************************************************************************

template <typename T>
int BinaryTree <T> :: numLeaves(Node <T> * r) const
{
    if (r == nullptr)
    {
        return 0;
    }
    if (r -> left == nullptr && r -> right == nullptr)
    {
        return 1;
    }
    return numLeaves(r -> left) + numLeaves(r -> right);
}

//*****************************************************************************************************

template <typename T>
void BinaryTree<T> :: insertHelper(Node <T> * & root, const T & item)
{
    if (root == nullptr)
    {
        root = new Node <T> (item, nullptr, nullptr);
    }
    else if (item < root -> data)
    {
        insertHelper(root -> left, item);
    }
    else
    {
        insertHelper(root -> right, item);
    }
}

//*****************************************************************************************************



