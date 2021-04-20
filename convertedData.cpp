#include "convertedData.h"
#include "fileToVector.cpp"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// load the airports into a vector. 
// Not really sure what the output of file_to_vector is?
void Flight::loadAirports() {
    string airportsFile = "data/airports.dat";

    vector<string> line = file_to_vector(airportsFile);
    // insert Vertex using line
}

void Flight::loadFlights() {
    string flightsFile = "data/routes.dat";
    ifstream infile(flightsFile.c_str());

    vector<string> line = file_to_vector(flightsFile);
}