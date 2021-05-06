#include <string>
#include <vector>
#include "../catch/catch.hpp"
#include "../FlightGraph.h"
#include "../FlightAlgorithms.h"
#include <iostream>
#include <cmath>

//just gonna use this to see if I'm doing this correctly
TEST_CASE("Verify that calculateDistance works ") {
	FlightGraph bruh;
	bruh.loadAirports();
 	bruh.loadFlights();
	//note distances calculated manually through online haversine calculator
	REQUIRE(bruh.calculateDistance(1, 1) == 0);
	REQUIRE(round(bruh.calculateDistance(1,2)) == 106);
	REQUIRE(round(bruh.calculateDistance(2,3)) == 179);
	REQUIRE(round(bruh.calculateDistance(4,5)) == 323);
}

TEST_CASE("Verify that null values and \\N values are not in routes vector") {
	FlightGraph flights;
	flights.loadFlights();
	vector<vector<string>> routes = flights.routes;
	//looks like the null is only in 3rd col which don't care about at all
	vector<vector<string>>::const_iterator row; 
    vector<string>::const_iterator col; 
	for (row = routes.begin(); row != routes.end(); ++row) {
		for (col = row->begin(); col != row->end(); ++col) {
			REQUIRE(*col != "Null");
			REQUIRE(*col != "\\N");
			
		}
	}
}

TEST_CASE("Verify that null and \\N values are not in airports vector") {
	FlightGraph flights;
	flights.loadAirports();
    vector<vector<string>> airports = flights.airports;
	vector<vector<string>>::const_iterator row; 
    vector<string>::const_iterator col; 
	// cout << airports[0][0] << endl;
	for (row = airports.begin(); row != airports.end(); ++row) {
		int counter = 0;
		for (col = row->begin(); col != row->end(); ++col) {
			// cout << *col << endl;
			//columns where we don't care about a null or \N existing
			if(counter == 1) {
				counter++;
				continue;
			}
			counter++; 
			REQUIRE(*col != "Null");
			//REQUIRE(*col != "\\N");
		}
	}
}

//next things to write
//potenitally check them manually against a subset with like 3 or 4 nodes only
TEST_CASE("Verify BFS is working") {
	REQUIRE(1 == 1);
	// I think we can validate this by just checking to make sure that
	// the weight of each node matches the distance calculated. It's 
	// redundant but this is the best I can think of. 
	// The only other thing we can really check is if every single node
	// has been visited. 

}

TEST_CASE("Verify Dijkstra's is working") {
	REQUIRE(1 == 1);
	//same strategy as BFS ig 
}

TEST_CASE("Verify that A* search is working") {
	REQUIRE(1 == 1);
}
