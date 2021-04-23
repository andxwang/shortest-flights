#include <string>
#include <vector>
#include "../catch/catch.hpp"
#include "../FlightGraph.h"
#include "../FlightAlgorithms.h"
#include <iostream>


/*
Example test case from instruction
*/
// TEST_CASE("Verify that file_to_string works on a small example") {
// 	std::string res = file_to_string("tests/smallSample.txt");
// 	// always check "expected" == "actual" --> be consistent
// 	REQUIRE("hello\nstudents\nof\ncs\n225\n!!!\n" == res);
// }

// /*
// Example test case from instruction
// */
// TEST_CASE("Verify that file_to_vector works on a small example") {
// 	std::vector<std::string> res = file_to_vector("tests/smallSample.txt");
// 	std::string expected[] = {"hello", "students", "of", "cs", "225", "!!!"};
	
// 	REQUIRE(6 == res.size());

// 	for (int i = 0; i < res.size(); i++) {
// 		REQUIRE(expected[i] == res[i]);
// 	}
// }	

//just gonna use this to see if I'm doing this correctly
TEST_CASE("Verify that calculateDistance works ") {
	FlightGraph bruh;
	bruh.loadAirports();
 	bruh.loadFlights();
	REQUIRE(bruh.calculateDistance(0, 0) == 0);
	// REQUIRE(bruh.calculateDistance())
}

/*
Still figuring out what to do with \\N values
*/

//I'ma just comment these out for now and see 
//ok ye the && is problematic for some reason- will come back to it

/*
TEST_CASE("Verify that null values and \\N values are not in routes vector") {
	FlightGraph flights;
	flights.loadAirports();
	vector<vector<string>> routes = flights.routes;
   
	vector<vector<string>>::const_iterator row; 
    vector<string>::const_iterator col; 
	for (row = routes.begin(); row != routes.end(); ++row) {
		for (col = row->begin(); col != row->end(); ++col) {
			REQUIRE(*col != "Null" && *col != "\\N"); 
		}
	}
}

TEST_CASE("Verify that null and \\N values are not in airports vector") {
	FlightGraph flights;
	flights.loadFlights();
    vector<vector<string>> airports = flights.airports;
	vector<vector<string>>::const_iterator row; 
    vector<string>::const_iterator col; 
	for (row = airports.begin(); row != airports.end(); ++row) {
		for (col = row->begin(); col != row->end(); ++col) {
			REQUIRE(*col != "Null" && *col != "\\N");
		}
	}
}
*/ 
	
