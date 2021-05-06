#include "FlightAlgorithms.h"
#include <iostream>
using namespace std;

//  Constructor
FlightAlgorithms::FlightAlgorithms() {
    //  copy files to private members
    flightGraph_.loadAirports();
    flightGraph_.loadFlights();
}

/*
Note: lines 40-42 likely have issues because of the iterator type. Need to fix.
If you want to start writing test cases comment out the while loop and then 
your tests should work- at least for the other functions.
Like ik the case for calculateDistance is working now.
*/

// BFS to traverse from a start point (airport id), returns a vector or vertices
vector<int> FlightAlgorithms::BFS(int start) {
    // Create visited vector, set all values to false, 14110 is ID of last airport
    // vector<bool> visited(14110, false);   

    // USE THIS IF ABOVE DOESN'T WORK
    vector<bool> visited(14110); 
    for (unsigned i = 0; i < 14110; i++) {
        visited[i] = false;
    }

    vector<int> result;      // Vector of all visited airports in order
    queue<int> airportQueue;    // queue for BFS
    airportQueue.push(start);   // enqueue first airport
    visited[start] = true;      // Set starting airport to visited

    //  BFS
    while (!airportQueue.empty()) {
        int curr = airportQueue.front();
        result.push_back(flightGraph_.airportGraph[curr].id); // add current airport to result
        // std::cout << flightGraph_.airportGraph[curr].id << std::endl;
        airportQueue.pop();
        for (auto it = flightGraph_.airportGraph[curr].airports.begin(); it != flightGraph_.airportGraph[curr].airports.end(); it++) {    //  search all departures from current airport
            if (visited[it->first] == false) {  //  next airport has not been visited
                airportQueue.push(it->first);   //  enqueue next airport
                visited[it->first] = true;
            }
        }
    }
    return result;
}

vector<int> FlightAlgorithms::dijkstra(int start, int dest) {
    vector<double> distances(14110); //Initialize distances
    vector<int> previous(14110); // initialize a map that maps current node -> its previous node

    vector<int> airportQueue;    // queue for Djikstra
    airportQueue.push_back(start);   // enqueue first airport

    vector<bool> visited(14110);
    for (unsigned i = 0; i < 14110; i++) {
        visited[i] = false; //initialize all indices of visited to false
        previous[i] = -1;  //initialize all previous airports to none (-1)
        distances[i] = std::numeric_limits<double>::infinity(); //  set all distances to infinity
    }

    visited[start] = true; // set start to visited
    distances[start] = 0; // set distance from start to start to be 0
    previous[start] = start; // initialize starting airport to start
 
    int curr; //ID of current airport

    //     while the top of priority_queue is not destination:
    while (!airportQueue.empty()) {
        //       get the current_node from priority_queue

        //First we need to find the node in the queue that has the shortest distance from the beginning
        double min_dist = std::numeric_limits<double>::infinity(); //set initial distance to infinity
        int min_i; //stores the index of the node with the shortest distance from the start
        for (size_t i = 0; i < airportQueue.size(); i++) { // find node in queue with min distanceFromStart
            if (distances[airportQueue[i]] < min_dist) { //if the airport id in the queue has a distance less than min distance...
                min_dist = distances[airportQueue[i]]; //Set new minimum distance  
                min_i = i; //set the minimum index to index within the queue that corresponds with the airport that has the minimum distance
            }
        }
        curr = airportQueue[min_i]; //set the current airport to airport in queue with the minimum distance
        airportQueue.erase(airportQueue.begin() + min_i); //remove the current airport from the queue

        if (curr == dest) { //if destination is reached, break
            break;
        }
        //       for neighbor in current_node's neighbors and not in visited:
        for (auto it = flightGraph_.airportGraph[curr].airports.begin(); it != flightGraph_.airportGraph[curr].airports.end(); it++) {    //  search all departures from current airport
            if (visited[it->first] == false) {  //  next airport has not been visited / added to the queue
                airportQueue.push_back(it->first);   //  enqueue next airport
                visited[it->first] = true;   // set to visited; added to queue already
            }
            // Check if next airport has not been already added to the queue before, or if it is in the queue...
            if (visited[it->first] == false || find(airportQueue.begin(), airportQueue.end(), it->first) != airportQueue.end()) {
                double neighbor_dist = distances[curr] + (it->second).getWeight(); //  distance of node of current iteration for the start
                //           if update its neighbor's distances:
                if (neighbor_dist < distances[it->first]) {
                    distances[it->first] = neighbor_dist; //update neighbor's distance
                    previous[it->first] = curr;  //    set previous[neighbor] = current_node
                }
            }
        }
    }
    //   extract path from previous
    vector<int> path; //used for path storage; 
    curr = dest; //set current to destination
    if (previous[curr] != -1) { //if there is a possible path between the destination and start
        while (curr != start) { //while current airport is not the start
            path.push_back(curr); //add airport to path
            curr = previous[curr]; //set next airport to airport before
        }
        path.push_back(curr); //push back the starting airport
    }
    reverse(path.begin(), path.end()); //reverse the path since it is backwards
    //   return path and distance; distance to be implemented later
    return path;
}


