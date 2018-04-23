//
// Created by thamian on 13.05.17.
//

#include "PathAlgorithm.h"

PathAlgorithm::PathAlgorithm() {

}

void PathAlgorithm::initialize(Graph *graph) {
    numberOfVertices_ = graph->getNumberOfVertices();
    firstVertexNumber_ = graph->getFirstVertexNumber();

    d_ = new int [numberOfVertices_];
    initialize(d_, INT32_MAX);
    d_[firstVertexNumber_] = 0;

    p_ = new int [numberOfVertices_];
    initialize(p_, -1);
}

void PathAlgorithm::initialize(int *array, int value) {
    for (int i = 0; i < numberOfVertices_; i++) {
        array[i] = value;
    }
}

void PathAlgorithm::displayResults() {
    int *stack = new int [numberOfVertices_];
    int stackPointer = 0;

    std::cout << "Start: " << firstVertexNumber_ << "\n\n";
    std::cout << "end\tdist\tpath\n";
    for (int i = 0; i < numberOfVertices_; i++) {

        std::cout << i << "\t";

        for (int j = i; j > -1; j = p_[j]) {
            stack[stackPointer++] = j;
        }

        while (stackPointer) std::cout << stack[--stackPointer] << " ";

        std::cout << "\t" << d_[i] << "\n";
    }

    delete [] stack;
}

PathAlgorithm::~PathAlgorithm() {

}
