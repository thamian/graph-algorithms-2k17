//
// Created by thamian on 20.05.17.
//

#include "EdgeHeap.h"

EdgeHeap::EdgeHeap() {
    size_ = 0;
    numberOfElements_ = 0;
}

EdgeHeap::EdgeHeap(int size) {
    size_ = size;
    numberOfElements_ = 0;
    heap_ = new Edge * [size_];
}

void EdgeHeap::rebuildDown(int index) {
    int currentElement = index;
    int leftChild = 2 * currentElement + 1;
    int rightChild = 2 * currentElement + 2;

    while (0 < leftChild < numberOfElements_) {
        if (rightChild < numberOfElements_) {
            if (*heap_[currentElement] > *heap_[leftChild] || *heap_[currentElement] > *heap_[rightChild]) {
                if (*heap_[leftChild] < *heap_[rightChild]) {
                    replace(currentElement, leftChild);

                    currentElement = leftChild;
                }
                else {
                    replace(currentElement, rightChild);

                    currentElement = rightChild;
                }
            }
            else return;
        }
        else if (leftChild < numberOfElements_) {
            if (*heap_[currentElement] > *heap_[leftChild]) {
                replace(currentElement, leftChild);

                currentElement = leftChild;
            }
            else return;
        }
        else return;

        leftChild = 2 * currentElement + 1;
        rightChild = 2 * currentElement + 2;
    }
}

void EdgeHeap::rebuildUp(int index) {
    int currentElement = index;
    int parent = (currentElement - 1) / 2;

    while (-1 < parent < numberOfElements_) {
        if (*heap_[currentElement] < *heap_[parent]) {
            replace(currentElement, parent);

            currentElement = parent;
            parent = (currentElement - 1) / 2;
        }
        else return;
    }
}

void EdgeHeap::replace(int firstElement, int secondElement) {
    Edge *temporaryElement = heap_[firstElement];
    heap_[firstElement] = heap_[secondElement];
    heap_[secondElement] = temporaryElement;
}

void EdgeHeap::push(Edge *edge) {
    addLastElement(edge);
    rebuildUp(numberOfElements_ - 1);
}

Edge *EdgeHeap::pop() {
    Edge *smallestEdge = heap_[0];
    heap_[0] = heap_[numberOfElements_ - 1];
    numberOfElements_--;
    rebuildDown(0);
    return smallestEdge;
}

void EdgeHeap::addLastElement(Edge *edge) {
    if (numberOfElements_ < size_) {
        heap_[numberOfElements_] = edge;
        numberOfElements_++;
    }

    else {
        int newSize = size_ * 2 + 1;
        Edge **newArray = new Edge * [newSize];

        for (int i = 0; i < size_; i++) {
            newArray[i] = heap_[i];
        }
        newArray[numberOfElements_] = edge;

        delete [] heap_;
        heap_ = newArray;

        size_ = newSize;
        numberOfElements_++;
    }
}

void EdgeHeap::removeFirstElement() {
    if (!size_ || !numberOfElements_) return;

    for (int i = 0; i < numberOfElements_; i++) {
        heap_[i] = heap_[i + 1];
    }
    numberOfElements_--;
}

EdgeHeap::~EdgeHeap() {
    for (int i = 0; i < numberOfElements_; i++) {
        delete heap_[i];
    }
    delete [] heap_;
}
