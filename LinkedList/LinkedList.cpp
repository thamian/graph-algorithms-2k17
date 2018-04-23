//
// Created by thamian on 03.05.17.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    head_ = NULL;
    size_ = 0;
}

LinkedList::~LinkedList() {
    Node *currentElement = head_;
    Node *nextElement;

    for (int i = 0; i < size_; i++) {
        nextElement = currentElement->next_;
        delete currentElement;
        currentElement = nextElement;
    }
}

Node *LinkedList::findElement(int value) {
    Node *currentElement = head_;

    for (int i = 1; i < size_; i++) {
        if (currentElement->value_ == value) {
            return currentElement;
        }
        currentElement = currentElement->next_;
    }
    return NULL;
}

void LinkedList::addElement(int value, int weight) {
    Node* newElement;
    Node* next = NULL;

    if (!size_) {
        newElement = new Node(next, value, weight);
        head_ = newElement;
        size_++;
        return;
    }
    else {
        Node *lastElement = getLastElement();
        newElement = new Node(next, value, weight);
        lastElement->next_ = newElement;
        size_++;
    }
}

void LinkedList::removeElement() {

    if (!size_)
        return;

    if (size_ == 1) {
        delete head_;
        head_ = NULL;
        return;
    }

    /*else {
        Node *next;

        Node *currentElement = findElement(index);

        previous = currentElement->getPrevious();
        next = currentElement->getNext();

        next->setPrevious(previous);

        delete currentElement;

        size_--;
    }*/
}

Node *LinkedList::getLastElement() {
    Node *currentElement = head_;

    for (int i = 1; i < size_; i++) {
        currentElement = currentElement->next_;
    }
    return currentElement;
}

int LinkedList::getSize() {
    return size_;
}

Node *LinkedList::getElement(int index) {
    Node *currentElement = head_;

    for (int i = 1; i <= index; i++) {
        currentElement = currentElement->next_;
    }
    return currentElement;
}

Node *LinkedList::getHead() {
    return head_;
}

bool LinkedList::isExist(int value) {
    Node *currentElement = head_;

    while (currentElement != NULL) {
        if (currentElement->value_ == value) return true;
        currentElement = currentElement->next_;
    }
    return false;
}
