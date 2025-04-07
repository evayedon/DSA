#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    Stack(int size = 10); // Constructor with default size
    ~Stack(); // Destructor

    void push(int value); // Push an element onto the stack
    int pop(); // Pop an element from the stack
    bool isEmpty() const; // Check if the stack is empty
    bool isFull() const; // Check if the stack is full
    int peek() const; // Peek at the top element of the stack
    int binToDecimal(int binary); // Convert binary to decimal
private:
    int* stackArray; // Array to hold stack elements
    int top; // Index of the top element in the stack
    int maxSize;     
};

#endif // STACK_H
