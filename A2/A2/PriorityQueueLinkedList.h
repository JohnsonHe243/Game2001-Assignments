#pragma once 
#include <cassert>

template <typename T> class LinkIterator;
template <typename T> class SinglyLinkList;

template<typename T>
class LinkNode
{
	friend class LinkIterator<T>;
	friend class SinglyLinkList<T>;

private:
	T m_data;
	LinkNode* m_next;
};

template<typename T>
class LinkIterator
{
public:
	LinkIterator()
	{
		m_node = NULL;
	}

	~LinkIterator
	{

	}

	void operator=(LinkNode<T> *node)
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

	void operator!=(LinkNode<T> *node)
	{
		return (m_node != node);
	}

	void operator==(LinkNode<T>* node)
	{
		return (m_node == node);
	}

		
private:
	LinkNode<T> *m_node;
};

template<typename T>
class SinglyLin