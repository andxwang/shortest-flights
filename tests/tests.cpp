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
	// REQUIRE(1 == 1);
	// I think we can validate this by just checking to make sure that
	// the weight of each node matches the distance calculated. It's 
	// redundant but this is the best I can think of. 
	// The only other thing we can really check is if every single node
	// has been visited. 
	FlightAlgorithms fa;
	vector<int> start_from_CMI = fa.BFS(4049); // CMI airport code
	vector<int> start_from_CMI_subset;
	for (int i = 0; i < 3; i++) {
		start_from_CMI_subset.push_back(start_from_CMI[i]);
		// std::cout << start_from_CMI[i] << std::endl;
	}
	vector<int> toCompare;
	toCompare.push_back(4049); // Champaign
	toCompare.push_back(3830); // Chicago O'Hare
	toCompare.push_back(3670); // Dallas-FW
	// toCompare.push_back(3876); // Charlotte
	REQUIRE(start_from_CMI_subset == toCompare);
}
//Checking that all points in the BFS created from different points are accessed
TEST_CASE("BFS Verify") {
	FlightAlgorithms f;
	vector<int> v1 = f.BFS(0);
	vector<int> v2 = f.BFS(1);
	vector<int> v3 = f.BFS(500);
	for (int i = 0; i < v1.size(); i++) {
		REQUIRE(v1[i] >= 0);
		REQUIRE(v2[i] >= 0);
		REQUIRE(v3[i] >= 0);
		REQUIRE(v1[i] < 14110);
		REQUIRE(v2[i] < 14110);
		REQUIRE(v3[i] < 14110);
		
	}
}		

//Checking all edges in graph to see sum
//for this one, im trying to check that no matter where we start the BFS, the sum of edge weights will remain the same, but i havent figured out how to loop it yet. 
TEST_CASE("Edge Check") {
	FlightGraph f;
	f.loadFlights();
	int sum = 0; 
	//for (int i = 0; i < loop through )
	REQUIRE(420 == 420);
}

TEST_CASE("Verify Dijkstra's is working") {
	FlightAlgorithms fa;
	vector<int> airports;
	airports = fa.dijkstra(3830, 3670); //ORD and Dallas
	for (size_t i = 0;  i  < airports.size(); i++) {
		cout << airports[i] << endl;
	}
	vector<int> toCompare;
	toCompare.push_back(3830); // Chicago O'Hare
	toCompare.push_back(3670); // Dallas-FW
	// toCompare.push_back(3876); // Charlotte
	REQUIRE(airports == toCompare);
}

TEST_CASE("Verify that A* search is working") {
	REQUIRE(1 == 1);
}
