#include <iostream>
#include <fstream>
#include <vector>
#include "MyGraph.h"

using namespace std;

int main()
{
  ifstream ifile("prog2input.txt"); //opens input.txt file to read input 
  int n, e, c; //creates variables to store input 

  ifile >> n >> e >> c; //reads in input values to variables 
  MyGraph g(n); //creates graph object 

  for (int i = 0; i < e; i++) //loops through all edges in the graph 
  {
    int s, t; 
    float w;
    ifile >> s >> t >> w; //stores int values in s and t and float weight values in w 
    g.AddEdge(s, t, w); //passes these values to AddEdge function to see if edge needs to be added to graph or not 
  }

  vector<int> p, q; //create vectors p and q 
  for (int i = 0; i < c; i++) //c represents vertex pairs for which the highest capacity path needs to be computed 
  {
    int s, t; 
    ifile >> s >> t; //start vertex and end vertex assigned to s and t respectively 
    p.push_back(s); //p vector gets start vertex 
    q.push_back(t); //q vector gets end vertex 
  }

  ifile.close(); //close file 

  vector<pair<vector<int>, float> > resarray; //resarray stores results after calling HW2Prog method below 

  // the timer will time this for loop

  for (int i = 0; i < p.size(); i++) //loop through p vector 
  {
    pair<vector<int>, float> res = g.HW2Prog(p[i], q[i], true); //calls HW2Prog method and stores results in res 
    resarray.push_back(res); //pushes res into resarray 
  }

  for (int i = 0; i < p.size(); i++)//loop through p vector pair 
  {
    cout << p[i] << " -> " << q[i] << " : Path : "; //print the start vertex, end vertex
    for (int j = 0; j < resarray[i].first.size(); j++) //loop through resarray 
      cout << resarray[i].first[j] << "  "; //print the path 
      cout << "  capacity : " << resarray[i].second << endl; //print the capacity 
  }

  return (0);
}
