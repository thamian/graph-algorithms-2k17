//
// Created by thamian on 13.05.17.
//

#include "Prim.h"

void Prim::execute(ListGraph *listGraph) {
    numberOfEdges_ = listGraph->getNumberOfEdges();
    priorityQueue = new EdgeHeap(numberOfEdges_);       // Rozmiar ustalany z góry - optymalizacja.
    numberOfVertices_ = listGraph->getNumberOfVertices();

    visitedVertices_ = new bool [numberOfVertices_];
    for (int i = 0; i < numberOfVertices_; i++) {
        visitedVertices_[i] = false;
    }
    visitedVertices_[0] = true; // Pierwszy wierzchołek, od którego zaczynamy.

    int numberOfAllResultEdges = numberOfVertices_ - 1;

    int currentVertexNumber = 0;
    int destinationVertexNumber;
    Edge *currentEdge;
    Edge **results = new Edge * [numberOfAllResultEdges];
    Node *vertexFromList = listGraph->getLinkedList(currentVertexNumber)->getHead();
    Edge *pushedEdge;
    Edge **pushedEdges = new Edge * [numberOfVertices_ * numberOfVertices_];
    int pushedEdgesPointer = 0;

    for (int i = 0; i < numberOfVertices_ - 1; i++) {
        while (vertexFromList != NULL) {
            priorityQueue->push(new Edge(vertexFromList->getWeight(), currentVertexNumber, vertexFromList->getValue()));
            vertexFromList = vertexFromList->getNext();
        }

        bool success = false;
        while (!success) {
            currentEdge = priorityQueue->pop();

            if (currentVertexNumber == currentEdge->getDestinationVertex()) {
                destinationVertexNumber = currentEdge->getSourceVertex();
            } else {
                destinationVertexNumber = currentEdge->getDestinationVertex();
            }

            if (!visitedVertices_[destinationVertexNumber]) {
                visitedVertices_[destinationVertexNumber] = true;
                currentVertexNumber = destinationVertexNumber;
                success = true;
                results[i] = currentEdge;
            } else {
                delete currentEdge;
            }
        }
        vertexFromList = listGraph->getLinkedList(currentVertexNumber)->getHead();
    }
/*
    int suma = 0;
    for (int k = 0; k < numberOfAllResultEdges; k++) {
        std::cout << "(" << results[k]->getSourceVertex() << ", " << results[k]->getDestinationVertex() << ") W: " << results[k]->getWeight() << "\n";
        suma += results[k]->getWeight();
    }
    std::cout << "MST = " << suma << "\n";
*/
    delete [] results;
    delete priorityQueue;
    delete currentEdge;
    delete [] visitedVertices_;
    delete [] pushedEdges;
}

void Prim::execute(MatrixGraph *matrixGraph) {
    numberOfEdges_ = matrixGraph->getNumberOfEdges();
    priorityQueue = new EdgeHeap(numberOfEdges_);       // Rozmiar ustalany z góry - optymalizacja.
    numberOfVertices_ = matrixGraph->getNumberOfVertices();

    visitedVertices_ = new bool [numberOfVertices_];
    for (int i = 0; i < numberOfVertices_; i++) {
        visitedVertices_[i] = false;
    }
    visitedVertices_[0] = true; // Pierwszy wierzchołek, od którego zaczynamy.

    int numberOfAllResultEdges = numberOfVertices_ - 1;

    int currentVertexNumber = 0;
    int destinationVertexNumber;
    Edge *currentEdge;
    Edge **results = new Edge * [numberOfAllResultEdges];

    for (int i = 0; i < numberOfVertices_ - 1; i++) {
        for (int i = 0; i < numberOfVertices_; i++) {
            if (matrixGraph->adjacencyMatrix_[currentVertexNumber][i] != INT32_MAX) {
                priorityQueue->push(new Edge(matrixGraph->adjacencyMatrix_[currentVertexNumber][i], currentVertexNumber, i));
            }
        }

        bool success = false;
        while (!success) {
            currentEdge = priorityQueue->pop();

            if (currentVertexNumber == currentEdge->getDestinationVertex()) {
                destinationVertexNumber = currentEdge->getSourceVertex();
            } else {
                destinationVertexNumber = currentEdge->getDestinationVertex();
            }

            if (!visitedVertices_[destinationVertexNumber]) {
                visitedVertices_[destinationVertexNumber] = true;
                currentVertexNumber = destinationVertexNumber;
                success = true;
                results[i] = currentEdge;
            } else {
                delete currentEdge;
            }
        }
    }
/*
    int suma = 0;
    for (int k = 0; k < numberOfAllResultEdges; k++) {
        std::cout << "(" << results[k]->getSourceVertex() << ", " << results[k]->getDestinationVertex() << ") W: " << results[k]->getWeight() << "\n";
        suma += results[k]->getWeight();
    }
    std::cout << "MST = " << suma << "\n";
    */
    delete [] results;
    delete [] visitedVertices_;
    delete priorityQueue;
}

Prim::Prim() {

}

Prim::~Prim() {

}
