#include <iostream>
#include "using stack.h"
#include <cmath>

using namespace std;

Stack::Stack(int size) : maxSize(size), top(-1) {
    stackArray = new int[maxSize]; // Allocate memory for the stack array
}

Stack::~Stack() {
    delete[] stackArray; // Deallocate memory for the stack array
}

void Stack::push(int value) {
    if (isFull()) {
        cout << "Stack is full. Cannot push " << value << endl;
        return;
    }
    stackArray[++top] = value; // Increment top and push the value onto the stack
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop." << endl;
        return -1; // Return -1 if the stack is empty
    }
    return stackArray[top--]; // Return the top value and decrement top
}

bool Stack::isEmpty() const {
    return top == -1; // Check if the stack is empty
}

bool Stack::isFull() const {
    return top == maxSize - 1; // Check if the stack is full
}

int Stack::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot peek." << endl;
        return -1; // Return -1 if the stack is empty
    }
    return stackArray[top]; // Return the top value without removing it
}

int Stack::binToDecimal(int binary) 
{   
    int decimal_value = 0;
    int power = 0;

    // Convert binary to decimal by processing each digit
    while (binary > 0) {
        int digit = binary % 10; // Extract the last digit
        if (digit != 0 && digit != 1) {
            cout << "Invalid binary number." << endl;
            return -1; // Return -1 for invalid binary input
        }
        decimal_value += digit * std::pow(2, power); // Calculate the decimal value
        binary /= 10; // Remove the last digit from the binary number
        power++;
    }
    
    return decimal_value;
}