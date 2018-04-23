//
// Created by thamian on 13.05.17.
//

#ifndef P2_TREEALGORITHM_H
#define P2_TREEALGORITHM_H


#include <EdgeHeap.h>
#include "Algorithm.h"

class TreeAlgorithm : public Algorithm {
protected:
    EdgeHeap *priorityQueue;

public:
    TreeAlgorithm();
    ~TreeAlgorithm();
};


#endif //P2_TREEALGORITHM_H
