//
// Created by thamian on 03.05.17.
//

#include <unistd.h>
#include "Controller.h"
#include "../Generator.h"

Controller::Controller() {
    listGraph_ = NULL;
    matrixGraph_ = NULL;

    kruskal_ = new Kruskal();
    prim_ = new Prim();
    dijkstra_= new Dijkstra();
    bellmanFord_ = new BellmanFord();
}

Controller::~Controller() {
    delete listGraph_;
    delete matrixGraph_;

    delete kruskal_;
    delete prim_;
    delete dijkstra_;
    delete bellmanFord_;

    delete undirectedMatrix;
    delete undirectedList;
}

void Controller::start() {
    menu_.println(Message::MENU_information);
    menu_.println();
    menu_.println(Message::MENU_description);

    bool exit = false;
    while (!exit) {
        switch (menu_.getChoice()) {
            case 0: {                   // Lista dostępnych opcji.
                menu_.println(Message::MENU_description);
            } break;
            case 1: {                   // Wczytanie grafu z pliku.
                loadFile();
            } break;
            case 2: {                   // Wyświetlenie grafu.
                displayGraph();
            } break;
            case 3: {                   // Algorytm Kruskala.
                std::chrono::high_resolution_clock::time_point startTime;
                std::chrono::high_resolution_clock::time_point stopTime;
                std::chrono::duration<double> spanTime;

                startTime = std::chrono::high_resolution_clock::now();
                kruskal_->execute(undirectedList);
                stopTime = std::chrono::high_resolution_clock::now();
                spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
                std::cout << spanTime.count() << std::endl;

                startTime = std::chrono::high_resolution_clock::now();
                kruskal_->execute(undirectedMatrix);
                stopTime = std::chrono::high_resolution_clock::now();
                spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
                std::cout << spanTime.count() << std::endl;
            } break;
            case 4: {                   // Algorytm Prima.
                std::chrono::high_resolution_clock::time_point startTime;
                std::chrono::high_resolution_clock::time_point stopTime;
                std::chrono::duration<double> spanTime;

                startTime = std::chrono::high_resolution_clock::now();
                prim_->execute(undirectedList);
                stopTime = std::chrono::high_resolution_clock::now();
                spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
                std::cout << spanTime.count() << std::endl;

                startTime = std::chrono::high_resolution_clock::now();
                prim_->execute(undirectedMatrix);
                stopTime = std::chrono::high_resolution_clock::now();
                spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
                std::cout << spanTime.count() << std::endl;
            } break;
            case 5: {                   // Algorytm Dijkstry.
                std::chrono::high_resolution_clock::time_point startTime;
                std::chrono::high_resolution_clock::time_point stopTime;
                std::chrono::duration<double> spanTime;

                startTime = std::chrono::high_resolution_clock::now();
                dijkstra_->execute(listGraph_);
                stopTime = std::chrono::high_resolution_clock::now();
                spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
                std::cout << spanTime.count() << std::endl;

                startTime = std::chrono::high_resolution_clock::now();
                dijkstra_->execute(matrixGraph_);
                stopTime = std::chrono::high_resolution_clock::now();
                spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
                std::cout << spanTime.count() << std::endl;
            } break;
            case 6: {                   // Algorytm Bellmana-Forda.
                std::chrono::high_resolution_clock::time_point startTime;
                std::chrono::high_resolution_clock::time_point stopTime;
                std::chrono::duration<double> spanTime;

                startTime = std::chrono::high_resolution_clock::now();
                bellmanFord_->execute(listGraph_);
                stopTime = std::chrono::high_resolution_clock::now();
                spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
                std::cout << spanTime.count() << std::endl;

                startTime = std::chrono::high_resolution_clock::now();
                bellmanFord_->execute(matrixGraph_);
                stopTime = std::chrono::high_resolution_clock::now();
                spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
                std::cout << spanTime.count() << std::endl;
            } break;
            case 7: {                   // Wyjście.
                exit = true;
            } break;
            default: {                  // Nierozpoznane polecenie.
                menu_.println(Message::MENU_wrongInput);
            } break;
        }
    }
}

void Controller::loadFile() {
    file_.load(menu_.getFilename());

    if (file_.isOpen()) {
        menu_.println(Message::FILE_loadSuccess);
        loadGraph();
    }
    else menu_.println(Message::FILE_loadFailure);
}

void Controller::loadGraph() {
    delete listGraph_;
    listGraph_ = new ListGraph();
    listGraph_->create(file_.getIfstream());

    delete matrixGraph_;
    matrixGraph_ = new MatrixGraph();
    matrixGraph_->create(file_.getIfstream());

    delete undirectedList;
    delete undirectedMatrix;

    undirectedList = listGraph_->convertToUndirected();
    undirectedMatrix = matrixGraph_->convertToUndirected();

    menu_.println(Message::GRAPH_created);
}

void Controller::displayGraph() {
    if (listGraph_ == NULL || matrixGraph_ == NULL)
        menu_.println(Message::GRAPH_notExist);
    else {
        menu_.display(listGraph_);
        menu_.display(matrixGraph_);
        menu_.println("Grafy nieskierowane:\n");
        menu_.display(undirectedList);
        menu_.display(undirectedMatrix);
    }
}

