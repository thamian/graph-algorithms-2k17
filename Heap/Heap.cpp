//
// Created by thamian on 13.05.17.
//

#include "Heap.h"

Heap::Heap() {
    size_ = 0;
    numberOfElements_ = 0;
}

Heap::Heap(Graph *graph, int *array) {
    size_ = graph->getNumberOfVertices();
    numberOfElements_ = size_;

    heap_ = new int [numberOfElements_];
    for (int i = 0; i < numberOfElements_; i++) {
        heap_[i] = i;
    }

    int firstNodeNumber = graph->getFirstVertexNumber();
    indexArray_ = array;

    transpose(heap_, 0, firstNodeNumber);
    transpose(indexArray_, 0, firstNodeNumber);
}

void Heap::rebuildDown(int index) {
    int currentElement = index;
    int leftChild = 2 * currentElement + 1;
    int rightChild = 2 * currentElement + 2;
    int temporaryElement;

    while (0 <= currentElement < numberOfElements_) {
        if (rightChild < numberOfElements_) {
            if (d_[heap_[currentElement]] > d_[heap_[leftChild]] || d_[heap_[currentElement]] > d_[heap_[rightChild]]) {
                if (d_[heap_[leftChild]] < d_[heap_[rightChild]]) {
                    temporaryElement = heap_[currentElement];
                    heap_[currentElement] = heap_[leftChild];
                    heap_[leftChild] = temporaryElement;

                    indexArray_[heap_[currentElement]] = leftChild;
                    indexArray_[heap_[leftChild]] = currentElement;

                    currentElement = leftChild;
                }
                else {
                    temporaryElement = heap_[currentElement];
                    heap_[currentElement] = heap_[rightChild];
                    heap_[rightChild] = temporaryElement;

                    indexArray_[heap_[currentElement]] = rightChild;
                    indexArray_[heap_[rightChild]] = currentElement;

                    currentElement = rightChild;
                }
            }
            else return;
        }
        else if (leftChild < numberOfElements_) {
            if (d_[heap_[currentElement]] > d_[heap_[leftChild]]) {
                temporaryElement = heap_[currentElement];
                heap_[currentElement] = heap_[leftChild];
                heap_[leftChild] = temporaryElement;

                indexArray_[heap_[currentElement]] = leftChild;
                indexArray_[heap_[leftChild]] = currentElement;

                currentElement = leftChild;
            }
            else return;
        }
        else return;

        leftChild = 2 * currentElement + 1;
        rightChild = 2 * currentElement + 2;
    }
}

void Heap::rebuildUp(int index) {
    int currentElement = index;
    int parent = (currentElement - 1) / 2;
    int temporaryElement;

    while (-1 < currentElement < numberOfElements_) {
        if (d_[heap_[currentElement]] < d_[heap_[parent]]) {
            temporaryElement = heap_[currentElement];
            heap_[currentElement] = heap_[parent];
            heap_[parent] = temporaryElement;

            indexArray_[heap_[currentElement]] = parent;
            indexArray_[heap_[parent]] = currentElement;

            currentElement = parent;
            parent = (currentElement - 1) / 2;
        }
        else return;
    }
}

void Heap::push(int value) {
    addLastElement(value);
    rebuildUp(numberOfElements_ - 1);
}

void Heap::pop() {
    //indexArray_[heap_[0]] = -1;

    heap_[0] = heap_[numberOfElements_ - 1];
    indexArray_[heap_[0]] = 0;

    numberOfElements_--;
    rebuildDown(0);
}

void Heap::addLastElement(int value) {
    int newSize = size_ * 2 + 1;

    if (numberOfElements_ < size_) {
        heap_[numberOfElements_] = value;
        numberOfElements_++;
    }

    else {
        int *newArray = new int [newSize];

        for (int i = 0; i < size_; i++) {
            newArray[i] = heap_[i];
        }
        newArray[numberOfElements_] = value;

        delete [] heap_;
        heap_ = newArray;

        size_ = newSize;
        numberOfElements_++;
    }
}

void Heap::removeFirstElement() {
    if (!size_ || !numberOfElements_)
        return;

    for (int i = 0; i < numberOfElements_; i++) {
        heap_[i] = heap_[i + 1];
    }
    numberOfElements_--;
}

int Heap::getFirst() {
    return heap_[0];
}

void Heap::setD(int *array) {
    d_ = array;
}

void Heap::transpose(int *array, int firstPosistion, int secondPosition) {
    int temporaryElement = array[firstPosistion];
    array[firstPosistion] = array[secondPosition];
    array[secondPosition] = temporaryElement;
}

Heap::~Heap() {
    delete [] heap_;
}
