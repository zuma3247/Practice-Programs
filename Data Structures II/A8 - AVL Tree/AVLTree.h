//*****************************************************************************************************
//
//		File:			    AVLTree.h
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
//		This file defines an AVL Tree.
//
//
//*****************************************************************************************************

#ifndef AVLTREE_H
#define AVLTREE_H

//*****************************************************************************************************

#include <iostream>
#include <algorithm>
using namespace std;

//*****************************************************************************************************

template <typename T>
struct Node
{
    T value;
    int balanceFactor;
    Node <T> * left;
    Node <T> * right;

    Node(const T& val, int bf = 0, Node <T> * l = nullptr, Node <T> * r = nullptr)
            : value(val), balanceFactor(bf), left(l), right(r) {}
};

//*****************************************************************************************************

template <typename T>
class AVLTree
{
private:
    Node <T> * root;

    Node <T> * rotateLeft(Node <T> * k1);
    Node <T> * rotateRight(Node <T> * k1);
    Node <T> * insert_helper(Node <T> * root, const T& key);
    Node <T> * remove_Helper(Node <T> * root, const T& key);
    Node <T> * findMin(Node <T> * node) const;

    bool retrieve_helper(Node <T> * root, T& key) const;
    void inOrderTraversal(Node <T> * root) const;
    void preOrderTraversal(Node <T> * root) const;
    void postOrderTraversal(Node <T> * root) const;
    int height(Node <T> * node) const;
    int getBalance(Node <T> * r) const;
    void updateBalanceFactor(Node <T> * node);
    void deleteTree(Node <T> * & r);

public:
    AVLTree();
    ~AVLTree();
    void inorder() const;
    void preOrder() const;
    void postOrder() const;
    void insert(const T & item);
    void remove(const T & item);
    bool retrieve(T & item);
    int height() const;
};

//*****************************************************************************************************

template <typename T>
Node <T> * AVLTree<T>:: rotateLeft(Node <T> * k1)
{
    Node <T> * k2 = k1 -> right;
    Node<T> * T2 = k2 -> left;

    k2 -> left = k1;
    k1 -> right = T2;

    updateBalanceFactor(k1);
    updateBalanceFactor(k2);

    return k2;
}

//*****************************************************************************************************

template <typename T>
Node<T> * AVLTree<T> :: rotateRight(Node <T> * k1)
{
    Node <T> * k2 = k1 -> left;
    Node <T> * T2 = k2 -> right;

    k2 -> right = k1;
    k1 -> left = T2;

    updateBalanceFactor(k1);
    updateBalanceFactor(k2);

    return k2;
}

//*****************************************************************************************************

template <typename T>
Node <T> * AVLTree<T> :: insert_helper(Node <T> * root, const T & key)
{
    Node <T> * newNode;
    int balance;

    if (root == nullptr)
    {
        newNode = new Node <T> {key, 0, nullptr, nullptr};
        return newNode;
    }

    if (key < root -> value)
    {
        root -> left = insert_helper(root -> left, key);
    }
    else if (key > root -> value)
    {
        root -> right = insert_helper(root -> right, key);
    }
    else
    {
        return root;
    }

    updateBalanceFactor(root);
    balance = root -> balanceFactor;

    if (balance > 1)
    {
        if (key < root -> left -> value)
        {
            return rotateRight(root);
        }
        if (key > root -> left -> value)
        {
            root->left = rotateLeft(root -> left);
            return rotateRight(root);
        }
    }

    if (balance < -1)
    {
        if (key > root -> right -> value)
        {
            return rotateLeft(root);
        }
        if (key < root -> right -> value)
        {
            root -> right = rotateRight(root -> right);
            return rotateLeft(root);
        }
    }

    return root;
}

//*****************************************************************************************************

