#include <iostream>
#include "Queues.h"
#include "Queues.cpp"
#include "linkedQueueType.h"
#include "linkedQueueType.cpp"

using namespace std;


int main() {
    Queue q(5); 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element is: " << q.peek() << endl; 

    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Front element is: " << q.peek() << endl; 

    q.enqueue(60); 
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    
    cout  << endl;
    cout << "Start of linked queue operations" << endl;
    linkedQueueType queue; 
    queue.initializeQueue(); 

    queue.addQueue(10);
    queue.addQueue(20);
    queue.addQueue(30);

    cout << "Front element: " << queue.front() << endl;
    cout << "Back element: " << queue.back() << endl;  

    
    queue.deleteQueue(); 

    
    cout << "Front element after deletion: " << queue.front() << endl; 
    return 0;
}