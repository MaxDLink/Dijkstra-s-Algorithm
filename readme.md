#Readme File 

# The GOAL: Create a graph. Retreive the highest capacity between two Nodes in the graph. 
## Note: When getting multiple capacities (crossing multiple edges), the newest capacity is set as current capacity that will be retrieved.   

# Algorithm 
In this program, a modified version of the Dijsktra algorithm was used. The original algorithm grabs the shortest path in a graph. The algorithm views the weight on the graph as a distance and grabs the lowest distance value between two points. This algorithm can be easily modified to grab the highest weight between two nodes instead of the lowest. Instead of viewing the weight as distance, it can be viewed as capacity. 

## Test Cases: 
First line = # of vertices, # of edges, # of paths that will be looked for.  
Other lines with 3 #s = Node1, Node2, Weight between Nodes. 
Lines with 2 #s = Paths that want to be found between two Nodes. 
### Original Input Modified to work:   
4 5 3
0 1 8
0 2 7
3 2 2
3 1 3
1 2 5
0 1 
1 3 
2 1 

### Rubric First Example Test input from HKitty Tamagou --> should output path: 0 --> 4 with capacity 110 
5 6 1
0 1 145
0 2 150 
1 3 65 
2 3 125 
3 4 110 
2 4 65 
0 4 