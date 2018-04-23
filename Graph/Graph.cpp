//
// Created by thamian on 11.05.17.
//

#include "Graph.h"

Graph::Graph() {

}

Graph::~Graph() {

}

void Graph::setProperties(std::ifstream &ifstream) {
    ifstream >> numberOfEdges_;
    ifstream >> numberOfVertices_;
    ifstream >> firstVertexNumber_;
    ifstream >> lastVertexNumber_;
}

void Graph::create(std::ifstream &ifstream) {
    setProperties(ifstream);
    initialize(ifstream);
}

int Graph::getNumberOfVertices() const {
    return numberOfVertices_;
}

int Graph::getFirstVertexNumber() const {
    return firstVertexNumber_;
}

int Graph::getNumberOfEdges() const {
    return numberOfEdges_;
}

int Graph::getLastVertexNumber() const {
    return lastVertexNumber_;
}
