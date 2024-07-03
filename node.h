#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
public:
    Node();
    virtual ~Node();

    void setData(T data);
    T getData(void);

    void setNext(Node<T>* next);
    Node<T>* getNext(void);

    void setPrev(Node<T>* prev);

    Node<T>* getPrev(void);

private:
    T m_data;
    Node<T>* m_next;
    Node<T>* m_prev;
};

template<class T>
Node<T>::Node(): m_next(nullptr), m_prev(nullptr){}

template<class T>
Node<T>::~Node(){}

template<class T>
void Node<T>::setData(T data)
{
    m_data = data;
}

template<class T>
T Node<T>::getData(void)
{
    return m_data;
}

template<class T>
void Node<T>::setNext(Node<T>* next)
{
    m_next = next;
}

template<class T>
Node<T>* Node<T>::getNext(void)
{
    return m_next;
}

template<class T>
void Node<T>::setPrev(Node<T>* prev)
{
    m_prev = prev;
}

template<class T>
Node<T>* Node<T>::getPrev(void)
{
    return m_prev;
}


#endif // NODE_H
