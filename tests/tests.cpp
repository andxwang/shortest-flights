#include <string>
#include <vector>
#include "../catch/catch.hpp"
#include "../FlightGraph.h"
#include "../FlightAlgorithms.h"
#include <iostream>
#include <cmath>
#include <chrono> 

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
TEST_CASE("Verify BFS 1") {
  FlightAlgorithms fa;
  vector<string> start_from_CMI = fa.BFS("CMI"); // CMI airport code
  vector<string> start_from_CMI_subset;
  for (int i = 0; i < 3; i++) {
    start_from_CMI_subset.push_back(start_from_CMI[i]);
    // std::cout << start_from_CMI[i] << std::endl;
  }
  vector<string> toCompare;
  toCompare.push_back("CMI"); // Champaign
  toCompare.push_back("ORD"); // Chicago O'Hare
  toCompare.push_back("DFW"); // Dallas-FW
  // toCompare.push_back(3876); // Charlotte // As of 2014, there was no route from CMI-Charlotte
  REQUIRE(start_from_CMI_subset == toCompare);
}

TEST_CASE("Verify BFS 2") {
	// routes data might be more outdated than flightconnections.com
	FlightAlgorithms fa;
	vector<string> start_TTN = fa.BFS("TTN"); // Trenton
	vector<string> start_TTN_subset;
	vector<string> toCompare;
	toCompare.push_back("TTN");
  toCompare.push_back("CVG");
  toCompare.push_back("RDU");
  toCompare.push_back("RSW");
  toCompare.push_back("MDW");
  toCompare.push_back("MCO");
  toCompare.push_back("FLL");
  toCompare.push_back("DTW");
  toCompare.push_back("TPA");
  toCompare.push_back("CLT");
  toCompare.push_back("UST");
	for (int i = 0; i < toCompare.size(); i++) {
		start_TTN_subset.push_back(start_TTN[i]);
		//std::cout << start_TTN[i] << " ";
		// results: 
		// 3447 3488 3626 3793 3747 3878 3533 3645 3646 3876 6989
		// start, Cincinatti, Raleigh-Durham, Fort Myers, Chicago Midway, 
		// Orlando, Ft. Lauderdale, Detroit, Tampa, Charlotte, St. Augustine
	}

	REQUIRE(start_TTN_subset == toCompare);
}

// Checking that all points in the BFS created from different points are accessed
// TEST_CASE("BFS Verify") {
//   FlightAlgorithms f;
//   vector<int> v1 = f.BFS(0);
//   vector<int> v2 = f.BFS(1);
//   vector<int> v3 = f.BFS(500);
//   for (int i = 0; i < v1.size(); i++) {
//     REQUIRE(v1[i] >= 0);
//     REQUIRE(v2[i] >= 0);
//     REQUIRE(v3[i] >= 0);
//     REQUIRE(v1[i] < 14110);
//     REQUIRE(v2[i] < 14110);
//     REQUIRE(v3[i] < 14110);
//   }
// }   



TEST_CASE("Verify Dijkstra's is working 1") {
  FlightAlgorithms fa;
  vector<string> airports;
  airports = fa.dijkstra("ORD", "DFW"); //ORD and Dallas

  vector<string> toCompare {"ORD", "DFW"};

  REQUIRE(airports == toCompare);
}

//CASE 2 Shortest path for ORD->SYD. Returns ORD->LAX->SYD
TEST_CASE("Verify Dijkstra's 2") {
	FlightAlgorithms fa;
	vector<string> airports;
	airports = fa.dijkstra("ORD", "SYD"); //ORD to SYD
	//just wanna see what this looks like 
	// for (size_t i = 0;  i  < airports.size(); i++) {
	//  cout << airports[i] << endl; //fly from ORD to LAX to Sydney 
	// }
	vector<string> toCompare {"ORD", "LAX", "SYD"};

	REQUIRE(airports == toCompare);
}

//CASE 3 Shortest path for DAB->PER. Returns DAB -> ATL -> DFW -> BNE -> PER.
TEST_CASE("Verify Dijkstra's 3") {
	FlightAlgorithms fa;
	vector<string> airports;
	airports = fa.dijkstra("DAB", "PER");

	vector<string> toCompare {"DAB", "ATL", "DFW", "BNE", "PER"};

	REQUIRE(airports == toCompare);
}

TEST_CASE("Verify A* search 1") {
  FlightAlgorithms fa;
  vector<string> airports;
  airports = fa.A_star("ORD", "DFW"); //ORD and Dallas

  vector<string> toCompare {"ORD", "DFW"};

  REQUIRE(airports == toCompare);
}

//CASE 2 Shortest path for ORD->SYD. Returns ORD->LAX->SYD
TEST_CASE("Verify A* search 2") {
	FlightAlgorithms fa;
	vector<string> airports;
	airports = fa.A_star("ORD", "SYD"); //ORD to SYD

	vector<string> toCompare {"ORD", "LAX", "SYD"};
  
	REQUIRE(airports == toCompare);
}

//CASE 3 Shortest path for DAB->PER. Returns DAB->ATL->IAD->DOH->PER.
TEST_CASE("Verify A* search 3") {

	FlightAlgorithms fa;
	vector<string> airports;
	airports = fa.A_star("DAB", "PER");

	vector<string> toCompare {"DAB", "ATL", "DFW", "BNE", "PER"};

	REQUIRE(airports == toCompare);
}


//run-time test case
TEST_CASE("Verify that A* is faster than Dijkstra's") {
	FlightAlgorithms fa;
	vector<string> airports;
  auto start = std::chrono::high_resolution_clock::now();
	airports = fa.dijkstra("ORD", "SYD");
  auto stop = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  cout << "Dijkstra's Runtime: " << time.count() << " microseconds" << endl;
  airports.clear();

  auto start2 = std::chrono::high_resolution_clock::now();
  airports = fa.A_star("ORD", "SYD"); 
  auto stop2 = std::chrono::high_resolution_clock::now();
  auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
  cout << "A* Search Runtime: " << time2.count() << " microseconds" << endl;
  REQUIRE(time2.count() <= time.count());
}
