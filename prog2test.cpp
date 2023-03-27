#include <iostream>
#include <fstream>
#include <vector>
#include "MyGraph.h"
//#include "MyGraph.cpp" //TODO - commented out for Mac but has to be enabled for windows? 
#include <chrono> //included for timing for loop 

using namespace std;

int main()
{ 
  ifstream ifile("prog2input.txt"); // opens input.txt file to read input
  int n, edges, c;                      // creates variables to store input

  ifile >> n >> edges >> c; // reads in input values to variables
  MyGraph g(n);         // creates graph object

  for (int i = 0; i < edges; i++) // loops through all edges in the graph
  {
    int s, t;
    float w;
    ifile >> s >> t >> w; // stores int values in s and t and float weight values in w
    g.AddEdge(s, t, w);   // passes these values to AddEdge function to see if edge needs to be added to graph or not
  }

  vector<int> p, q;           // create vectors p and q
  for (int i = 0; i < c; i++) // c represents vertex pairs for which the highest capacity path needs to be computed
  {
    int startV, endV;
    ifile >> startV >> endV; // start vertex and end vertex assigned to s and t respectively
    // cout << "START: " << startV << endl; 
    // cout << "ENDV: " << endV << endl; 
    p.push_back(startV);  // p vector gets start vertex
    q.push_back(endV);  // q vector gets end vertex
  }

  ifile.close(); // close file

  vector<pair<vector<int>, float> > resarray; // resarray stores results after calling HW2Prog method below

  // the timer will time this for loop
  auto start = chrono::high_resolution_clock::now();

  // unsync the I/O of C and C++.
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < p.size(); i++) // loop through p vector
  {
    pair<vector<int>, float> res = g.HW2Prog(p[i], q[i], true); //calls HW2Prog method and stores results in res
    resarray.push_back(res); // pushes res into resarray
  }

  auto end = chrono::high_resolution_clock::now(); //end time after for loop 
  double forDuration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  forDuration *= 1e-9; //multiply to convert to seconds? 

  for (int i = 0; i < p.size(); i++) // loop through p vector pair
  {
    cout << p[i] << " -> " << q[i] << " : Path : ";        // print the start vertex, end vertex
    for (int j = 0; j < resarray[i].first.size(); j++)     // loop through resarray
      cout << resarray[i].first[j] << "  ";                // print the path
    cout << "  capacity : " << resarray[i].second << endl; // print the capacity
  }

  cout << "DURATION OF FOR: " << forDuration << "seconds" << endl;
  return (0);

}

