
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <class T>
class Queue {
private:

    struct Node {
        T data;
        Node* next;

        Node(T value) {
            data = value;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* rearNode;
    int size;

public:

    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
        size = 0;
    }

    // Prevent shallow copying
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    // Add booking request
    void enqueue(T value) {
        Node* newNode = new Node(value);

        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }

        size++;
    }

    // Remove booking request
    void dequeue() {
        if (frontNode == nullptr) {
            return;
        }

        Node* temp = frontNode;

        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
        size--;
    }

    // Get first booking request
    T front() const {
        if (frontNode == nullptr) {
            return T();
        }

        return frontNode->data;
    }

    bool empty() const {
        return frontNode == nullptr;
    }

    int getSize() const {
        return size;
    }

    ~Queue() {
        while (frontNode != nullptr) {
            dequeue();
        }
    }
};

#endif
