Abhyan Jaikishen(abhyanj2)
Minjoong Kim(msk6)
Andy Wang, (andyjw2)
Henry Wu (henrywu3)

# CS 225 Final Project Report
### Goals:
	
For our final project, our team chose to use the OpenFlights dataset to create a program to find the shortest path for any two airports. The OpenFlights web page provided a csv containing information related to airport details, as well as a csv of routes between airports. 

### Development:

Our team first parsed this data into vectors and stored the data to use for our algorithms. We created a Vertex and Edge class to represent the elements of the graph and loaded each airport’s data into a Vertex and each route’s data into an Edge.
In order to traverse through the routes, our team implemented a Breadth-first search traversal for a directed graph, and created a distance function based on the haversine formula dependent on the given latitude and longitude of the airports to create positive edge weights between vertices (airports) with connecting flights.   

To find the shortest path possible with available flights between any two airports, our team implemented Dijkstra’s shortest path algorithm learned in class over our graph for the given airports. To test our Dijkstra’s algorithm, we used online resources to find the shortest path between two airports, and compared it with what our algorithm produced. We encountered issues with our algorithm producing incorrect paths that were still quite short, but not completely correct. After debugging, we found that there was incorrect logic in terms of finding and checking neighboring distances from each vertex, and solved the issue.  

Our team additionally implemented an A* search to find the shortest path between any two airports in our dataset. With A* being relatively similar to Dijkstra’s, we used much of the same logic in the implementation. The key difference was that we used an admissible heuristic function for our A* algorithm to guide the search in order to drastically decrease runtime. Our tests showed that our A* algorithm and Dijkstra’s algorithm returned the same paths from airport A to B, with A* having a significantly faster runtime, which confirmed what we knew about both algorithms. 

### Testing:

Tests were created using CATCH and subsets of the airports and routes data. Some tests utilized online tools, such as distance calculators or flight-mapping tools to verify our algorithms and functions were working as intended. However, the final test suite utilizes the full dataset and tests our functions on multiple paths. Furthermore, our tests for data-parsing and algorithm runtime affirm the project is running as intended. 

### Conclusion: 

We are proud to say that we accomplished our initial goals and can find the shortest-path between any two airports provided in the dataset. It should be noted that we use the Euclidean distance between airports rather than the actual flight path or flight-time for a given route, meaning that our results are realistically not 100% accurate. 

The BFS traverses the graph from a user-inputted starting code (e.g. LAX) and the shortest-path algorithms use a user-inputted start and destination (e.g. DAB and PER, respectively). BFS returns the traversal in a .txt file and the shortest-path algorithm outputs the path in the terminal (DAB->ATL->DFW->BNE->PER in this case). 

This project initially seemed daunting given that we started from scratch. We even initially had some difficulty with our makefile (another learning experience). Having full control over the design and development process of the project was a unique and enlightening experience. We constantly made changes to our classes and objects to better address runtime issues and mitigate future obstacles. There were moments of frustration, without a doubt, but the overall process was fun and fulfilling.

In the future, we could implement other graph traversals or complex algorithms, such as Landmark path or DFS. A priority would be trying to implement a visualization of the paths we generate and we fully believe this is doable given how much we worked with images this past semester. There is always room for improvement and we look forward to seeing what can be accomplished in the future. 
