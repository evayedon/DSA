#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *left;
    nodeType<elemType> *right;
};

// Class to implement a binary tree
template <class elemType>
class binaryTreeType
{
public:
    // Constructor
    binaryTreeType();

    // Destructor
    ~binaryTreeType();

    // Function to create a binary tree
    void createBinaryTree();

    // Function to do an inorder traversal
    void inorderTraversal() const;

    // Function to do an inorder traversal (helper)
    void inorder(nodeType<elemType> *p) const;

    // Function to count the leaves in the binary tree - Exercise #2
    int leavesCount() const;

    // Helper function for leavesCount
    int leavesCount(nodeType<elemType> *p) const;

    // Function to count nodes with only one child - Exercise #4
    int singleParent() const;

    // Helper function for singleParent
    int singleParent(nodeType<elemType> *p) const;

    // Function to insert a node in a BST (for testing Exercise #4)
    void insert(const elemType& insertItem);

    // Function to print the tree
    void printTree() const;

    // Helper function to print the tree
    void printTree(nodeType<elemType> *p, int indent = 0) const;

private:
    nodeType<elemType> *root;
    void destroyTree(nodeType<elemType>* &p);
};

#endif // BINARY_TREE_H