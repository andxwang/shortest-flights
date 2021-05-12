# CS225 SP2021 Final Project - Open Flights Shortest Path


**Advisor**: Vlas Zyrianov

**Team**: 
* Abhyan Jaikishen (abhyanj2)
* Minjoong Kim (msk6)
* Andy Wang (andyjw2)
* Henry Wu (henrywu3)

## Overview: 

Our final project’s goals were to find the shortest path between any two airports by distance given airlines and route information from https://openflights.org/data.html. To accomplish this, our team used BFS to implement a graph of the routes, and then used Dijkstra’s and A * algorithm to find the shortest paths between any two airports.  

## Usage:

Our repository can be cloned using [this](https://github-dev.cs.illinois.edu/cs225-sp21/abhyanj2-msk6-andyjw2-henrywu3.git) link


To use our program, in the terminal, simply enter 

`make`

If you are on EWS, you may have to run 

`module load llvm/6.0.1`

After creating the makefile, you can run the executable 

`./proj`

to run the project.

The terminal will prompt you to enter a start point for the BFS

## not gonna finishh writing this section for now in case we change it


The terminal will prompt you to enter a start and end point as an airport code in all caps. This code is the IATA code of the airports of your choosing. The result of the shortest path between those two airports in IATA form will be printed in the terminal as shown below.

![image](https://postimg.cc/wtVxVtdw)

## Resources:

All the data being used for this project is taken from the OpenFlights website ,and is available to be seen under the "data" folder of this project. 

The loading in of the data and building of the graph was done in the "FlightGraph" class, and made use of the "Vertex" and "Edge" classes. 


## Algorithms:

The three algorithms we implemented(BFS, Dijkstra, A *) can all be found in the "FlightAlgorithms" class, which used a "FlightGraphs" object to build the various traversals and searches. All the major code for this project can be found in "FlightGraph" and "FlightAlgorithms"

## Testing

Our project used catch testing, and covered a variety of tests for our code. 

The main goals of our tests were to: 

* verify that the data being used was not incomplete in any impactful way
* verify that our distances were properly calculated
* verify our BFS was accurately traversing the graph on small subsets of data
* make sure that our Dijkstra's implementation was giving a correct shortest path between airports with known shortest paths
* ensure that our A * implementation was correct, and giving the same result as our Dijkstra's algorithm
* compare the runtimes of A * and Dijkstra's, and verify that A * is faster

Tests can be ran simply by entering 

`make test`
`./test`

into the terminal. 




