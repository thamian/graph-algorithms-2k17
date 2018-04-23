//
// Created by thamian on 02.05.17.
//

#ifndef P2_MENU_H
#define P2_MENU_H


class ListGraph;
class MatrixGraph;

#include "Console.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

class Menu : public Console {
public:
    int getChoice();
    std::string getFilename();
    void display(ListGraph *listGraph);
    void display(MatrixGraph *matrixGraph);
};


#endif //P2_MENU_H
