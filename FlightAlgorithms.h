/**
 * @file FlightAlgorithms.h
 * @brief Class to represent graph of flights
 */

#pragma once
#include "FlightGraph.h"
#include "Vertex.h"
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

class FlightAlgorithms {
    public:
        FlightAlgorithms();
        vector<int> BFS(int start);
        vector<int> dijkstra(int start, int dest);
        vector<int> A_star(int start, int dest);
    private:        
        FlightGraph flightGraph_;
        
};