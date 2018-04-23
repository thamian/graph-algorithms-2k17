//
// Created by thamian on 11.05.17.
//

#ifndef P2_GRAPH_H
#define P2_GRAPH_H


#include <fstream>
#include "../Interface/File.h"
#include "Edge.h"

class Graph {
protected:
    int numberOfEdges_;
    int numberOfVertices_;
    int firstVertexNumber_;
    int lastVertexNumber_;      // Nieużywany w żadnym z algorytmów.

    void setProperties(std::ifstream &ifstream);
    virtual void initialize(std::ifstream &ifstream) = 0;

public:
    Graph();
    virtual ~Graph();

    void create(std::ifstream &ifstream);

    int getNumberOfEdges() const;
    int getNumberOfVertices() const;
    int getFirstVertexNumber() const;
    int getLastVertexNumber() const;
};


#endif //P2_GRAPH_H
