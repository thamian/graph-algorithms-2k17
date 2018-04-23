//
// Created by thamian on 02.05.17.
//

#ifndef P2_CONSOLE_H
#define P2_CONSOLE_H


#include "Message.h"

class Console {
protected:
    int getPositiveNumber();
    int getPositiveNumber(std::string string);
    std::string getInput();
    std::string getInput(std::string string);
    int convert(std::string string);

public:
    void print(std::string string);
    void println();
    void println(std::string string);
};


#endif //P2_CONSOLE_H
