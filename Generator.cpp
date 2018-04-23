//
// Created by thamian on 25.05.17.
//

#include "Generator.h"

void Generator::generate(int v_num, float dens, bool directed, int range, int start, int amount) {
    srand(time(NULL));
    for (int x = 0; x < amount; x++) {

        std::vector<int> v_in(0);
        std::vector<int> v_out(v_num);
        int** matrix = new int*[v_num];

        for (int i = 0; i < v_num; i++) {
            v_out[i] = i;
            matrix[i] = new int[v_num];
            for (int j = 0; j < v_num; j++)
                matrix[i][j] = 0;
        }

        int v1;
        int v2;
        int value;
        int counter = 0;
        float wanted = (dens / (float) 100) * (float) v_num * (float) v_num;
        int begin = 0;

        v1 = (rand() % v_out.size()) + 0;
        v_in.push_back(v_out[v1]);
        begin = v_out[v1];
        v_out.erase(v_out.begin() + v1);


        while (v_out.size() != 0) {
            v1 = (rand() % v_in.size()) + 0;
            v2 = (rand() % v_out.size()) + 0;
            value = (rand() % range) + start;
            if (directed == false)
            {
                matrix[v_out[v2]][v_in[v1]] = value;
                counter++;
            }
            matrix[v_in[v1]][v_out[v2]] = value;
            counter++;
            v_in.push_back(v_out[v2]);
            v_out.erase(v_out.begin() + v2);

        }
        if (wanted > (v_num * v_num) - v_num)
            wanted = (v_num * v_num) - v_num;
        while (counter < wanted)
        {
            value = (rand() % range) + start;
            v1 = (rand() % v_num) + 0;
            v2 = (rand() % v_num) + 0;

            if (v2 != v1 && matrix[v_in[v1]][v_in[v2]] == 0 && value != 0)
            {
                if (directed == false)
                {
                    matrix[v_in[v2]][v_in[v1]] = value;
                    counter++;
                }
                matrix[v_in[v1]][v_in[v2]] = value;
                counter++;
            }

        }


        std::string file_name = "graph";
        std::string buffer;


        buffer = "grafy/";
        buffer.append(file_name);
        buffer.append(std::to_string(x));
        buffer.append(".txt");
        std::ofstream graph_file;
        graph_file.open(buffer);


        if (directed == true) {
            graph_file << counter << " " << v_num << " " << begin << " " << 0 << "\n";
            for (int i = 0; i < v_num; i++)
                for (int j = 0; j < v_num; j++)
                    if (matrix[i][j] != 0)
                        graph_file << i << " " << j << " " << matrix[i][j] << "\n";
        }
        else {
            int j = 0;
            int k = 0;
            counter = counter / 2;
            graph_file << counter << " " << v_num << " " << begin << " " << 0 << "\n";
            for (int i = 0; i < v_num; i++)
            {
                for (j = 0 + k; j < v_num; j++)
                    if (matrix[i][j] != 0)
                    {
                        graph_file << i << " " << j << " " << matrix[i][j] << "\n";

                    }
                k++;
            }

        }

        graph_file.close();

        for (int i = 0; i < v_num; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
        std::cout << "...\n";
    /*

        std::cout << "Macierz:\n";
        std::cout << "\t[W]";
        for (int i = 0; i < v_num; i++)
            std::cout << "\t[" << i << "] ";
        std::cout << "\n";
        for (int i = 0; i < v_num; i++) {
            std::cout << "\t[" << i << "] ";
            for (int j = 0; j < v_num; j++)
                std::cout << "\t " << matrix[i][j] << " ";
            std::cout << "\n";

        }*/
    }
}
