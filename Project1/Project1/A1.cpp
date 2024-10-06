// Student Name: Jin He
// Student ID: 101175996

#include <iostream>
#include <cassert>

using namespace std;

// Base Array Template
template<class T>
class Array
{
public:
	// Constructor
	Array(int size, int growBy = 2) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)	// Is this a legal size for an array?
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];		// Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize);	// Explicitly set 0 to all elements in the array

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	~Array()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	// Deletion (2 ways)
	// Remove the last item inserted into the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;	// Reduce the total number of elements by 1. Ignoring the last element.
		}
	}
	// Remove an item given an index
	// (Almost) Brute-force execution -- Big-O = O(N)
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{
			// I am trying to remove something outside of the bounds of the array
			return;	// <-- Maybe could do some form of exception handling
		}

		for (int i = index; i < m_numElements; i++)
		{
			// Start at the index we want to remove.
			// Shift everything after index back by one.
			if (i + 1 < m_numElements)	// Confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	// Clear
	void clear()
	{
		m_numElements = 0;	 // Ignore (or forgets) all current items in the array
	}
	// Gets and Sets
	int GetSize()
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
	bool GetExpand()
	{
		Expand();
	}
private:
	// Protected functions
	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			// LEAVE!
			return false;
		}

		// Create the new array
		T* temp = new T[m_maxSize + m_growSize * m_increment]; // Expand Increment
		assert(temp != nullptr);

		// Copy the contents of the original array into the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		// Delete the old array
		delete[] m_array;

		// Clean up variable assignments
		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;
		m_growSize = m_growSize * m_increment;

		return true;
	}
private:
	// Protected Variables
	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;		// Maximum size of the array
	int m_growSize;		// Amount the array can grow through expansion
	int m_numElements;	// Number of items currently in my array

	int m_increment = 2; // // Expand Increment
};

template <typename T>
class UnorderedArray : public Array<T> 
{
public:
	UnorderedArray(int size) : Array() {}
	~UnorderedArray() : ~Array() {}
	// Insertion
	// Fast insertion for UnorderedArray -- Big-O is O(1)
	void push(T val)
	{
		assert(Array<T>::m_array != nullptr); // Debugging purposes

		if (Array<T>::m_numElements >= Array<T>::m_maxSize)	// Check if the array has to expand to accommodate the new data.
		{
			Array<T>::Expand();
		}

		// My array has space for a new value. Let's add it!
		Array<T>::m_array[Array<T>::m_numElements] = val;
		Array<T>::m_numElements++;
	}
	// Searching
	// Linear Search
	int search(T val)
	{
		assert(Array<T>::m_array != nullptr);

		// Brute-force Search
		for (int i = 0; i < Array<T>::m_numElements; i++)
		{
			if (Array<T>::m_array[i] == val)
			{
				return i;	// Return the index of where the item is located in the array
			}
		}

		return -1;
	}
};

template <typename T>
class OrderedArray : public Array<T>
{
	
public:
	OrderedArray(int size) : Array() {}
	~OrderedArray() : ~Array() {}


	// Insertion -- Big-O = O(N)
	void push(T val)
	{
		assert(Array<T>::m_array != nullptr);

		if (Array<T>::m_numElements >= Array<T>::m_maxSize)
		{
			Array<T>::Expand();
		}

		int i, k;	// i - Index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val
		for (i = 0; i < Array<T>::m_numElements; i++)
		{
			if (Array<T>::m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index(i) forward by one. Work backwards
		for (k = Array<T>::m_numElements; k > i; k--)
		{
			Array<T>::m_array[k] = Array<T>::m_array[k - 1];
		}

		// Step 3: Insert val into the array at index
		Array<T>::m_array[i] = val;

		Array<T>::m_numElements++;

		// return i;
	}
	// Searching
	// Binary Search
	int search(T searchKey)
	{
		assert(Array<T>::m_array != nullptr);

		// Helper variables.
		int lowerBound = 0;
		int upperBound = Array<T>::m_numElements - 1;
		int current = 0;

		while (1)	// <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1;	//bitwise operation; divides by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for.
			if (Array<T>::m_array[current] == searchKey)
			{
				// Found the item in the middle of the array. Return the index
				return current;
			}
			// Step 2: Check that we've exhausted all options. Can't find the item
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			// Step 3: Check which half of the array the value is in.
			else
			{
				if (Array<T>::m_array[current] < searchKey)
				{
					lowerBound = current + 1;	// Value may be in the upper half
				}
				else
				{
					upperBound = current - 1;	// Value may be in the lower half
				}
			}
		}
		return -1;	// Catch all return from danger.
	}
};



int main()
{


}
