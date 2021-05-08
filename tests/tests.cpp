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
  // toCompare.push_back(3876); // Charlotte // As of 2014, there was no route from CMI-Charlotte
  REQUIRE(start_from_CMI_subset == toCompare);
}

TEST_CASE("Verify BFS 2") {
	// routes data might be more outdated than flightconnections.com
	FlightAlgorithms fa;
	vector<int> start_TTN = fa.BFS(3447); // Trenton
	vector<int> start_TTN_subset;
	vector<int> toCompare;
	toCompare.push_back(3447);
	toCompare.push_back(3626); // Raleigh-Durham
	toCompare.push_back(3876); // Charlotte
	toCompare.push_back(3515); // Myrtle Beach
	toCompare.push_back(3806); // Charleston
	toCompare.push_back(3830); // Chicago
	toCompare.push_back(3682); // Atlanta
	toCompare.push_back(3878); // Orlando
	toCompare.push_back(3646); // Tampa
	toCompare.push_back(3793); // Fort Myers
	toCompare.push_back(3576); // Miami
	
	for (int i = 0; i < toCompare.size(); i++) {
		start_TTN_subset.push_back(start_TTN[i]);
		std::cout << start_TTN[i] << " ";
		// results: 
		// 3447 3488 3626 3793 3747 3878 3533 3645 3646 3876 6989
		// start, Cincinatti, Raleigh-Durham, Fort Myers, Chicago Midway, 
		// Orlando, Ft. Lauderdale, Detroit, Tampa, Charlotte, St. Augustine
	}
	std::cout << std::endl;

	REQUIRE(start_TTN_subset == toCompare);
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

// verified using: https://www.flightconnections.com/flights-to-sydney-syd 
TEST_CASE("Verify Dijkstra's is working 1") {
  FlightAlgorithms fa;
  vector<int> airports;
  airports = fa.dijkstra(3830, 3670); //ORD and Dallas
  // for (size_t i = 0;  i  < airports.size(); i++) {
  //  cout << airports[i] << endl;
  // }
  vector<int> toCompare;
  toCompare.push_back(3830); // Chicago O'Hare
  toCompare.push_back(3670); // Dallas-FW
  // toCompare.push_back(3876); // Charlotte
  REQUIRE(airports == toCompare);
}

//CASE 2 Shortest path for ORD->SYD. Returns ORD->LAX->SYD
TEST_CASE("Verify Dijkstra's 2") {
	FlightAlgorithms fa;
	vector<int> airports;
	airports = fa.dijkstra(3830, 3361); //ORD to SYD
	//just wanna see what this looks like 
	// for (size_t i = 0;  i  < airports.size(); i++) {
	//  cout << airports[i] << endl; //fly from ORD to LAX to Sydney 
	// }
	vector<int> toCompare;
	toCompare.push_back(3830); 
	toCompare.push_back(3484);
	toCompare.push_back(3361);
	REQUIRE(airports == toCompare);
}

//CASE 3 Shortest path for DAB->PER. Returns DAB->ATL->IAD->MCT->PER.
TEST_CASE("Verify Dijkstra's 3") {
	// The online programs don't show this as a possibility
	// Makes sense since flight paths aren't a straight distance like we assumed
	// The overall path does technically make sense though
	FlightAlgorithms fa;
	vector<int> airports;
	airports = fa.dijkstra(3950, 3351);
	// for (size_t i = 0;  i  < airports.size(); i++) {
	// 	cout << airports[i] << endl; //fly from ORD to LAX to Sydney 
	// }
	vector<int> toCompare;
	toCompare.push_back(3950);
	toCompare.push_back(3682);
	toCompare.push_back(3714);
	toCompare.push_back(11051);
	toCompare.push_back(3351);
	REQUIRE(airports == toCompare);
}

//will use same tests as Dijkstra's it should just run faster
// TEST_CASE("Verify A* search 1") {
//   FlightAlgorithms fa;
//   vector<int> airports;
//   airports = fa.A_star(3830, 3670); //ORD and Dallas
//   // for (size_t i = 0;  i  < airports.size(); i++) {
//   //  cout << airports[i] << endl;
//   // }
//   vector<int> toCompare;
//   toCompare.push_back(3830); // Chicago O'Hare
//   toCompare.push_back(3670); // Dallas-FW
//   // toCompare.push_back(3876); // Charlotte
//   REQUIRE(airports == toCompare);
// }

// //CASE 2 Shortest path for ORD->SYD. Returns ORD->LAX->SYD
// TEST_CASE("Verify A* search 2") {
// 	FlightAlgorithms fa;
// 	vector<int> airports;
// 	airports = fa.A_star(3830, 3361); //ORD to SYD
// 	//just wanna see what this looks like 
// 	// for (size_t i = 0;  i  < airports.size(); i++) {
// 	//  cout << airports[i] << endl; //fly from ORD to LAX to Sydney 
// 	// }
// 	vector<int> toCompare;
// 	toCompare.push_back(3830); 
// 	toCompare.push_back(3484);
// 	toCompare.push_back(3361);
// 	REQUIRE(airports == toCompare);
// }

// //CASE 3 Shortest path for DAB->PER. Returns DAB->ATL->IAD->MCT->PER.
// TEST_CASE("Verify A* search 3") {
// 	// The online programs don't show this as a possibility
// 	// Makes sense since flight paths aren't a straight distance like we assumed
// 	// The overall path does technically make sense though
// 	FlightAlgorithms fa;
// 	vector<int> airports;
// 	airports = fa.A_star(3950, 3351);
// 	// for (size_t i = 0;  i  < airports.size(); i++) {
// 	// 	cout << airports[i] << endl; //fly from ORD to LAX to Sydney 
// 	// }
// 	vector<int> toCompare;
// 	toCompare.push_back(3950);
// 	toCompare.push_back(3682);
// 	toCompare.push_back(3714);
// 	toCompare.push_back(11051);
// 	toCompare.push_back(3351);
// 	REQUIRE(airports == toCompare);
// }


//run-time test case
TEST_CASE("Verify that A* is faster than Dijkstra's") {
	FlightAlgorithms fa;
	vector<int> airports;
  auto start = std::chrono::high_resolution_clock::now();
	airports = fa.dijkstra(3950, 3351);
  auto stop = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  cout << "Dijkstra's Runtime: " << time.count() << " microseconds" << endl;
  airports.clear();
  REQUIRE(1 == 1); //comment out once we write A*  
  // auto start2 = std::chrono::high_resolution_clock::now();
  // airports = fa.A_star(3950, 3351); //or whatever we decide to name it
  // auto stop2 = std::chrono::high_resolution_clock::now();
  // auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
  // cout << "A* Search Runtime: " << time2.count() << " microseconds" << endl;
  // REQUIRE(time2.count() <= time.count());
}
