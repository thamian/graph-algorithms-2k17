//
// Created by thamian on 03.05.17.
//

#ifndef P2_NODE_H
#define P2_NODE_H


class Node {
    friend class LinkedList;
    friend class ListGraph;

    Node *next_;
    int value_;
    int weight_;

    Node(Node *next, int value, int weight);

public:
    Node *getNext();
    int getValue();
    int getWeight();
};


#endif //P2_NODE_H
