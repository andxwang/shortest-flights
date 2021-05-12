## Week 1

We made the contract this week and discussed goals on what we want to accomplish with this project. In short, we want to traverse through all the airports using BFS, outputting the result in a txt file. We also want to find the shortest flight path between two airports using Dijkstra's and A* search and hopefully show that A* is a more efficient algorithm in the process.


## Week 2

This week, we set up our project repository. We created a make file, a tests file, and a catch file. We downloaded the data from openflights as dat files and loaded them into our repository and started to work on loading it in. We assigned tasks for the week to implement reading in and storing the data and implementing the BFS traversal. Everyone worked well together!

Andy: Load data into vector  
Minjoong: Test cases for the loaded data  
Henry: Implement BFS  
Abhyan: Write BFS tests  

We finished loading in the data creating an FlightGraph object that essentially stores a graph of airports as nodes and possibly routes as edges. 

## Week 3
We discussed and resolved issues with our make file as we continue to make progress on the project. We fixed the make file to allow our code and tests to run. We did some cleaning on our code, removing unused functions like the readFromFile function. We discussed how the data should be parsed for our project and special cases. For example, we discussed how to deal with /N entries in the routes.dat and airports.dat file. We created a new script called FlightAlgorithms to store our BFS, Dijkstra's and A* algorithms. We worked on the constructor to make sure it was right. We finished our BFS and discussed it and made appropriate changes so that it would run. We went over and implemented ideas on how we would test our BFS. We verified our BFS was functional. We removed the unused parameters from our main function as well. We began to write our main function as well, making sure we can create a FlightAlgorithms object correctly. We assigned tasks for the next few weeks regarding the implementation of Dijkstra's and A*.


## Week 4
This week, we finished our implementation of Dijkstra's algorithm. We worked through simple test cases to verify that BFS and Dijkstra's was working as intended. We debugged Dijkstra's and our A* algorithms. We found a small error in the visitation of each node in our Djikstra's algorithm and fixed it so that it would run correctly. After getting Djikstra's to work, we continued to work on our A* algorithm. We continued to write more complex test cases to validate our code. We tested our shortest path algorithms on the route from DAB (Daytona Beach) to PER (Perth) which should lead to the result of DAB -> ATL -> DFW -> BNE -> PER.
 

## Week 5
We finally fixed our A* algorithm and verified that it is working. Now A* and Dijkstra both return the shortest path between two airports. After verifying that our baseline algorithms are working, we made some quality of life changes. For all of our functions, we changed the inputs and outputs instead of being integers representing airport IDs, we changed them to be strings representing airport codes as those are more readable. Airport IDs were just indices specific to our data, but the codes are more distinguishable to the average user. For our BFS, we made sure that we also output a TXT file with the result as the result would be too large to appropriately print out in our main function. We fixed our main function, adding user inputs for the BFS and shortest flight path, making it more user-friendly when we run it in the terminal. We worked on our final project report and documentation. We also rewrote our test cases to match the changes to our functions. We assigned roles on what parts of the final write-up and video each of us would complete.
