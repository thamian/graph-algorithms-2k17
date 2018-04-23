//
// Created by thamian on 02.05.17.
//

#include "MatrixGraph.h"

void MatrixGraph::initialize(std::ifstream &ifstream) {
    int firstVertex;
    int secondVertex;
    int weight;

    adjacencyMatrix_ = new int * [numberOfVertices_];
    for (int i = 0; i < numberOfVertices_; i++) {
        adjacencyMatrix_[i] = new int[numberOfVertices_];
    }

    for (int i = 0; i < numberOfVertices_; i++)
        for (int j = 0; j < numberOfVertices_; ++j)
            adjacencyMatrix_[i][j] = INT32_MAX;

    for (int i = 0; i < numberOfEdges_; i++) {
        ifstream >> firstVertex;
        ifstream >> secondVertex;
        ifstream >> weight;

        adjacencyMatrix_[firstVertex][secondVertex] = weight;
    }
    ifstream.clear();
    ifstream.seekg(0, std::ios::beg);
}

MatrixGraph::~MatrixGraph() {
    for (int i = 0; i < numberOfVertices_; i++) {
        delete [] adjacencyMatrix_[i];
    }
    delete [] adjacencyMatrix_;
}

int MatrixGraph::getEdgeWeight(int firstNode, int lastNode) {
    return adjacencyMatrix_[firstNode][lastNode];
}

MatrixGraph *MatrixGraph::convertToUndirected() {
    MatrixGraph *undirectedGraph = new MatrixGraph();

    undirectedGraph->numberOfEdges_ = numberOfEdges_;
    undirectedGraph->numberOfVertices_ = numberOfVertices_;
    undirectedGraph->firstVertexNumber_ = firstVertexNumber_;
    undirectedGraph->lastVertexNumber_ = lastVertexNumber_;

    undirectedGraph->adjacencyMatrix_ = new int * [numberOfVertices_];
    for (int i = 0; i < numberOfVertices_; i++) {
        undirectedGraph->adjacencyMatrix_[i] = new int[numberOfVertices_];
    }

    for (int i = 0; i < numberOfVertices_; i++) {
        for (int j = 0; j < numberOfVertices_; ++j) {
            undirectedGraph->adjacencyMatrix_[i][j] = adjacencyMatrix_[i][j];
        }
    }

    for (int i = 0; i < numberOfVertices_; ++i) {
        for (int j = 0; j < numberOfVertices_; ++j) {
            if (undirectedGraph->adjacencyMatrix_[i][j] != undirectedGraph->adjacencyMatrix_[j][i]) {
                if (undirectedGraph->adjacencyMatrix_[i][j] > undirectedGraph->adjacencyMatrix_[j][i]) {
                    undirectedGraph->adjacencyMatrix_[i][j] = undirectedGraph->adjacencyMatrix_[j][i];
                }
                else {
                    undirectedGraph->adjacencyMatrix_[j][i] = undirectedGraph->adjacencyMatrix_[i][j];
                }
            }
        }
    }
    return undirectedGraph;
}
