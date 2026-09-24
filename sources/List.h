#pragma once
#include <memory>

template <typename T>
class List {
    public:
    virtual ~List() = default;          //remove the virtual when testing alternate makeList() return

    virtual void addFront(T* data) = 0;
    virtual void deleteFront() = 0;
    virtual bool search(T* data) const = 0;
    virtual void print() const = 0;
};

#include "LinkedList.h"
#include "ArrayList.h"

template <typename T>
std::unique_ptr<List<T>> makeList() {
    return std::make_unique<LinkedList<T>>();
    //return std::make_unique<ArrayList<T>>(); (REMOVE override from ~ArrayList() override to test)
}
