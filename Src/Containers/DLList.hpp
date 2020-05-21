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

    void addNode(Node<T>* node)
    {
        Node<T> *temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
    }

    void rmNode(T value)
    {
        Node<T> *ptr = head;
        while(ptr != nullptr)
        {
            if(ptr->value == value)
            {
                ptr->prev->next = ptr->next;
                break;
            }
            ptr = ptr->next;
        }
    }
    
    


Node<T> *head;
Node<T> *tail;

};

