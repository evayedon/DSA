#include <iostream>
#include "binaryTree.h"

using namespace std;


// Constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}

// Destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroyTree(root);
}

// Function to destroy the binary tree
template <class elemType>
void binaryTreeType<elemType>::destroyTree(nodeType<elemType>* &p)
{
    if (p != nullptr)
    {
        destroyTree(p->left);
        destroyTree(p->right);
        delete p;
        p = nullptr;
    }
}

// Function to do an inorder traversal
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

// Helper function for inorder traversal
template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
    }
}

// Function to create a binary tree manually (for Exercise #2)
template <class elemType>
void binaryTreeType<elemType>::createBinaryTree()
{    
    root = new nodeType<elemType>;
    root->info = 10;
    
    root->left = new nodeType<elemType>;
    root->left->info = 5;
    
    root->right = new nodeType<elemType>;
    root->right->info = 15;
    
    root->left->left = new nodeType<elemType>;
    root->left->left->info = 3;
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    
    root->left->right = new nodeType<elemType>;
    root->left->right->info = 7;
    
    root->left->right->left = new nodeType<elemType>;
    root->left->right->left->info = 6;
    root->left->right->left->left = nullptr;
    root->left->right->left->right = nullptr;
    
    root->left->right->right = nullptr;
    
    root->right->left = nullptr;
    
    root->right->right = new nodeType<elemType>;
    root->right->right->info = 20;
    
    root->right->right->left = new nodeType<elemType>;
    root->right->right->left->info = 18;
    root->right->right->left->left = nullptr;
    root->right->right->left->right = nullptr;
    
    root->right->right->right = new nodeType<elemType>;
    root->right->right->right->info = 25;
    root->right->right->right->left = nullptr;
    root->right->right->right->right = nullptr;
}

// Exercise #2: Function to count the leaves in the binary tree
template <class elemType>
int binaryTreeType<elemType>::leavesCount() const
{
    return leavesCount(root);
}

// Helper function for leavesCount
template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    
    // If both left and right are null, it's a leaf node
    if (p->left == nullptr && p->right == nullptr)
        return 1;
    
    // Otherwise, continue counting in the left and right subtrees
    return leavesCount(p->left) + leavesCount(p->right);
}

// Exercise #4: Function to count nodes with only one child
template <class elemType>
int binaryTreeType<elemType>::singleParent() const
{
    return singleParent(root);
}

// Helper function for singleParent
template <class elemType>
int binaryTreeType<elemType>::singleParent(nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    
    // Check if the current node has exactly one child
    int count = 0;
    if ((p->left == nullptr && p->right != nullptr) || 
        (p->left != nullptr && p->right == nullptr))
        count = 1;
    
    // Continue counting in the left and right subtrees
    return count + singleParent(p->left) + singleParent(p->right);
}

// Function to insert a node in a BST (for testing Exercise #4)
template <class elemType>
void binaryTreeType<elemType>::insert(const elemType& insertItem)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;
    nodeType<elemType> *newNode;
    
    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->left = nullptr;
    newNode->right = nullptr;
    
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    
    current = root;
    
    while (current != nullptr)
    {
        trailCurrent = current;
        
        if (current->info == insertItem)
        {
            cout << "The item to be inserted is already in the tree." << endl;
            return;
        }
        else if (current->info > insertItem)
            current = current->left;
        else
            current = current->right;
    }
    
    if (trailCurrent->info > insertItem)
        trailCurrent->left = newNode;
    else
        trailCurrent->right = newNode;
}

// Function to print the tree structure
template <class elemType>
void binaryTreeType<elemType>::printTree() const
{
    printTree(root);
}

// Helper function to print the tree with indentation
template <class elemType>
void binaryTreeType<elemType>::printTree(nodeType<elemType> *p, int indent) const
{
    if (p != nullptr)
    {
        printTree(p->right, indent + 4);
        
        for (int i = 0; i < indent; i++)
            cout << " ";
        
        cout << p->info << endl;
        
        printTree(p->left, indent + 4);
    }
}