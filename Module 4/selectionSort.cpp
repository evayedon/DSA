#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void append(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
}

void selectionSort(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->data < minNode->data)
                minNode = j;
        }
        swap(i->data, minNode->data);
    }
}

Node* generateRandomList(int size) {
    Node* head = nullptr;
    for (int i = 0; i < size; ++i) {
        int value = rand() % 10000;  // Random number between 0 and 9999
        append(head, value);
    }
    return head;
}

Node* cloneList(Node* head) {
    if (!head) return nullptr;
    Node* newHead = new Node(head->data);
    Node* current = newHead;
    Node* original = head->next;

    while (original) {
        current->next = new Node(original->data);
        current = current->next;
        original = original->next;
    }

    return newHead;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;

    Node* a;
    Node* b;

    split(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = merge(a, b);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random generator

    int size =10000;

    cout << "Size\tSelection(ms)\tMerge(ms)\n";

    
    Node* original = generateRandomList(size);
    Node* list1 = cloneList(original);
    Node* list2 = cloneList(original);

    auto start1 = high_resolution_clock::now();
    selectionSort(list1);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    mergeSort(&list2);
    auto end2 = high_resolution_clock::now();

    auto duration1 = duration_cast<milliseconds>(end1 - start1).count();
    auto duration2 = duration_cast<milliseconds>(end2 - start2).count();

    cout << size << "\t" << duration1 << "\t\t" << duration2 << "\n";

    freeList(original);
    freeList(list1);
    freeList(list2);
   

    return 0;
}
