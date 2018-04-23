//
// Created by thamian on 02.05.17.
//

#ifndef P2_FILE_H
#define P2_FILE_H


#include <fstream>

class File {
    std::ifstream ifstream_;

public:
    std::ifstream &getIfstream();
    void load(std::string path);
    bool isOpen();
};


#endif //P2_FILE_H
