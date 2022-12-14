#include <iostream>
#include <vector>

using namespace std;

// C++ implementation to find the
// shortest path in a directed
// graph from source vertex to
// the destination vertex
 
#include <bits/stdc++.h>
#define infi 1000000000
using namespace std;
 
// Class of the node
class Node {
public:
    int vertexNumber;
 
    // Adjacency list that shows the
    // vertexNumber of child vertex
    // and the weight of the edge
    vector<pair<int, int> > children;
    Node(int vertexNumber)
    {
        this->vertexNumber = vertexNumber;
    }
 
    // Function to add the child for
    // the given node
    void add_child(int vNumber, int length)
    {
        pair<int, int> p;
        p.first = vNumber;
        p.second = length;
        children.push_back(p);
    }
};
 
// Function to find the distance of
// the node from the given source
// vertex to the destination vertex
vector<int> dijkstraDist(
    vector<Node*> g,
    int s, vector<int>& path)
{
    // Stores distance of each
    // vertex from source vertex
    vector<int> dist(g.size());
 
    // Boolean array that shows
    // whether the vertex 'i'
    // is visited or not
    bool visited[g.size()];
    for (int i = 0; i < g.size(); i++) {
        visited[i] = false;
        path[i] = -1;
        dist[i] = infi;
    }
    dist[s] = 0;
    path[s] = -1;
    int current = s;
 
    // Set of vertices that has
    // a parent (one or more)
    // marked as visited
    unordered_set<int> sett;
    while (true) {
 
        // Mark current as visited
        visited[current] = true;
        for (int i = 0;
             i < g[current]->children.size();
             i++) {
            int v = g[current]->children[i].first;
            if (visited[v])
                continue;
 
            // Inserting into the
            // visited vertex
            sett.insert(v);
            int alt
                = dist[current]
                  + g[current]->children[i].second;
 
            // Condition to check the distance
            // is correct and update it
            // if it is minimum from the previous
            // computed distance
            if (alt < dist[v]) {
                dist[v] = alt;
                path[v] = current;
            }
        }
        sett.erase(current);
        if (sett.empty())
            break;
 
        // The new current
        int minDist = infi;
        int index = 0;
 
        // Loop to update the distance
        // of the vertices of the graph
        for (int a: sett) {
            if (dist[a] < minDist) {
                minDist = dist[a];
                index = a;
            }
        }
        current = index;
    }
    return dist;
}
 
// Function to print the path
// from the source vertex to
// the destination vertex
void printPath(vector<int> path,
               int i, int s)
{
    if (i != s) {
 
        // Condition to check if
        // there is no path between
        // the vertices
        if (path[i] == -1) {
            cout << "Path not found!!";
            return;
        }
        printPath(path, path[i], s);
        cout << path[i] << " ";
    }
}



int main() {

  int testCases;
  cin >> testCases;

  const int s = 0;     // the starting node

  int numRows, numColumns, weight;

  // loop through the test cases
  for(int i = 0; i < testCases; i++) {
    cin >> numRows >> numColumns;

    int numNodes = numRows * numColumns;

    vector<Node*> v;
    // Loop to create the nodes
    for (int j = 0; j < numNodes; j++) {
      Node* a = new Node(i);
      v.push_back(a);
    }

    // making the connections
    for(int k = 0; k < numNodes; k++) {
      // get the weight
      cin >> weight;

      if(numNodes == 1) {
        cout <<  weight << '\n';
        break;
      }

      // add the self loop if on the first node
      if(k == 0)
        v[k]->add_child(k, weight);
      
      // one to the right
      if((k%numColumns)+1 < numColumns) {
        v[k+1]->add_child(k, weight);
      }
      // one to the left
      if((k%numColumns)-1 >= 0) {
        v[k-1]->add_child(k, weight);
      }
      // one down
      if(k+numColumns < numNodes) {
        v[k+numColumns]->add_child(k, weight);
      }
      // one up
      if(k-numColumns >= 0) {
        v[k-numColumns]->add_child(k, weight);
      }
    }

    // for(int n = 0; n < v.size(); n++) {
    //   cout << "V-" << n << ": \n";

    //   for(int m = 0; m < v[n]->children.size(); m++) {
    //     cout << "child: " << v[n]->children[m].first << " - weight: " 
    //          << v[n]->children[m].second << '\n';
    //   }
    // }

    // if there's only one node skip going into the algorithm
    if(numNodes == 1) {
      continue;
    }

    vector<int> path(v.size());
    vector<int> dist = dijkstraDist(v, s, path);

    cout << dist[v.size()-1] + v[0]->children[0].second << '\n';
    
    // cout << i << ": " << numNodes << '\n';
    // cout << "v size: " << v.size() << '\n';    
    // cout << "nodeweight#: " << v[0]->children[0].second << '\n';
    
    // cout << "Distance: " << dist[v.size()-1] + v[0]->children[0].second << '\n';
    // cout << "Distance: " << dist[12] + v[0]->children[0].second << '\n';

  }
}
