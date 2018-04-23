//
// Created by thamian on 02.05.17.
//

#ifndef P2_MATRIXGRAPH_H
#define P2_MATRIXGRAPH_H


#include "Graph.h"
#include "../Interface/Menu.h"
#include "Edge.h"

class MatrixGraph : public Graph {
public:
    int **adjacencyMatrix_;

    void initialize(std::ifstream &ifstream);

    ~MatrixGraph();

    MatrixGraph *convertToUndirected();

    int getEdgeWeight(int sourceVertex, int destinationVertex);
};


#endif //P2_MATRIXGRAPH_H
