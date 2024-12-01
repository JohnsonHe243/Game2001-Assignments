#include <iostream>
#include "PriorityQueueLinkedList.h"

using namespace std;

int main(void) {

	LinkedList<int> TestIntList;

	PriorityQueue<int> TestPrio;

	cout << "Testing base Linked list" << endl;
	cout << "First we will attempt to pop an empty list" << endl;

	TestIntList.Pop();

	cout << "Now we will push in a value of 20" << endl;
	TestIntList.Push(20);

	cout << "The front of the linked list is ";
	cout << TestIntList.Front() << endl;
	cout << "Now we push in 10" << endl;
	TestIntList.Push(10);

	cout << "The front of the list is now ";
	cout << TestIntList.Front() << endl;

	cout << "Now we will pop out both of the values" << endl;
	cout << TestIntList.Pop() << endl;
	cout << TestIntList.Pop() << endl << endl;
	//this is testing the linked list part

	cout << "Testing Priority Queue now" << endl;
	cout << "First we will try and pop an empty list" << endl;
	TestPrio.Pop();

	cout << "Now we will push in a 10 with priority 10" << endl;
	TestPrio.Push(10, 10);

	cout << "The front of the list is now ";
	cout << TestPrio.Front() << endl;

	cout << "Now we will push in a 20 with a priority of 5" << endl;
	TestPrio.Push(20, 5);

	cout << "The front of the list is now ";
	cout << TestPrio.Front() << endl;

	cout << "Now we will push in a 15 with a priority of 7" << endl;
	TestPrio.Push(15, 7);

	cout << "The front of the list is now ";
	cout << TestPrio.Front() << endl;

	cout << "Now we will push in a 40 with priority of 5" << endl;
	TestPrio.Push(40, 5);

	cout << "The front of the list is now ";
	cout << TestPrio.Front() << endl;

	cout << "Lastly we will pop out all values of the list" << endl;
	while (TestPrio.GetSize() > 0) {
		cout << TestPrio.Pop() << endl;
	}



	system("PAUSE");

	return 0;
}