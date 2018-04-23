//
// Created by thamian on 13.05.17.
//

#ifndef P2_KRUSKAL_H
#define P2_KRUSKAL_H


#include "Algorithm.h"
#include "../TreeAlgorithm.h"
#include "Subset.h"

class Kruskal : public TreeAlgorithm {
    Subset **subsets_;

public:
    Kruskal();
    ~Kruskal();
    void execute(ListGraph *listGraph);
    void execute(MatrixGraph *matrixGraph);
    int findSubset(int vertexNumber);
    void makeUnion(int x, int y);
};



#endif //P2_KRUSKAL_H
