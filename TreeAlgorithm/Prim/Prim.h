//
// Created by thamian on 13.05.17.
//

#ifndef P2_PRIM_H
#define P2_PRIM_H


#include "Algorithm.h"
#include "../TreeAlgorithm.h"

class Prim : public TreeAlgorithm {
    bool *visitedVertices_;

public:
    void execute(ListGraph *listGraph);
    void execute(MatrixGraph *matrixGraph);
    Prim();
    ~Prim();
};


#endif //P2_PRIM_H
