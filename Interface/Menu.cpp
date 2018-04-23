//
// Created by thamian on 02.05.17.
//

#include "Menu.h"

int Menu::getChoice() {
    return getPositiveNumber(Message::CONSOLE_prompt);
}

std::string Menu::getFilename() {
    return getInput(Message::FILE_getFilename);
}

void Menu::display(ListGraph *listGraph) {
    int numberOfNodes = listGraph->getNumberOfVertices();

    println(Message::LIST_GRAPH_display);
    for (int i = 0; i < numberOfNodes; i++) {
        std::cout << " " << i << " - ";
        for (int j = 0; j < listGraph->getAdjacencyListArray()[i]->getSize(); j++) {
            Node *element = listGraph->getAdjacencyListArray()[i]->getElement(j);
            std::cout << element->getValue() << "[" << element->getWeight() << "], ";
        }
        println();
    }
}

void Menu::display(MatrixGraph *matrixGraph) {
    int numberOfNodes = matrixGraph->getNumberOfVertices();

    println(Message::MATRIX_GRAPH_display);
    print("  # ");
    for (int i = 0; i < numberOfNodes; i++) {
        std::cout << "\t" << i;
    }
    print("\n\n");

    for (int i = 0; i < numberOfNodes; i++) {
        std::cout << "  " << i << " ";
        for (int j = 0; j < numberOfNodes; j++) {
            if (matrixGraph->getEdgeWeight(i, j) == INT32_MAX)
                std::cout << "\t" << "x";
            else
                std::cout << "\t" << matrixGraph->getEdgeWeight(i, j);
        }
        println();
    }
}
