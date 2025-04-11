/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350-04
Assignment or exercise number: PA3 (Do You See What I See?)
*/

#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <stdexcept>


template <class T>
class MonoStack {
public:
    MonoStack(int cap, char order);
    ~MonoStack();

    void push(T x);
    T pop();
    T peek() const;

    bool isEmpty() const;
    bool isFull()  const;
    int size()     const;

private:
    T* arr;
    int capacity;
    int topIndex;
    char stackOrder; // 'd' or 'i'
};

template <class T>
MonoStack<T>::MonoStack(int cap, char order)
  : capacity(cap), stackOrder(order), topIndex(-1)
{
    arr = new T[cap];
}

template <class T>
MonoStack<T>::~MonoStack() {
    delete[] arr;
}

template <class T>
bool MonoStack<T>::isEmpty() const {
    return (topIndex < 0);
}

template <class T>
bool MonoStack<T>::isFull() const {
    return (topIndex >= capacity - 1);
}

template <class T>
int MonoStack<T>::size() const {
    return (topIndex + 1);
}

template <class T>
T MonoStack<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("MonoStack peek: empty stack");
    }
    return arr[topIndex];
}

template <class T>
T MonoStack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("MonoStack pop: empty stack");
    }
    return arr[topIndex--];
}

template <class T>
void MonoStack<T>::push(T x) {
    if (isFull()) {
        throw std::runtime_error("MonoStack push: stack overflow");
    }
    if (stackOrder == 'd') {
        // pop all smaller than x
        while (!isEmpty() && arr[topIndex] < x) {
            pop();
        }
    }
    else if (stackOrder == 'i') {
        // pop all larger than x
        while (!isEmpty() && arr[topIndex] > x) {
            pop();
        }
    }
    else {
        throw std::runtime_error("MonoStack push: invalid order specifier");
    }
    arr[++topIndex] = x;
}

#endif
