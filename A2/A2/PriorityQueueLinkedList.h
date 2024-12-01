#pragma once 
#include <cassert>

using namespace std;

template <typename T> class LinkIterator;
template <typename T> class SinglyLinkList;

template<class T>
class LinkNode
{
	friend class LinkIterator<T>;
	friend class SinglyLinkList<T>;

private:
	T m_data;
	LinkNode* m_next;
	LinkNode* m_prev;
	int m_prior;

public: 
	Node(T data, int priority, Node* next)
	{
		m_data = data;
		m_prev = nullptr;
		m_next = next;
		m_prior = priority;
	}

	Node(T data, int priority, Node* next, Node* prev)
	{
		m_data = data;
		m_prev = next;
		m_next = nullptr;
		m_prior = priority;
	}
	
	Node(T data)
	{
		m_data = data;
		m_prev = nullptr;
		m_next = nullptr
		m_priority = 0;
	}

	Node(T data, Node* next)
	{
		m_data = inputData;
		m_prev = nullptr;
		m_next = next;
		m_prior = 0;
	}

	Node(T data, Node* prev, Node* next)
	{
		m_data = data;
		m_prev = prev;
		m_next = next;
		m_prior = 0;
	}

	~Node()
	{
		m_next = nullptr;
		m_prev = nullptr;
	}

	Node* GetNext()
	{
		return m_next;
	}

	Node* GetPrev()
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

	void SetNext(Node* add)
	{
		m_next = add;
	}

	void SetPrev(Node* add)
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



template<typename T>
class LinkIterator
{
public:
	LinkIterator()
	{
		m_node = NULL;
		nodePosition = 0;
	}

	~LinkIterator
	{

	}

	void operator=(LinkNode<T>* node)
	{
		m_node = node;
	}
		
	T& operator*()
	{
		assert(m_node != NULL);
		return m_node->m_data;
	}
		 
	void operator++()
	{
		assert(m_node != NULL);
	}

	void operator++(int)
	{
		assert(m_node != NULL);
		return m_node = m_node->m_next;
	}

	void operator!=(LinkNode<T>* node)
	{
		return (m_node != node);
	}

	void operator==(LinkNode<T>* node)
	{
		return (m_node == node);
	}

		
private:
	LinkNode<T>* m_node;
	int nodePosition;
};

template<typename T>
class SinglyLinkList
{
protected:
public:
	LinkList() : m_size(0), m_root(0), m_lastNode(0)
	{

	}
	
	~LinkList()
	{
		while (m_root = NULL)
		{
			Pop();
		}
	}

	LinkNode<T>* Begin()
	{
		assert(m_root != NULL);
		return m_root;
	}

	LinkNode<T>* End()
	{
		return NULL;
	}

	void Push(T newData)
	{
		LinkNode<T> *node = new LinkNode<T>;

		assert(node != NULL);
		node->m_data = newData;
		node->m_next = NULL;

		if (m_lastNode != NULL)
		{
			m_lastNode->m_next = node;
			m_lastNode = node;
		}
		else
		{
			m_root = node;
			m_lastNode = node
		}
		 
		m_size++;
	}

	void Pop()
	{
		assert(m_root != NULL);

		if (m_root->m_next == NULL)
		{
			delete m_root;
			m_root = NULL;
		}
		else
		{
			LinkNode<T>* prev Node = m_root;

			while (prevNode->m_next != NULL &&
				prevNode->m_next != m_lastNode)
			{
				prevNode = prevNode->m_next;
			}

			delete m_lastNode;
			prevNode->m_next = NULL;
			m_lastNode = prevNode;
		}

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}

	int GetSize()
	{
		return m_size;
	}

private:
	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;
};