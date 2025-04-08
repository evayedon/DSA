#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

template <class Type>
unorderedLinkedList<Type>::unorderedLinkedList() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
unorderedLinkedList<Type>::~unorderedLinkedList() {
    initializeList();
}

template <class Type>
void unorderedLinkedList<Type>::initializeList() {
    nodeType* temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template <class Type>
bool unorderedLinkedList<Type>::isEmptyList() const {
    return (first == nullptr);
}

template <class Type>
int unorderedLinkedList<Type>::length() const {
    return count;
}

template <class Type>
void unorderedLinkedList<Type>::print() const {
    nodeType* current = first;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newElement) {
    nodeType* newNode = new nodeType;
    newNode->info = newElement;
    newNode->link = first;
    first = newNode;
    if (last == nullptr) {
        last = newNode;
    }
    count++;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newElement) {
    nodeType* newNode = new nodeType;
    newNode->info = newElement;
    newNode->link = nullptr;
    if (last != nullptr) {
        last->link = newNode;
    } else {
        first = newNode;
    }
    last = newNode;
    count++;
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    if (first == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    nodeType* current = first;
    nodeType* previous = nullptr;
    while (current != nullptr && current->info != deleteItem) {
        previous = current;
        current = current->link;
    }
    if (current == nullptr) {
        cout << "Item not found in the list." << endl;
        return;
    }
    if (previous == nullptr) {
        first = first->link;
    } else {
        previous->link = current->link;
    }
    if (current == last) {
        last = previous;
    }
    delete current;
    count--;
}

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
    nodeType* current = first;
    while (current != nullptr) {
        if (current->info == searchItem) {
            return true;
        }
        current = current->link;
    }
    return false;
}

template <class Type>
void unorderedLinkedList<Type>::insertAt(int position, const Type& newElement) {
    if (position < 0 || position > count) {
        cout << "Position out of range." << endl;
        return;
    }
    if (position == 0) {
        insertFirst(newElement);
    } else if (position == count) {
        insertLast(newElement);
    } else {
        nodeType* newNode = new nodeType;
        newNode->info = newElement;
        nodeType* current = first;
        for (int i = 1; i < position; i++) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
        count++;
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteAt(int position) {
    if (position < 0 || position >= count) {
        cout << "Position out of range." << endl;
        return;
    }
    if (position == 0) {
        deleteNode(first->info);
    } else {
        nodeType* current = first;
        nodeType* previous = nullptr;
        for (int i = 0; i < position; i++) {
            previous = current;
            current = current->link;
        }
        previous->link = current->link;
        if (current == last) {
            last = previous;
        }
        delete current;
        count--;
    }
}

