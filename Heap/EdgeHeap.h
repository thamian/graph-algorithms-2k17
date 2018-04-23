//
// Created by thamian on 20.05.17.
//

#ifndef P2_COMPARABLEHEAP_H
#define P2_COMPARABLEHEAP_H


#include <Edge.h>
#include <Graph.h>

class EdgeHeap {
    Edge **heap_;
    int size_;
    int numberOfElements_;

public:
    EdgeHeap();
    EdgeHeap(int size);
    ~EdgeHeap();
    void rebuildDown(int index);
    void rebuildUp(int index);
    void push(Edge *edge);
    Edge *pop();
    void addLastElement(Edge *edge);
    void removeFirstElement();
    void replace(int firstElement, int secondElement);
};


#endif //P2_COMPARABLEHEAP_H
