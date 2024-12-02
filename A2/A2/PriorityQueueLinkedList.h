#pragma once 
#include <iostream>

using namespace std;


template<class T>
class LinkNode
{

private:
	T m_data;
	LinkNode* m_next;
	LinkNode* m_prev;
	int m_prior;

public: 
	LinkNode(T data, int priority, LinkNode* next)
	{
		m_data = data;
		m_prev = nullptr;
		m_next = next;
		m_prior = priority;
	}

	LinkNode(T data, int priority, LinkNode* next, LinkNode* prev)
	{
		m_data = data;
		m_prev = next;
		m_next = nullptr;
		m_prior = priority;
	}
	
	LinkNode(T data, int priority)
	{
		m_prev = nullptr;
		m_next = nullptr;
		m_data = data;
		m_prior = priority;
	}

	LinkNode(T data, LinkNode* next)
	{
		m_data = data;
		m_prev = nullptr;
		m_next = next;
		m_prior = 0;
	}

	LinkNode(T data, LinkNode* prev, LinkNode* next)
	{
		m_data = data;
		m_prev = prev;
		m_next = next;
		m_prior = 0;
	}

	LinkNode(T data)
	{
		m_data = data;
		m_prev = nullptr;
		m_next = nullptr;
		m_prior = 0;
	}
	~LinkNode()
	{
		m_next = nullptr;
		m_prev = nullptr;
	}

	LinkNode* GetNext()
	{
		return m_next;
	}

	LinkNode* GetPrev()
	{
		return m_prev;
	}

	T GetData()
	{
		return m_data;
	}

	int GetPrior()
	{
		return m_prior;
	}

	void SetNext(LinkNode* add)
	{
		m_next = add;
	}

	void SetPrev(LinkNode* add)
	{
		m_prev = add;
	}

	void SetData(T add)
	{
		m_data = add;
	}

	void SetPrior(int add)
	{
		m_prior = add;
	}
};



template<class T>
class LinkIterator
{
public:
	LinkIterator()
	{
		m_node = NULL;
		m_location = 0;
	}

	~LinkIterator()
	{

	}

	T* GetNode()
	{
		return m_node;
	}

	void SetNode(T* node)
	{
		m_node = node;
	}

	int GetLocation()
	{
		return m_location;
	}

	void SetLocation(int location)
	{
		m_location = location;
	}

	void Iterate(T* node)
	{
		m_node = node;
		m_location++;
	}
		
private:
	T* m_node;
	int m_location;
};

template<class T>
class LinkedList
{
public:
	LinkedList()
	{
		m_size = 0;
		m_first = nullptr;
		m_last = nullptr;
	}
	
	~LinkedList() 
	{
		cout << "and...nothing" << endl;
		system("PAUSE");

		LinkNode<T>* NextNode;
		while (m_first != nullptr) {
			NextNode = m_first->GetNext();
			delete m_first;
			m_first = NextNode;
		}

	};


	void Push(T data) 
	{
		LinkNode<T>* newNode;
		if (m_size == 0) 
		{
			newNode = new LinkNode<T>(data);
			m_first = newNode;
			m_last = newNode;
			m_size++;
		}
		else 
		{
			newNode = new LinkNode<T>(data, m_first);
			m_first->SetPrev(newNode);
			m_first = newNode;
			m_size++;
		}
	};

	T Pop() { //this removes the first item of the list, it will also output the value
		if (m_size > 0) {
			T tempData = m_first->GetData();

			if (m_first->GetNext() != nullptr) {
				LinkNode<T>* TempFirst = m_first->GetNext();
				delete m_first;
				m_first = TempFirst;
				TempFirst = nullptr;
			}
			else {
				delete m_first;
				m_first = nullptr;
				m_last = nullptr;
			}

			m_size--;
			return tempData;
		}
		else {
			cout << "Error: Empty Linked List!" << endl;
		}
	};

	T Front() {
		if (m_size > 0) {
			return m_first->GetData();
		}
	};

	int GetSize()
	{
		return m_size;
	}

protected:
	int m_size;
	LinkNode<T>* m_first;
	LinkNode<T>* m_last;
	LinkIterator<LinkNode<T>> it;
};

template <class T>
class PriorityQueue : public LinkedList<T>
{
public:
	// Overloaded Push without priority - Display error message
	void Push(T data) 
	{
		cout << "Error: Priority not specified for insertion." << endl;
	}

	// Overloaded Push with priority
	void Push(T data, int priority) 
	{
		auto* newNode = new LinkNode<T>(data, priority);

		if (this->m_size == 0) 
		{
			// If the list is empty, initialize it with the new node
			this->m_first = newNode;
			this->m_last = newNode;
		}
		else {
			this->it.SetNode(this->m_first);
			while (this->it.GetNode() != nullptr) 
			{
				if (this->it.GetNode()->GetPrior() >= priority) 
				{
					// Insert new node before the current node
					newNode->SetNext(this->it.GetNode());
					newNode->SetPrev(this->it.GetNode()->GetPrev());

					if (this->it.GetNode()->GetPrev() != nullptr) 
					{
						this->it.GetNode()->GetPrev()->SetNext(newNode);
					}
					else 
					{
						// New node is the new first node
						this->m_first = newNode;
					}

					this->it.GetNode()->SetPrev(newNode);
					this->m_size++;
					return;
				}
				this->it.Iterate(this->it.GetNode()->GetNext());
			}

			// Add new node at the end if no higher-priority node is found
			this->m_last->SetNext(newNode);
			newNode->SetPrev(this->m_last);
			this->m_last = newNode;
		}
		this->m_size++;
	}
};