/**
 * @file FlightGraph.h
 * @brief Class to represent graph of flights
 */

#pragma once
#include <map>
#include "Vertex.h"
#include "Edge.h"
#include <vector>

using namespace std;

class FlightGraph {
    public:
        map<int, Vertex> airportGraph;
        void insertVertex(vector<string> line);
        void insertEdge(vector<string> line);
};