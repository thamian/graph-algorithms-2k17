//
// Created by thamian on 10.05.17.
//

#ifndef P2_MESSAGE_H
#define P2_MESSAGE_H


#include <iostream>

class Message {
public:
    static const std::string CONSOLE_prompt;
    static const std::string MENU_description;
    static const std::string MENU_information;
    static const std::string MENU_wrongInput;
    static const std::string FILE_getFilename;
    static const std::string FILE_loadSuccess;
    static const std::string FILE_loadFailure;
    static const std::string GRAPH_created;
    static const std::string GRAPH_notExist;
    static const std::string LIST_GRAPH_display;
    static const std::string MATRIX_GRAPH_display;
};


#endif //P2_MESSAGE_H
