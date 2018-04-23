//
// Created by thamian on 21.05.17.
//

#include <cstdlib>
#include "ArrayList.h"

ArrayList::ArrayList() {
    array_ = NULL;
    size_ = 0;
}

ArrayList::~ArrayList() {
    delete [] array_;
}

int* ArrayList::findElement(unsigned int index) {

    int *currentElement = &array_[index];

    if (index >= size_)
        currentElement = NULL;

    return currentElement;
}

int* ArrayList::getArray() {
    return array_;
}

void ArrayList::addElement(unsigned int index, int value) {

    if (!index) {
        addFirstElement(value);
        return;
    }

    if (index >= size_) {
        addLastElement(value);
        return;
    }

    else {

        int newSize = size_ + 1;
        int *newArray = new int[newSize];

        for (int i = 0; i < index; i++) {

            newArray[i] = array_[i];
        }

        newArray[index] = value;

        for (int i = index + 1; i < newSize; i++) {

            newArray[i] = array_[i - 1];
        }

        delete [] array_;
        array_ = newArray;
        size_++;
    }
}

void ArrayList::addFirstElement(int value) {

    int newSize = size_ + 1;
    int *newArray = new int[newSize];

    newArray[0] = value;

    for (int i = 1; i < newSize; i++) {

        newArray[i] = array_[i - 1];
    }

    delete [] array_;
    array_ = newArray;
    size_++;
}

void ArrayList::addLastElement(int value) {

    int newSize = size_ + 1;
    int *newArray = new int[newSize];

    for (int i = 0; i < size_; i++) {

        newArray[i] = array_[i];
    }

    newArray[size_] = value;

    delete [] array_;
    array_ = newArray;
    size_++;
}

void ArrayList::removeElement(unsigned int index) {

    if (!size_)
        return;

    int newSize = size_ - 1;
    int *newArray = new int[newSize];

    if (!newSize) {                                         // gdy nowy rozmiar ma być 0
        delete [] array_;
        array_ = NULL;
        size_--;
        return;
    }

    if (!index) {
        removeFirstElement();
        return;
    }

    if (index >= size_) {
        removeLastElement();
        return;
    }

    else {
        for (int i = 0; i < index; i++) {
            newArray[i] = array_[i];
        }

        for (int i = index; i < newSize; i++) {
            newArray[i] = array_[i + 1];
        }

        delete [] array_;
        array_ = newArray;
        size_--;
    }
}

void ArrayList::removeFirstElement() {

    if (!size_)
        return;

    int newSize = size_ - 1;
    int *newArray = new int[newSize];

    if (!newSize) {                                         // gdy nowy rozmiar ma być 0

        delete [] array_;
        array_ = NULL;
        size_--;
        return;
    }

    for (int i = 0; i < newSize; i++) {
        newArray[i] = array_[i + 1];
    }

    delete [] array_;
    array_ = newArray;
    size_--;
}

void ArrayList::removeLastElement() {

    if (!size_)
        return;

    int newSize = size_ - 1;
    int *newArray = new int[newSize];

    if (!newSize) {                                         // gdy nowy rozmiar ma być 0

        delete [] array_;
        array_ = NULL;
        size_--;
        return;
    }

    for (int i = 0; i < newSize; i++) {

        newArray[i] = array_[i];
    }

    delete [] array_;
    array_ = newArray;
    size_--;
}
