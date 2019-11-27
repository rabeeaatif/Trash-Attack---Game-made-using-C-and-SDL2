#pragma once
#include <iostream>

template<typename T>
class Node
{
protected:
    T data; ///change this to type template///
    Node<T>* prev;
    Node<T>* next;
    int index;



public:
    /** Default constructor */
    Node<T>()
    {
        prev = NULL;
        next = NULL;
    }

};

