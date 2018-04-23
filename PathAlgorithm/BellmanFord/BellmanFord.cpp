//
// Created by thamian on 13.05.17.
//

#include "BellmanFord.h"

BellmanFord::BellmanFord() {

}

void BellmanFord::execute(ListGraph *listGraph) {
    initialize(listGraph);

    bool test;
    Node *currentAdjacent;
    int adjacentValue;
    int adjacentWeight;

    for (int i = 0; i < numberOfVertices_ - 1; i++) {
        for (int j = 0; j < numberOfVertices_; j++) {
            currentAdjacent = listGraph->getLinkedList(j)->getHead();

            while (currentAdjacent != NULL) {
                adjacentValue = currentAdjacent->getValue();
                adjacentWeight = currentAdjacent->getWeight();

                if (d_[adjacentValue] > d_[j] + adjacentWeight && d_[j] != INT32_MAX) {
                    d_[adjacentValue] = d_[j] + adjacentWeight;
                    p_[adjacentValue] = j;
                }
                currentAdjacent = currentAdjacent->getNext();
            }
        }
    }

    // Sprawdzanie negatywnego cyklu.
    bool negativeCycle = false;
    for (int i = 0; i < numberOfVertices_; i++) {
        currentAdjacent = listGraph->getLinkedList(i)->getHead();

        while (currentAdjacent != NULL) {
            adjacentValue = currentAdjacent->getValue();
            adjacentWeight = currentAdjacent->getWeight();

            if (d_[adjacentValue] > d_[i] + adjacentWeight && d_[i] != INT32_MAX) {
                negativeCycle = true;
            }
            currentAdjacent = currentAdjacent->getNext();
        }
    }
/*
    if (negativeCycle) {
        std::cout << "Znaleziono ujemny cykl!" << "\n";
    } else {
        displayResults();
    }*/
    delete [] d_;
    delete [] p_;
}

void BellmanFord::execute(MatrixGraph *matrixGraph) {
    initialize(matrixGraph);

    bool test;
    Node *currentAdjacent;
    int adjacentValue;
    int adjacentWeight;

    for (int i = 0; i < numberOfVertices_ - 1; i++) {
        for (int j = 0; j < numberOfVertices_; j++) {
            for (int adjacentValue = 0; adjacentValue < numberOfVertices_; adjacentValue++) {
                adjacentWeight = matrixGraph->getEdgeWeight(j, adjacentValue);

                if (d_[adjacentValue] > d_[j] + adjacentWeight && adjacentWeight != INT32_MAX && d_[j] != INT32_MAX) {
                    d_[adjacentValue] = d_[j] + adjacentWeight;
                    p_[adjacentValue] = j;
                }
            }
        }
    }

    // Sprawdzanie negatywnego cyklu.
    bool negativeCycle = false;
    for (int j = 0; j < numberOfVertices_; j++) {
        for (int adjacentValue = 0; adjacentValue < numberOfVertices_; adjacentValue++) {
            adjacentWeight = matrixGraph->getEdgeWeight(j, adjacentValue);

            if (d_[adjacentValue] > d_[j] + adjacentWeight && adjacentWeight != INT32_MAX && d_[j] != INT32_MAX) {
                negativeCycle = true;
            }
        }
    }
/*
    if (negativeCycle) {
        std::cout << "Znaleziono ujemny cykl!" << "\n";
    } else {
        displayResults();
    }*/
    delete [] d_;
    delete [] p_;
}

BellmanFord::~BellmanFord() {

}
