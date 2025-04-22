#include <iostream>
using namespace std;

// Recursive function to reverse elements between low and high indices
void reverseArray(int intArray[], int low, int high) {
    if (low >= high) {
        return;
    }
    
    // Swap elements at low and high indices
    int temp = intArray[low];
    intArray[low] = intArray[high];
    intArray[high] = temp;
    
    reverseArray(intArray, low + 1, high - 1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test case 1: Reversing entire array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "Test Case 1: Reversing entire array" << endl;
    cout << "Original array: ";
    printArray(arr1, size1);
    
    reverseArray(arr1, 0, size1 - 1);
    
    cout << "Reversed array: ";
    printArray(arr1, size1);
    cout << endl;
    
    // Test case 2: Reversing a portion of the array
    int arr2[] = {10, 20, 30, 40, 50, 60, 70};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "Test Case 2: Reversing elements from index 2 to 5" << endl;
    cout << "Original array: ";
    printArray(arr2, size2);
    
    reverseArray(arr2, 2, 5);
    
    cout << "After reversing from index 2 to 5: ";
    printArray(arr2, size2);
    cout << endl;
    
    // Test case 3: Reversing with user input
    const int MAX_SIZE = 100;
    int arr3[MAX_SIZE];
    int size3, low, high;
    
    cout << "Test Case 3: User input" << endl;
    cout << "Enter the size of the array (max 100): ";
    cin >> size3;
    
    if (size3 <= 0 || size3 > MAX_SIZE) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    
    cout << "Enter " << size3 << " integers:" << endl;
    for (int i = 0; i < size3; i++) {
        cin >> arr3[i];
    }
    
    cout << "Enter low index: ";
    cin >> low;
    cout << "Enter high index: ";
    cin >> high;
    
    if (low < 0 || high >= size3 || low >= high) {
        cout << "Invalid indices! Make sure 0 <= low < high < " << size3 << endl;
        return 1;
    }
    
    cout << "Original array: ";
    printArray(arr3, size3);
    
    reverseArray(arr3, low, high);
    
    cout << "After reversing from index " << low << " to " << high << ": ";
    printArray(arr3, size3);
    
    return 0;
}