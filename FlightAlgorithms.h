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
        vector<string> BFS(string start_code);
        vector<string> dijkstra(string start_code, string dest_code);
        vector<string> A_star(string start_code, string dest_code);
    private:        
        FlightGraph flightGraph_;
        
};