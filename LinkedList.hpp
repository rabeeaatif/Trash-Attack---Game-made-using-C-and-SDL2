#pragma once
#include "Node.hpp"

template <typename T>
class LinkedList
{
    private:
        Node<T>* head;

    public:
        LinkedList();
        int GetSize();
        void push(int index, T data);
        Node<T>* get_head();



}