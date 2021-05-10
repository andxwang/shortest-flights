#include <iostream>
#include <vector>
#include "FlightAlgorithms.h"

int main() {
	FlightAlgorithms fa;
	string BFS_start;
	cout << "Enter a start point for BFS: ";
	cin >> BFS_start; 
	fa.BFS(BFS_start);
	cout << "Printing results of BFS traversal to BFS_Result.txt.\n" << endl;
	cout << "Now we can find the shortest path.\n" << endl;
	string start, end;
	cout << "Enter a starting point as an airport code in all caps: ";
	cin >> start; 
	cout << "Enter a destination: ";
	cin >> end;
	vector<string> airports = fa.A_star(start, end);

	cout<<"The shortest path between " << start << " and " << end << " is: " << endl;
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
	/*
	int q = calculateDistance(3682, 2188);
	int w = calculateDistance(2188,3351);
	cout<< "A star is " << q << " + " << w <<endl;
	int a = calculateDistance(3682, 3714);
	int b = calculateDistance(3714,11051);
	int c = calculateDistance(11051, 3351);
	cout<< "dik is " << a << " + " << b << " + " << c<<endl;
	**/