//
// Created by thamian on 03.05.17.
//

#include "Node.h"

Node::Node(Node *next, int value, int weight) {
    next_ = next;
    value_ = value;
    weight_ = weight;
}

Node *Node::getNext() {
    return next_;
}

int Node::getValue() {
    return value_;
}

int Node::getWeight() {
    return weight_;
}
