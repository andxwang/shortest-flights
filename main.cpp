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
	vector<string> airports = fa.A_star(x, y);
	vector<string> dij = fa.dijkstra(x,y);
	//will lookup for airport codes later (can use 3830, 3361 for now) 
	//Shortest path for ORD->SYD. Returns ORD->LAX->SYD
	cout<<"A-star" << endl;
	for (size_t i = 0;  i  < airports.size(); i++) {
		cout << airports[i]<<endl; 
		if(i < airports.size() - 1) {
			cout << " -> ";
		} else {
			cout << " " << endl;
		}
	}
	cout<<"dijkstra" << endl;
	for (size_t i = 0;  i  < dij.size(); i++) {
		cout << dij[i]<<endl; 
		if(i < dij.size() - 1) {
			cout << " -> ";
		} else {
			cout << " " << endl;
		}
	}
	/*
	int q = calculateDistance(3682, 2188);
	int w = calculateDistance(2188,3351);
	cout<< "A star is " << q << " + " << w <<endl;
	int a = calculateDistance(3682, 3714);
	int b = calculateDistance(3714,11051);
	int c = calculateDistance(11051, 3351);
	cout<< "dik is " << a << " + " << b << " + " << c<<endl;
	**/
	return 0; //placeholder I just dropped in
}