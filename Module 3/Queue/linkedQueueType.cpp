#include <iostream>
#include "linkedQueueType.h"
#include "unorderedLinkedList.h"
#include "unorderedLinkedList.cpp" 


using namespace std;


void linkedQueueType::initializeQueue() {
    unorderedLinkedList::initializeList(); 
}


bool linkedQueueType::isEmptyQueue() const {
    return unorderedLinkedList::isEmptyList(); 
}


bool linkedQueueType::isFullQueue() const {
    return false; 
}


int linkedQueueType::front() const {
    if (isEmptyQueue()) {
        cout << "Queue is empty. Cannot access front element." << endl;
        return -1; 
    } else {
        return getFirst()->info; 
    }
}


int linkedQueueType::back() const {
    if (isEmptyQueue()) {
        cout << "Queue is empty. Cannot access back element." << endl;
        return -1; 
    } else {
        return getLast()->info; 
    }
}


void linkedQueueType::addQueue(const int& newElement) {
    unorderedLinkedList::insertLast(newElement); 
}


void linkedQueueType::deleteQueue() {
    if (isEmptyQueue()) {
        cout << "Queue is empty. Cannot delete element." << endl;
    } else {
        unorderedLinkedList::deleteNode(getFirst()->info); 
    }
}


