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


using namespace std;

class FlightGraph {
    public:
        map<int, Vertex> airportGraph;
        void insertVertex(vector<string> line);
        void insertEdge(vector<string> line);
        void loadAirports();
        void loadFlights();
        double calculateDistance(int sourceID, int destnID);
    private:
};