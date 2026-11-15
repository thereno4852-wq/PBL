
#ifndef DS_H
#define DS_H

#include <iostream>
using namespace std;

// Custom Dynamic Array
template <class T>
class DynamicArray {
private:
    T* arr;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;

        T* temp = new T[capacity];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        arr = new T[capacity];
    }

    // Prevent accidental shallow copying
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }

        arr[size] = value;
        size++;
    }

    T& get(int index) {
        return arr[index];
    }

    const T& get(int index) const {
        return arr[index];
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};


// Custom Max Heap
template <class T>
class MaxHeap {
private:
    T* arr;
    int size;
    int capacity;

    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void resize() {
        capacity *= 2;

        T* temp = new T[capacity];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < size && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest == index) {
                break;
            }

            swap(arr[index], arr[largest]);
            index = largest;
        }
    }

public:
    MaxHeap() {
        capacity = 10;
        size = 0;
        arr = new T[capacity];
    }

    // Prevent accidental shallow copying
    MaxHeap(const MaxHeap&) = delete;
    MaxHeap& operator=(const MaxHeap&) = delete;

    void push(const T& value) {
        if (size == capacity) {
            resize();
        }

        arr[size] = value;
        heapifyUp(size);
        size++;
    }

    T top() const {
        if (size == 0) {
            return T();
        }

        return arr[0];
    }

    void pop() {
        if (size == 0) {
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        if (size > 0) {
            heapifyDown(0);
        }
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    ~MaxHeap() {
        delete[] arr;
    }
};

#endif
