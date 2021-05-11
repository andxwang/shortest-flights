# CS 225 Data Structures
## Project Proposal (abhyanj2-msk6-andyjw2-henrywu3)

1. **Leading Question** Given the Open Flights dataset, our goal is to find the shortest flight path from point A to point B to find preferable routes.
Ideally, we would have a function or interface whereby entering the parameters of two airports, 
the shortest path between those two locations would be returned based on available flight routes.

2. **Dataset Acquistion and Processing** Our team will use the Open Flights dataset, specifically the airports.dat and routes.dat files, 
as well as potentially the airlines.dat file. The files are available for download as a CSV file, and will be stored on Github. 
We will load the data into arrays and then construct a weighted digraph with the flight paths as edges and airports as nodes.
Given the size of the data, we will drop any entries with errors by first by first checking all the entries.

3. **Graph Algorithms** For our first algorithm we will be finding the shortest path between two airports using Dijkstra's algorithm.
Our function will have 2 main parameters, the starting airport node and the destination airport node. 
The output of the function will be the shortest path as a text file (ORD->EWR->ATL). If we’re able to we’d like to overlay the graph path on a world map. 
We would like to target a big O efficiency of O(Elog(v)) where E is the maximum number of edges from a single node and V is the number of nodes. 

For the complex/uncovered algorithm, we plan on using an A* search algorithm to find the shortest distance between two cities. Edges will be flight paths between two cities.
The weight factor for the A* search will be distance, since that is what we are trying to minimize.

To test, we plan to have test cases with known shortest distances. For example, we could test the output for two large cities, since we would know the shortest distance. 
We could also find a small airport that only has service to a few cities, such as Champaign’s airport, and find known shortest distances.

Lastly, for the graph traversal we would like to implement BFS with an iterator. 
The BFS function will take in a starting airport node and then iterate through in a traditional BFS manner. 
The operator++ will simply update to the next airport node by following the conditions of a BFS. 

4. **Timeline** 

  April 9 - submit project proposal and team contract

  April 15 - set up initial repository and Makefile. finish reading in data into array format and write simple tests to verify correctness

  April 19 - convert array format into graph format and pass simple tests

  April 22 - write BFS iterator and verify with tests

  April 19-23 - mid-project check-in

  April 29 - write Dijikstra's and verify with tests

  May 5 - write A* search algorithm and verify with tests

  May 7 - finish report

  May 9 - sync to record final presentation

  May 12 - finish editing presentation and submit

