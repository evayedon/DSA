#include <iostream>
#include "binaryTree.h"
#include "binaryTree.cpp"

using namespace std;


void testLeavesCount()
{
    binaryTreeType<int> tree;
    
    cout << "==== Testing leavesCount function ====" << endl;
    
    // Create a binary tree
    tree.createBinaryTree();
    
    cout << "Tree structure:" << endl;
    tree.printTree();
    
    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;
    
    // Count leaves
    cout << "Number of leaf nodes: " << tree.leavesCount() << endl;
    cout << endl;
}

// Test program for Exercise #4
void testSingleParent()
{
    binaryTreeType<int> bst;
    
    cout << "==== Testing singleParent function ====" << endl;
    
    // Create a binary search tree
    bst.insert(50);
    bst.insert(70);
    bst.insert(60);
    bst.insert(35);
    bst.insert(80);
    bst.insert(90);
    bst.insert(10);
    bst.insert(100);
    
    cout << "BST structure:" << endl;
    bst.printTree();
    
    cout << "Inorder traversal: ";
    bst.inorderTraversal();
    cout << endl;
    
    // Count single parent nodes
    cout << "Number of nodes with only one child: " << bst.singleParent() << endl;
    cout << endl;
}

int main()
{
    // Test Exercise #2
    testLeavesCount();
    
    // Test Exercise #4
    testSingleParent();
    
    return 0;
}