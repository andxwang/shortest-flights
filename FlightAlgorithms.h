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
        OpenFlights();
        vector<Vertex> BFS(int start);

    private:        
        FlightGraph flightGraph_;
};