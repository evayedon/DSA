#include <iostream>
#include "Hash.h"


using namespace std;

HashT::HashT(int tableSize)
{
    this->tableSize = tableSize;
    table = new HashNode*[tableSize];
    for (int i = 0; i < tableSize; i++)
        table[i] = nullptr;
}

HashT::~HashT()
{
    for (int i = 0; i < tableSize; i++)
    {
        HashNode *current = table[i];
        while (current != nullptr)
        {
            HashNode *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

int HashT::search(int key)
{
    int index = key % tableSize;
    HashNode *current = table[index];
    while (current != nullptr)
    {
        if (current->key == key)
            return current->value;
        current = current->next;
    }
    return -1; // Not found
}

void HashT::isItemEqual(int key, int value)
{
    int index = key % tableSize;
    HashNode *current = table[index];
    while (current != nullptr)
    {
        if (current->key == key && current->value == value)
            return; // Found equal item
        current = current->next;
    }
    cout << "Item not found or not equal" << endl;
}

void HashT::insert(int key, int value)
{
    int index = key % tableSize;
    HashNode *newNode = new HashNode{key, value, nullptr};
    if (table[index] == nullptr)
    {
        table[index] = newNode; // Insert at empty index
    }
    else
    {
        HashNode *current = table[index];
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode; // Insert at end of linked list
    }
}

int HashT::retrieve(int key)
{
    int index = key % tableSize;
    HashNode *current = table[index];
    while (current != nullptr)
    {
        if (current->key == key)
            return current->value; // Found item
        current = current->next;
    }
    return -1; // Not found
}

int HashT::remove(int key)
{
    int index = key % tableSize;
    HashNode *current = table[index];
    HashNode *prev = nullptr;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (prev == nullptr) // First node in the list
                table[index] = current->next;
            else
                prev->next = current->next;
            int value = current->value;
            delete current;
            return value; // Return the removed value
        }
        prev = current;
        current = current->next;
    }
    return -1; // Not found
}

void HashT::print()
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << "Index " << i << ": ";
        HashNode *current = table[i];
        while (current != nullptr)
        {
            cout << "(" << current->key << ", " << current->value << ") -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
}
