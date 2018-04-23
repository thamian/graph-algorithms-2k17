//
// Created by thamian on 03.05.17.
//

#ifndef P2_CONTROLLER_H
#define P2_CONTROLLER_H


#include "../Interface/Menu.h"
#include "../Interface/File.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "../PathAlgorithm/BellmanFord/BellmanFord.h"
#include "../PathAlgorithm/Dijkstra/Dijkstra.h"
#include "../TreeAlgorithm/Kruskal/Kruskal.h"
#include "../TreeAlgorithm/Prim/Prim.h"
#include "../PathAlgorithm/PathAlgorithm.h"
#include <chrono>

class Controller {
    Menu menu_;
    File file_;

    ListGraph *listGraph_;
    MatrixGraph *matrixGraph_;

    ListGraph *undirectedList;
    MatrixGraph *undirectedMatrix;

    Kruskal *kruskal_;
    Prim *prim_;
    Dijkstra *dijkstra_;
    BellmanFord *bellmanFord_;

    void loadFile();
    void loadFile(std::string filename);
    void loadGraph();
    void displayGraph();

public:
    Controller();
    ~Controller();

    void start();
    void testSalesman();
    void testTree();
    void test();
};


#endif //P2_CONTROLLER_H
