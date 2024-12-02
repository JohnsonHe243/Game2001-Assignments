#include <iostream>
#include "PriorityQueueLinkedList.h"

using namespace std;

int main() 
{

    // LinkedList<int> linkedList;
    //linkedList.Push(17);
    //cout << "Current front of the linked list: " << linkedList.Front() << endl;
    //linkedList.Push(5);
    //cout << "Updated front of the linked list: " << linkedList.Front() << endl;
    //cout << "Removed: " << linkedList.Pop() << endl;
    //cout << "Removed: " << linkedList.Pop() << endl;

    PriorityQueue<int> priorityQueue;

    cout << "\n=== Testing Priority Queue ===" << endl;

    cout << "Attempting to remove an element from an empty priority queue..." << endl;
    priorityQueue.Pop();

    cout << "Adding 88 with priority of 10 to the priority queue." << endl;
    priorityQueue.Push(88, 10);
    cout << "Current front of the priority queue: " << priorityQueue.Front() << endl;

    cout << "Adding 56 with priority of 3 to the priority queue." << endl;
    priorityQueue.Push(56, 3);
    cout << "Updated front of the priority queue: " << priorityQueue.Front() << endl;

    cout << "Adding element 6 with priority of 7 to the priority queue." << endl;
    priorityQueue.Push(6, 7);
    cout << "Updated front of the priority queue: " << priorityQueue.Front() << endl;

    cout << "Adding element 90 with priority of 2 to the priority queue." << endl;
    priorityQueue.Push(90, 2);
    cout << "Updated front of the priority queue: " << priorityQueue.Front() << endl;

    cout << "Removing all elements from the priority queue in order:" << endl;
    while (priorityQueue.GetSize() > 0) {
        cout << "Removed: " << priorityQueue.Pop() << endl;
    }

    cout << "Attempting to remove an element from an empty priority queue..." << endl;
    priorityQueue.Pop();

    return 0;
}