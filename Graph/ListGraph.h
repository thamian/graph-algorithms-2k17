//
// Created by thamian on 02.05.17.
//

#ifndef P2_LISTGRAPH_H
#define P2_LISTGRAPH_H


#include <LinkedList.h>
#include "Graph.h"
#include "../Interface/Menu.h"

class ListGraph : public Graph {
    LinkedList **adjacencyListArray_;          // Tablica wskaźników na listy sąsiedztwa.

    void initialize(std::ifstream &ifstream);
public:
    ~ListGraph();

    ListGraph *convertToUndirected();

    LinkedList **getAdjacencyListArray();
    LinkedList *getLinkedList(int vertexNumber);
};


#endif //P2_LISTGRAPH_H
