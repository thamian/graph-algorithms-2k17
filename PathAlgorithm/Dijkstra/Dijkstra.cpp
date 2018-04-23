//
// Created by thamian on 13.05.17.
//

#include "Dijkstra.h"

void Dijkstra::execute(ListGraph *listGraph) {
    initialize(listGraph);
    initializeDijkstra(listGraph);

    int currentNode;
    LinkedList *list;
    Node *currentAdjacent;
    int adjacentValue;
    int adjacentWeight;

    for (int i = 0; i < numberOfVertices_; i++) {
        currentNode = priorityQueue_->getFirst();

        checkedNodes_[currentNode] = true;

        list = listGraph->getLinkedList(currentNode);
        currentAdjacent = list->getHead();

        while (currentAdjacent != NULL) {
            adjacentValue = currentAdjacent->getValue();
            adjacentWeight = currentAdjacent->getWeight();

            if (d_[adjacentValue] > d_[currentNode] + adjacentWeight && !checkedNodes_[adjacentValue]) {
                d_[adjacentValue] = d_[currentNode] + adjacentWeight;
                p_[adjacentValue] = currentNode;

                rebuildHeap(indexArray_[adjacentValue]);
            }
            currentAdjacent = currentAdjacent->getNext();
        }
        priorityQueue_->pop();
    }

    //displayResults();

    delete [] d_;
    delete [] p_;
    delete [] indexArray_;
    delete priorityQueue_;
    delete [] checkedNodes_;
}

void Dijkstra::execute(MatrixGraph *matrixGraph) {
    initialize(matrixGraph);
    initializeDijkstra(matrixGraph);

    int currentNode;
    int adjacentWeight;

    for (int i = 0; i < numberOfVertices_; i++) {
        currentNode = priorityQueue_->getFirst();

        checkedNodes_[currentNode] = true;

        for (int adjacentValue = 0; adjacentValue < numberOfVertices_; adjacentValue++) {
            adjacentWeight = matrixGraph->getEdgeWeight(currentNode, adjacentValue);

            if (d_[adjacentValue] > d_[currentNode] + adjacentWeight && !checkedNodes_[adjacentValue] && adjacentWeight != INT32_MAX && d_[currentNode] != INT32_MAX) {
                d_[adjacentValue] = d_[currentNode] + adjacentWeight;
                p_[adjacentValue] = currentNode;

                rebuildHeap(indexArray_[adjacentValue]);
            }
        }
        priorityQueue_->pop();
    }

    //displayResults();

    delete [] d_;
    delete [] p_;
    delete [] indexArray_;
    delete priorityQueue_;
    delete [] checkedNodes_;
}

Dijkstra::Dijkstra() {

}

void Dijkstra::initializeDijkstra(Graph *graph) {
    indexArray_ = new int [numberOfVertices_];
    for (int i = 0; i < numberOfVertices_; i++) {
        indexArray_[i] = i;
    }

    priorityQueue_ = new Heap(graph, indexArray_);
    priorityQueue_->setD(d_);

    checkedNodes_ = new bool [numberOfVertices_];

    for (int i = 0; i < numberOfVertices_; i++) {
        checkedNodes_[i] = false;
    }
}

void Dijkstra::rebuildHeap(int index) {
    priorityQueue_->rebuildDown(index);
    priorityQueue_->rebuildUp(index);
}

Dijkstra::~Dijkstra() {

}
