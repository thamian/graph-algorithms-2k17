//
// Created by thamian on 20.05.17.
//

#include "Edge.h"

Edge::Edge(int weight, int sourceVertex, int destinationVertex) {
    weight_ = weight;
    sourceVertex_ = sourceVertex;
    destinationVertex_ = destinationVertex;
}

Edge::~Edge() {

}

int Edge::getWeight() {
    return weight_;
}

int Edge::getSourceVertex() {
    return sourceVertex_;
}

int Edge::getDestinationVertex() {
    return destinationVertex_;
}

bool Edge::operator <(const Edge &edge) {
    return this->weight_ < edge.weight_;
}

bool Edge::operator >(const Edge &edge) {
    return this->weight_ > edge.weight_;
}
