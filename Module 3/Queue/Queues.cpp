#include <iostream>
#include "Queues.h"

using namespace std;

Queue::Queue(int size) : size(size), front(-1), rear(-1) {
    arr = new int[size];
}

Queue::~Queue() {
    delete[] arr;
}

bool Queue::isFull() {
    return (rear + 1) % size == front;
}

bool Queue::isEmpty() {
    return front == -1;
}

void Queue::enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue " << item << endl;
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % size;
    arr[rear] = item;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1; // or throw an exception
    }
    int item = arr[front];
    if (front == rear) { // Queue has only one element
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }
    return item;
}

int Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot peek." << endl;
        return -1; // or throw an exception
    }
    return arr[front];
}

int Queue::getSize() {
    if (isEmpty()) {
        return 0;
    }
    return (rear - front + size) % size + 1;
}

