#pragma once

template <typename T>
class Node {
    public:
    T* data;                                                    //pointer to a data in heap
    Node<T>* next;                                              //pointer to next node
    explicit Node(T* data) : data(data), next(nullptr) {}       //explicit will prevent type conversion issues
};