vector<int> FlightAlgorithms::A_star(int start, int dest) {
    vector<double> distances(14110); //Initialize distances
    vector<int> previous(14110); // initialize a map that maps current node -> its previous node

    vector<int> airportQueue;    // queue for Djikstra
    airportQueue.push_back(start);   // enqueue first airport
    vector<bool> visited(14110);
    for (unsigned i = 0; i < 14110; i++) {
        visited[i] = false; //initialize all indices of visited to false
        previous[i] = -1;  //initialize all previous airports to none (-1)
        distances[i] = std::numeric_limits<double>::infinity(); //  set all distances to infinity
    }

    visited[start] = true; // set start to visited
    distances[start] = 0; // set distance from start to start to be 0
    previous[start] = start; // initialize starting airport to start
 
    int curr; //ID of current airport

    //     while the top of priority_queue is not destination:
    while (!airportQueue.empty()) {
        //       get the current_node from priority_queue

        //First we need to find the node in the queue that has the shortest distance from the beginning
        double min_dist = std::numeric_limits<double>::infinity(); //set initial distance to infinity
        int min_i; //stores the index of the node with the shortest distance from the start
        for (size_t i = 0; i < airportQueue.size(); i++) { // find node in queue with min distanceFromStart
            if (distances[airportQueue[i]] < min_dist) { //if the airport id in the queue has a distance less than min distance...
                min_dist = distances[airportQueue[i]]; //Set new minimum distance
                min_i = i; //set the minimum index to index within the queue that corresponds with the airport that has the minimum distance
            }
        }
        curr = airportQueue[min_i]; //set the current airport to airport in queue with the minimum distance
        airportQueue.erase(airportQueue.begin() + min_i); //remove the current airport from the queue


        if (curr == dest) { //if destination is reached, break
            break;
        }
        //       for neighbor in current_node's neighbors and not in visited:
        for (auto it = flightGraph_.airportGraph[curr].airports.begin(); it != flightGraph_.airportGraph[curr].airports.end(); it++) {    //  search all departures from current airport
            if (visited[it->first] == false) {  //  next airport has not been visited

                airportQueue.push_back(it->first);   //  enqueue next airport
                visited[it->first] = true;   // set to visited; added to queue already

                double neighbor_dist = (distances[curr] + (it->second).getWeight())  + flightGraph_.calculateDistance(curr, dest); //  distance of node of current iteration for the start
                //           if update its neighbor's distances:
                if (neighbor_dist < distances[it->first]) {
                    if (it->first == 2188) {
                        cout<<"AAA 2188"<<endl;
                        cout << "AAA neighbor dist " << neighbor_dist << endl;
                        cout << "AAA dist[it->first] " << distances[it->first]<< endl;

                    }
                    if (it->first == 3351) {
                        cout<<"AAA 3351"<<endl;
                        cout << "AAA neighbor dist " << neighbor_dist << endl;
                        cout << "AAA dist[it->first] " << distances[it->first]<< endl;
                    }
                    if (it->first == 3714) {
                        cout<<"AAA 3714"<<endl;
                        cout << "AAA neighbor dist " << neighbor_dist << endl;
                        cout << "AAA dist[it->first] " << distances[it->first]<< endl;
                    }
                    if (it->first == 11051) {
                        cout<<"AAA 11051"<<endl;
                        cout << "AAA neighbor dist " << neighbor_dist << endl;
                        cout << "AAA dist[it->first] " << distances[it->first]<< endl;
                    }
                    distances[it->first] = neighbor_dist; //update neighbor's distance
                    previous[it->first] = curr;  //    set previous[neighbor] = current_node
                }
            }
        }
    }
    //   extract path from previous
    vector<int> path; //used for path storage; 
    curr = dest; //set current to destination
    if (previous[curr] != -1) { //if there is a possible path between the destination and start
        while (curr != start) { //while current airport is not the start
            path.push_back(curr); //add airport to path
            curr = previous[curr]; //set next airport to airport before
        }
        path.push_back(curr); //push back the starting airport
    }
    reverse(path.begin(), path.end()); //reverse the path since it is backwards
    //   return path and distance; distance to be implemented later
    return path;
}