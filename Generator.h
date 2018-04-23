//
// Created by thamian on 25.05.17.
//

#ifndef P2_GENERATOR_H
#define P2_GENERATOR_H


#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

class Generator {
public:
    static void generate(int v_num, float dens, bool directed, int range, int start, int amount);
};


#endif //P2_GENERATOR_H
