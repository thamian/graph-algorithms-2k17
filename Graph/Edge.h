//
// Created by thamian on 20.05.17.
//

#ifndef P2_EDGE_H
#define P2_EDGE_H


class Edge {
    int weight_;
    int sourceVertex_;
    int destinationVertex_;

public:
    Edge(int weight_, int sourceVertex, int destinationVertex);
    ~Edge();

    int getWeight();
    int getSourceVertex();
    int getDestinationVertex();

    bool operator <(const Edge &edge);
    bool operator >(const Edge &edge);
};


#endif //P2_EDGE_H
