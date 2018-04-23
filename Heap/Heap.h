//
// Created by thamian on 13.05.17.
//

#ifndef P2_HEAP_H
#define P2_HEAP_H


#include <Graph.h>

class Heap {
protected:
    int size_;
    int numberOfElements_;
    int *heap_;
    int *d_;
    int *indexArray_;

public:
    Heap();
    ~Heap();
    Heap(Graph *graph, int *array);
    void rebuildDown(int index);
    void rebuildUp(int index);
    void push(int value);
    void pop();
    void addLastElement(int value);
    void removeFirstElement();
    int getFirst();
    void setD(int *array);
    void transpose(int *array, int firstPosistion, int secondPosition);
};


#endif //P2_HEAP_H
