#include "FlightAlgorithms.h"

using namespace std;

//  Constructor
FlightAlgorithms::FlightAlgorithms() {
    //  copy files to private members
    flightGraph_.loadAirports();
    flightGraph_.loadFlights();
}

/*
Note: lines 40-42 likely have issues because of the iterator type. Need to fix.
If you want to start writing test cases comment out the while loop and then 
your tests should work- at least for the other functions.
Like ik the case for calculateDistance is working now.
*/

// BFS to traverse from a start point (airport id), returns a vector or vertices
vector<Vertex> FlightAlgorithms::BFS(int start) {
    // Create visited vector, set all values to false, 14110 is ID of last airport
    // vector<bool> visited(14110, false);   

    // USE THIS IF ABOVE DOESN'T WORK
    vector<bool> visited(14110); 
    for (unsigned i = 0; i < 14110; i++) {
        visited[i] = false;
    }

    vector<Vertex> result;      // Vector of all visited airports in order
    queue<int> airportQueue;    // queue for BFS
    airportQueue.push(start);   // enqueue first airport
    visited[start] = true;      // Set starting airport to visited

    //  BFS
    while (!airportQueue.empty()) {
        int curr = airportQueue.front();
        result.push_back(flightGraph_.airportGraph[curr]); // add current airport to result
        airportQueue.pop();
        for (auto i = flightGraph_.airportGraph[curr].airports.begin(); i != flightGraph_.airportGraph[curr].airports.end(); ++i) {    //  search all departures from current airport
            if (visited[i] == false) {  //  next airport has not been visited
                airportQueue.push(i);   //  enqueue next airport
                visited[i] = true;
            }
        }
    }

    return result;
}


