//
// Created by thamian on 02.05.17.
//

#include "ListGraph.h"

void ListGraph::initialize(std::ifstream &ifstream) {
    int firstVertex;
    int secondVertex;
    int weight;

    adjacencyListArray_ = new LinkedList * [numberOfVertices_];
    for (int i = 0; i < numberOfVertices_; i++) {
        adjacencyListArray_[i] = new LinkedList();
    }

    for (int i = 0; i < numberOfEdges_; i++) {
        ifstream >> firstVertex;
        ifstream >> secondVertex;
        ifstream >> weight;

        adjacencyListArray_[firstVertex]->addElement(secondVertex, weight);
    }
    ifstream.clear();
    ifstream.seekg(0, std::ios::beg);
}

ListGraph::~ListGraph() {
    for (int i = 0; i < numberOfVertices_; i++) {
        delete adjacencyListArray_[i];
    }
    delete [] adjacencyListArray_;
}

LinkedList **ListGraph::getAdjacencyListArray() {
    return adjacencyListArray_;
}

LinkedList *ListGraph::getLinkedList(int vertexNumber) {
    return adjacencyListArray_[vertexNumber];
}

ListGraph *ListGraph::convertToUndirected() {
    ListGraph *undirectedGraph = new ListGraph();

    undirectedGraph->numberOfEdges_ = numberOfEdges_;
    undirectedGraph->numberOfVertices_ = numberOfVertices_;
    undirectedGraph->firstVertexNumber_ = firstVertexNumber_;
    undirectedGraph->lastVertexNumber_ = lastVertexNumber_;

    LinkedList **adjacencyListArray = new LinkedList * [numberOfVertices_];

    undirectedGraph->adjacencyListArray_ = adjacencyListArray;
    for (int i = 0; i < numberOfVertices_; i++) {
        adjacencyListArray[i] = new LinkedList();
    }

    int firstVertex;
    int secondVertex;
    int weight;
    Node *vertexFromList;
    for (int i = 0; i < numberOfVertices_; i++) {
        vertexFromList = adjacencyListArray_[i]->head_;
        while (vertexFromList != NULL) {
            adjacencyListArray[i]->addElement(vertexFromList->value_, vertexFromList->weight_);
            vertexFromList = vertexFromList->getNext();
        }
    }

    // koniec kopiowania grafu

    for (int j = 0; j < numberOfVertices_; j++) {
        vertexFromList = adjacencyListArray[j]->head_;
        while (vertexFromList != NULL) {
            if (!adjacencyListArray[vertexFromList->value_]->isExist(j)) {
                adjacencyListArray[vertexFromList->value_]->addElement(j, vertexFromList->weight_);
            }
            /*else if (vertexFromList->weight_ != adjacencyListArray[vertexFromList->value_]->findElement(j)->weight_) {
                adjacencyListArray[vertexFromList->value_]->findElement(j)->weight_ = vertexFromList->weight_;
            }*/
            vertexFromList = vertexFromList->getNext();
        }
    }

    return undirectedGraph;
}
