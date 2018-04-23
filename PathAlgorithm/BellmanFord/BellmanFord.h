//
// Created by thamian on 13.05.17.
//

#ifndef P2_BELLMANFORD_H
#define P2_BELLMANFORD_H


#include "Algorithm.h"
#include "../PathAlgorithm.h"

class BellmanFord : public PathAlgorithm {
public:
    BellmanFord();
    ~BellmanFord();
    void execute(ListGraph *listGraph);
    void execute(MatrixGraph *matrixGraph);
};


#endif //P2_BELLMANFORD_H
