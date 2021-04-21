/**
 * @file Edge.h
 * @brief Edge class to represent edge between airports (Vertexes) in graph
 */

#pragma once
#include "Vertex.h"

class Edge {
    public:
        Edge(int s, int d, double w)
            : source(s), destn(d), weight(w) 
            {};
        
        void setWeight(double w) {
            weight = w;
        }

        double getWeight() {
            return weight;
        }

    private:
        int source; // ID of source airport
        int destn; // ID of destination airport
        double weight; // distance between source airport and destination airport
};