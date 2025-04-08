#ifndef QUEUES_H
#define QUEUES_H

//This chapter describes the array implementation of queues that use a special array slot, called the reserved slot, to distinguish between an empty and a full queue. 
// Write the definition of the class and the definitions of the function members of this queue design. Also, write a test program to test various operations on a queue

class Queue
{
private:
    int front;  
    int rear;  
    int size; 
    int capacity; 
    int* arr;

public:
    Queue(int cap);
    ~Queue(); 
    bool isFull(); 
    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int peek(); 
    int getSize();
};

#endif // QUEUES_H