//
// Created by thamian on 13.05.17.
//

#ifndef P2_PATHALGORITHM_H
#define P2_PATHALGORITHM_H


#include "Algorithm.h"

class PathAlgorithm : public Algorithm {
protected:
    int *d_;
    int *p_;

    void initialize(Graph *graph);
    void initialize(int *array, int value);
    void displayResults();

public:
    PathAlgorithm();
    ~PathAlgorithm();
};


#endif //P2_PATHALGORITHM_H
