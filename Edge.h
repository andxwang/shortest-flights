/**
 * @file Edge.h
 * @brief Edge class to represent edge between airports (Vertexes) in graph
 */

#pragma once
#include "Vertex.h"

class Edge {
    public:
        Edge(Vertex v1, Vertex v2)
            : source(v1), destn(v2), weight(-1) 
            {};
        
        Edge(Vertex v1, Vertex v2, double w)
            : source(v1), destn(v2), weight(w) 
            {};

    private:
        Vertex source;
        Vertex destn;
        double weight;
};