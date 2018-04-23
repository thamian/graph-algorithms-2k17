//
// Created by thamian on 02.05.17.
//

#include "File.h"

std::ifstream &File::getIfstream() {
    return ifstream_;
}

void File::load(std::string path) {
    ifstream_.close();
    ifstream_.open(path);
}

bool File::isOpen() {
    return (bool) ifstream_;
}
