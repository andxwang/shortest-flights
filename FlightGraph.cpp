#include "FlightGraph.h"

// insert Vertex into airportGraph
void FlightGraph::insertVertex(vector<string> line) {
    // line consists of:
    // [ID, city, country, iata-code, lat, lon]
    Vertex airport;
    airport.id = atoi(line[0].c_str()); //atoi converts string to int
    airport.city = line[1];
    airport.country = line[2];
    airport.code = line[3];
    airport.latitude = atof(line[4].c_str());
    airport.longitude = atof(line[5].c_str()); //atof converts string to float

    airportGraph.insert(pair<int, Vertex>(airport.id, airport));
}

// load the airports into a vector, 
// to be passed into insertVertex 
void FlightGraph::loadAirports() {
    ifstream airportsfile("data/airports.dat");
    string line;
    stringstream ss(line);
    char delim = ',';

    while (getline(airportsfile, line)) {
        vector<string> v; // vector represents one line read in
        //parse file
        stringstream ss(line);
        string ID, name, city, country, iata, icao, lat, lon;
        getline(ss, ID, delim);
        getline(ss, name, delim);
        getline(ss, city, delim);
        getline(ss, country, delim);
        getline(ss, iata, delim);
        getline(ss, icao, delim);
        getline(ss, lat, delim);
        getline(ss, lon, delim);

        v.push_back(ID);
        v.push_back(city);
        v.push_back(country);
        // if the IATA code is \N, then use the ICAO code
        if (iata.compare("\\N") == 0) {
            v.push_back(icao);
        }
        else {
            v.push_back(iata);
        }
        v.push_back(lat);
        v.push_back(lon);
        
        // testing printing
        // cout << "PRINTING VECTOR" << endl;
        // for (auto e : v) {
        //     cout << e << endl;
        // }


        // add to vector to track airports
        airports.push_back(v);

        // insert Vertex using vector
        insertVertex(v);
    }
}

// insert Edge into airportGraph
void FlightGraph::insertEdge(vector<string> line) {
    // line consists of:
    // [source_ID, destn_ID]
    int source_ID = atoi(line[0].c_str());
    int destn_ID = atoi(line[1].c_str());
    double weight = calculateDistance(source_ID, destn_ID);
    Edge flight(source_ID, destn_ID, weight);
    // if edge doesn't already exist, add to airports
    if (airportGraph[source_ID].airports.find(destn_ID) == airportGraph[source_ID].airports.end()) {
        airportGraph[source_ID].airports.insert(pair<int, Edge>(destn_ID, flight));
    }
}

// load the routes/flights into a vector, 
// to be passed into insertEdge
void FlightGraph::loadFlights() {
    ifstream flightsfile("data/routes.dat");
    string line;
    stringstream ss(line);
    char delim = ',';

    while(getline(flightsfile, line)) {
        vector<string> v;
        stringstream ss(line);
        string airline, airlineID, source_code, source_ID, destn_code, destn_ID;
        getline(ss, airline, delim);
        getline(ss, airlineID, delim);
        getline(ss, source_code, delim);
        getline(ss, source_ID, delim); // OpenFlights ID #
        getline(ss, destn_code, delim);
        getline(ss, destn_ID, delim); // OpenFlights ID #

        v.push_back(source_ID);
        v.push_back(destn_ID);
        // add to vector to track routes
        routes.push_back(v);

        insertEdge(v);
    }
}

double FlightGraph::calculateDistance(int source, int destn) {
    // use airportGraph[source] and airportGraph[dest]
}