#include <iostream>
#include "Hash.h"
#include "Hash.cpp"

using namespace std;

int main() {
    HashT hashTable(10); 

    // Add values to the hash table
    hashTable.insert(1, 100);
    hashTable.insert(2, 200);
    hashTable.insert(3, 300);

    // Search for a value in the hash table
    int value = hashTable.search(2);
    if (value != -1) {
        cout << "Value found: " << value << endl;
    } else {
        cout << "Value not found" << endl;
    }

    // Check if an item is equal to a specific key and value
    hashTable.isItemEqual(2, 200);

    // Retrieve a value from the hash table
    int retrievedValue = hashTable.retrieve(3);
    cout << "Retrieved value: " << retrievedValue << endl;

    return 0;
}