#include <iostream>


using namespace std;

// Recursive function to print star pattern
void starPattern(int n) {
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            cout << '*';
        }
        cout << endl;
        
        // Recursive call
        starPattern(n - 1);
        
        // Print the increasing part
        for (int i = 0; i < n; ++i) {
            cout << '*';
        }
        cout << endl;
    }
}

int main() {
    int n;
    
    cout << "Test 1: n = 2" << endl;
    starPattern(2);
    cout << endl;
    
    // User input
    cout << "Enter the number of lines in the pattern: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Please enter a positive integer!" << endl;
        return 1;
    }
    
    cout << "\nGenerating pattern for n = " << n << ":" << endl;
    starPattern(n);
    
    return 0;
}