#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template<class T>

class Queue
{
private:
    Node<T>* m_head;
    Node<T>* m_tail;
    int m_nodeSize;
public:
    Queue();

    void enqueue(T data);
    T dequeue(void);

    bool isEmpty(void);
    int size(void);
private:
    void initNode(T data, Node<T>* node, Node<T>* next, Node<T>* prev);
};

template<class T>
Queue<T>::Queue() : m_nodeSize(0), m_head(nullptr), m_tail(nullptr){}

template<class T>
void Queue<T>::enqueue(T data)
{
    auto node = new Node<T>();

    if (m_head == nullptr)
    {
        initNode(data, node, nullptr, nullptr);

        m_head = node;
    }
    else if (m_tail == nullptr && m_head != nullptr)
    {
        initNode(data, node, nullptr, m_head);

        m_tail = node;

        m_head->setNext(m_tail);
    }
    else if (m_head != nullptr && m_tail != nullptr)
    {
        m_tail->setNext(node);

        initNode(data, node, nullptr, nullptr);

        m_tail = node;;
    }
    else
    {
        delete node;
    }
}

template<class T>
T Queue<T>::dequeue()
{
    T ret;

    if (m_head != nullptr)
    {
        auto nodeToDequeue = m_head;

        ret = nodeToDequeue->getData();

        m_head = nodeToDequeue->getNext();

        m_nodeSize--;

        delete nodeToDequeue;
    }

    return ret;
}

template<class T>
bool Queue<T>::isEmpty()
{
    bool ret = true;

    if (m_head != nullptr)
    {
        ret = false;
    }

    return ret;
}

template<class T>
int Queue<T>::size()
{
    return m_nodeSize;
}

template<class T>
void Queue<T>::initNode(T data, Node<T> *node, Node<T> *next, Node<T> *prev)
{
    if (node != nullptr)
    {
        node->setNext(next);
        node->setPrev(prev);
        node->setData(data);
    }

    m_nodeSize++;
}

#endif // QUEUE_H
