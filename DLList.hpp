#pragma once

template<class T>
class Node
{
public: 
    Node(const T &x, Node* left_node, Node* right_node)
    {
        prev = left_node;
        next = right_node;
        value = x;
    }
    T value;
    Node* prev;
    Node* next;
};

template<class T>
class DLList 
{
public:
    DLList()
    {
        head = nullptr;
        tail = nullptr;
    }

    DLList(Node<T>* head, Node<T>* tail)
    {
        this->head = head;
        this->tail = tail;
    }

    void add(Node<T>* node)
    {
        Node<T> *temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    
    


Node<T> *head;
Node<T> *tail;

};

