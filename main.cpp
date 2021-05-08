#include <iostream>
#include <vector>
#include "FlightAlgorithms.h"

int main() {
	FlightAlgorithms fa;
	int x, y;
	cout << "Enter a starting point: ";
	cin >> x; 
	cout << "Enter a destination: ";
	cin >> y;
	vector<int> airports = fa.dijkstra(x, y);
	//will lookup for airport codes later
	for (size_t i = 0;  i  < airports.size(); i++) {
		cout << airports[i]; 
		if(i < airports.size() - 1) {
			cout << " -> ";
		} else {
			cout << " " << endl;
		}
	}
	return 0; //placeholder I just dropped in
}