template <typename T>
Node<T> * AVLTree <T> :: remove_Helper(Node <T> * root, const T & key)
{
    Node <T> * temp;
    int balance;

    if (root == nullptr)
    {
        return root;
    }

    if (key < root -> value)
    {
        root -> left = remove_Helper(root -> left, key);
    }
    else if (key > root -> value)
    {
        root -> right = remove_Helper(root -> right, key);
    }
    else
    {
        if (root -> left == nullptr || root -> right == nullptr)
        {
            if (root -> left != nullptr)
            {
                temp = root -> left;
            }
            else
            {
                temp = root -> right;
            }
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                * root = * temp;
            }
            delete temp;
        }
        else
        {
            temp = findMin(root -> right);
            root -> value = temp -> value;
            root -> right = remove_Helper(root -> right, temp -> value);
        }
    }

    if (root == nullptr)
    {
        return root;
    }

    updateBalanceFactor(root);
    balance = root -> balanceFactor;

    if (balance > 1)
    {
        if (getBalance(root -> left) >= 0)
        {
            return rotateRight(root);
        }

        if (getBalance(root -> left) < 0)
        {
            root -> left = rotateLeft(root -> left);
            return rotateRight(root);
        }
    }

    if (balance < -1)
    {
        if (getBalance(root -> right) <= 0)
        {
            return rotateLeft(root);
        }
        if (getBalance(root -> right) > 0)
        {
            root -> right = rotateRight(root -> right);
            return rotateLeft(root);
        }
    }

    return root;
}

//*****************************************************************************************************

template <typename T>
Node <T> * AVLTree <T> :: findMin(Node <T> * node) const
{
    Node <T> * current = node;
    while (current -> left != nullptr)
    {
        current = current -> left;
    }
    return current;
}

//*****************************************************************************************************

template <typename T>
bool AVLTree <T> :: retrieve_helper(Node <T> * root, T & key) const
{
    if (root == nullptr)
    {
        return false;
    }

    if (key < root->value)
    {
        return retrieve_helper(root -> left, key);
    }
    else if
    (key > root->value)
    {
        return retrieve_helper(root -> right, key);
    }
    else
    {
        key = root -> value;
        return true;
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: inOrderTraversal(Node <T> * root) const
{
    if (root != nullptr)
    {
        inOrderTraversal(root -> left);
        cout << root -> value << " ";
        inOrderTraversal(root -> right);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: preOrderTraversal(Node <T> * root) const
{
    if (root != nullptr)
    {
        cout << root -> value << " ";
        preOrderTraversal(root -> left);
        preOrderTraversal(root -> right);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T> :: postOrderTraversal(Node <T> * root) const
{
    if (root != nullptr)
    {
        postOrderTraversal(root -> left);
        postOrderTraversal(root -> right);
        cout << root -> value << " ";
    }
}

//*****************************************************************************************************

template <typename T>
int AVLTree <T> :: height(Node <T> * node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + std::max(height(node -> left), height(node -> right));
}

//*****************************************************************************************************

template <typename T>
int AVLTree <T> :: getBalance(Node <T> * r) const
{
    if (r == nullptr)
    {
        return 0;
    }
    return height(r -> left) - height(r -> right);
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: updateBalanceFactor(Node <T> * node)
{
    if (node != nullptr)
    {
        node -> balanceFactor = getBalance(node);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: deleteTree(Node <T> * & r)
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
AVLTree <T> :: AVLTree()
{
    root = nullptr;
}

//*****************************************************************************************************

template <typename T>
AVLTree <T> :: ~AVLTree()
{
    deleteTree(root);
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: inorder() const
{
    inOrderTraversal(root);
    cout << endl;
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: preOrder() const
{
    preOrderTraversal(root);
    cout << endl;
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: postOrder() const
{
    postOrderTraversal(root);
    cout << endl;
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: insert(const T & item)
{
    root = insert_helper(root, item);
}

//*****************************************************************************************************

template <typename T>
void AVLTree <T> :: remove(const T & item)
{
    root = remove_Helper(root, item);
}

//*****************************************************************************************************

template <typename T>
bool AVLTree <T> :: retrieve(T & item)
{
    return retrieve_helper(root, item);
}

//*****************************************************************************************************

template <typename T>
int AVLTree <T> :: height() const
{
    return height(root);
}

//*****************************************************************************************************

#endif AVLTREE_H