void Controller::testSalesman() {
    menu_.println("path");

    std::ofstream dijkstraList;
    std::ofstream dijkstraMatrix;
    std::ofstream bellmanList;
    std::ofstream bellmanMatrix;

    dijkstraList.open("dijkstraList.txt");
    dijkstraMatrix.open("dijkstraMatrix.txt");
    bellmanList.open("bellmanList.txt");
    bellmanMatrix.open("bellmanMatrix.txt");

    double rDijkstraList[10];
    double rDijkstraMatrix[10];
    double rBellmanList[10];
    double rBellmanMatrix[10];

    for (int i = 0; i < 100; i++) {
        Generator::generate(600, 25.0, true, 5000, 0, 1);   // Graf skierowany.
        loadFile("grafy/graph0.txt");

        std::chrono::high_resolution_clock::time_point startTime;
        std::chrono::high_resolution_clock::time_point stopTime;
        std::chrono::duration<double> spanTime;

        for (int j = 0; j < 10; j++) {
            startTime = std::chrono::high_resolution_clock::now();
                dijkstra_->execute(listGraph_);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rDijkstraList[j] = spanTime.count();

            startTime = std::chrono::high_resolution_clock::now();
                dijkstra_->execute(matrixGraph_);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rDijkstraMatrix[j] = spanTime.count();


            startTime = std::chrono::high_resolution_clock::now();
                bellmanFord_->execute(listGraph_);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rBellmanList[j] = spanTime.count();

            startTime = std::chrono::high_resolution_clock::now();
                bellmanFord_->execute(matrixGraph_);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rBellmanMatrix[j] = spanTime.count();
        }

        double averageDijkstraList = 0;
        for (int k = 0; k < 10; ++k) {
            averageDijkstraList += rDijkstraList[k];
            averageDijkstraList = averageDijkstraList / 10;
        }

        double averageDijkstraMatrix = 0;
        for (int l = 0; l < 10; ++l) {
            averageDijkstraMatrix += rDijkstraMatrix[l];
            averageDijkstraMatrix = averageDijkstraMatrix / 10;
        }

        double averageBellmanList = 0;
        for (int m = 0; m < 10; ++m) {
            averageBellmanList += rBellmanList[m];
            averageBellmanList = averageBellmanList / 10;
        }

        double averageBellmanMatrix = 0;
        for (int n = 0; n < 10; ++n) {
            averageBellmanMatrix += rBellmanMatrix[n];
            averageBellmanMatrix = averageBellmanMatrix / 10;
        }

        dijkstraList << averageDijkstraList << ";\n";
        dijkstraMatrix << averageDijkstraMatrix << ";\n";
        bellmanList << averageBellmanList << ";\n";
        bellmanMatrix << averageBellmanMatrix << ";\n";
    }

    dijkstraList.close();
    dijkstraMatrix.close();
    bellmanList.close();
    bellmanMatrix.close();
}

void Controller::loadFile(std::string filename) {
    file_.load(filename);

    if (file_.isOpen()) {
        menu_.println(Message::FILE_loadSuccess);
        loadGraph();
    }
    else menu_.println(Message::FILE_loadFailure);
}

void Controller::testTree() {
    menu_.println("tree");

    std::ofstream primList;
    std::ofstream primMatrix;
    std::ofstream kruskalList;
    std::ofstream kruskalMatrix;

    primList.open("primList.txt");
    primMatrix.open("primMatrix.txt");
    kruskalList.open("kruskalList.txt");
    kruskalMatrix.open("kruskalMatrix.txt");

    double rPrimList[10];
    double rPrimMatrix[10];
    double rKruskalList[10];
    double rKruskalMatrix[10];

    for (int i = 0; i < 100; i++) {
        Generator::generate(600, 25.0, false, 5000, 0, 1);   // Graf nieskierowany.
        loadFile("grafy/graph0.txt");

        std::chrono::high_resolution_clock::time_point startTime;
        std::chrono::high_resolution_clock::time_point stopTime;
        std::chrono::duration<double> spanTime;

        for (int j = 0; j < 10; j++) {
            startTime = std::chrono::high_resolution_clock::now();
                prim_->execute(undirectedList);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rPrimList[j] = spanTime.count();

            startTime = std::chrono::high_resolution_clock::now();
                prim_->execute(undirectedMatrix);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rPrimMatrix[j] = spanTime.count();


            startTime = std::chrono::high_resolution_clock::now();
                kruskal_->execute(undirectedList);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rKruskalList[j] = spanTime.count();

            startTime = std::chrono::high_resolution_clock::now();
                kruskal_->execute(undirectedMatrix);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rKruskalMatrix[j] = spanTime.count();
        }

        double averagePrimList = 0;
        for (int k = 0; k < 10; ++k) {
            averagePrimList += rPrimList[k];
            averagePrimList = averagePrimList / 10;
        }

        double averagePrimMatrix = 0;
        for (int l = 0; l < 10; ++l) {
            averagePrimMatrix += rPrimMatrix[l];
            averagePrimMatrix = averagePrimMatrix / 10;
        }

        double averageKruskalList = 0;
        for (int m = 0; m < 10; ++m) {
            averageKruskalList += rKruskalList[m];
            averageKruskalList = averageKruskalList / 10;
        }

        double averageKruskalMatrix = 0;
        for (int n = 0; n < 10; ++n) {
            averageKruskalMatrix += rKruskalMatrix[n];
            averageKruskalMatrix = averageKruskalMatrix / 10;
        }

        primList << averagePrimList << ";\n";
        primMatrix << averagePrimMatrix << ";\n";
        kruskalList << averageKruskalList << ";\n";
        kruskalMatrix << averageKruskalMatrix << ";\n";
    }

    primList.close();
    primMatrix.close();
    kruskalList.close();
    kruskalMatrix.close();
}
