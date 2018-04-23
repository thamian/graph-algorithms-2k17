//
// Created by thamian on 03.05.17.
//

#ifndef P2_LINKEDLIST_H
#define P2_LINKEDLIST_H


#include <cstdlib>
#include "Node.h"

class LinkedList {
    friend class ListGraph;

    Node* head_;
    int size_;

public:
    LinkedList();
    ~LinkedList();
    void addElement(int value, int weight);
    void removeElement();
    Node *findElement(int value);
    bool isExist(int value);
    Node *getLastElement();
    int getSize();
    Node *getElement(int index);
    Node *getHead();
};


#endif //P2_LINKEDLIST_H
