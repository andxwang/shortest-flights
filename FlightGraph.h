/**
 * @file FlightGraph.h
 * @brief Class to represent graph of flights
 */

#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

class FlightGraph {
    public:
        vector<vector<string>> routes;
        vector<vector<string>> airports;
        map<int, Vertex> airportGraph; // maps id to Vertex (airport)
        map<string, int> code_to_id; // maps 3-letter airport code to its id
        void insertVertex(vector<string> line);
        void insertEdge(vector<string> line);
        void loadAirports();
        void loadFlights();
        double calculateDistance(int sourceID, int destnID);
    private:
};