//
// Created by thamian on 21.05.17.
//

#ifndef P2_ARRAYLIST_H
#define P2_ARRAYLIST_H


class ArrayList {

protected:
    int *array_;
    int size_;

public:
    ArrayList();
    ~ArrayList();

    void addElement(unsigned int index, int value);
    void addFirstElement(int value);
    void addLastElement(int value);

    void removeElement(unsigned int index);
    void removeFirstElement();
    void removeLastElement();

    int* findElement(unsigned int index);

    int* getArray();
};


#endif //P2_ARRAYLIST_H
