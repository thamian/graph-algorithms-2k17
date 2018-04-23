//
// Created by thamian on 13.05.17.
//

#ifndef P2_DIJKSTRA_H
#define P2_DIJKSTRA_H


#include <Heap.h>
#include "Algorithm.h"
#include "../PathAlgorithm.h"

class Dijkstra : public PathAlgorithm {
    int *indexArray_;
    Heap *priorityQueue_;
    bool *checkedNodes_;

    void initializeDijkstra(Graph *graph);
    void rebuildHeap(int index);
public:
    Dijkstra();
    ~Dijkstra();
    void execute(ListGraph *listGraph);
    void execute(MatrixGraph *matrixGraph);
};


#endif //P2_DIJKSTRA_H
