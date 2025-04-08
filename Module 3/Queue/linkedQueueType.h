#ifndef LINKEDQUEUETYPE_H
#define LINKEDQUEUETYPE_H   

#include "unorderedLinkedList.h"
// Write the definition of the class linkedQueueType, which is derived from the class unorderedLinkedList, as explained in this chapter. 
// Also, write a program to test various operations of this class

class linkedQueueType : public unorderedLinkedList<int>
{
public:
    void initializeQueue(); 
    bool isEmptyQueue() const; 
    bool isFullQueue() const; 
    int front() const; 
    int back() const; 
    void addQueue(const int& newElement); 
    void deleteQueue(); 
};  
#endif // LINKEDQUEUETYPE_H