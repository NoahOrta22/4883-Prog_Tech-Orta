// C++ program to find out whether
// a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;


// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(vector<vector<int>> G, int src, vector<int> &colorArr, int numNodes, int &guards)
{

  int V = numNodes;

  int numBlue = 0;      // number of blue nodes
  int numRed = 0;       // number of red nodes

  colorArr[src] = 1;
  numBlue++;

	// Create a queue (FIFO) of vertex numbers a
	// nd enqueue source vertex for BFS traversal
	queue<int> q;
	q.push(src);

  

	// Run while there are vertices in queue (Similar to
	// BFS)
	while (!q.empty()) {
		// Dequeue a vertex from queue ( Refer
		// http://goo.gl/35oz8 )
		int u = q.front();
		q.pop();

		// Return false if there is a self-loop
		if (G[u][u] == 1) {
      return false;
    }

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v) {
			// An edge from u to v exists and
			// destination v is not colored
			if (G[u][v] && colorArr[v] == -1) {
				// Assign alternate color to this
				// adjacent v of u
				colorArr[v] = 1 - colorArr[u];

        // for(int i = 0; i < colorArr.size(); i++) {
        //   cout << colorArr[i] << " ";
        // }
        // cout << endl;

        if(colorArr[v] == 1) {
          numBlue++;
          // cout << "increasing blue\n";
        }
        else if(colorArr[v] == 0) {
          numRed++;
          // cout << "increasing red\n";
        }
        
        // cout << "COLOR u: " << colorArr[u] << '\n';
        // cout << "COLOR v: " << colorArr[v] << '\n';
        
				q.push(v);
        
			}
			// An edge from u to v exists and destination
			// v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;

		}

	}

  // we want the SMALLEST number of guards
  if(numRed > numBlue) {
    guards += numBlue;
  }
  else if(numRed < numBlue){
    guards += numRed;
  }
  else {
    guards += numBlue;
  }

  // if there's only one node not connected to anyone
  if(numRed == 0 && numBlue == 1) {
    guards++;
  }

	// If we reach here, then all adjacent vertices can
	// be colored with alternate color
	return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(vector<vector<int>> G, int numNodes, int &guards)
{
  int V = numNodes;
  int smallest = 1;    // the smallest node is blue(1), or red(0) or equal(1)

  int numBlue = 0;      // number of blue nodes
  int numRed = 0;       // number of red nodes
  
	// Create a color array to store colors assigned to all
	// vertices. Vertex/ number is used as index in this
	// array. The value '-1' of colorArr[i] is used to
	// indicate that no color is assigned to vertex 'i'.
	// The value 1 is used to indicate first color is
	// assigned and value 0 indicates second color is
	// assigned.
  vector<int> colorArr(V, -1);

	// This code is to handle disconnected graph
	for (int i = 0; i < V; i++) {
    if (colorArr[i] == -1) {
      if (isBipartiteUtil(G, i, colorArr, numNodes, guards) == false)
				return false;
    }
  }

	return true;
}

// Driver code
int main()
{
  int numGuards = 0;

  int testCases;                         // number of test cases
  
  int numNodes, numEdges;

  cin >> testCases;                      // get the number of nodes

  // goes through all the test cases
  for(int i = 0; i < testCases; i++) {
    cin >> numNodes >> numEdges;         // how many nodes in a map
    // cout << "nodes: " << numNodes << "\nedges: " << numEdges << '\n';

    vector<vector<int>> graph(numNodes, vector<int> (numNodes));

    // looks at all the nodes
    for(int j = 0; j < numEdges; j++) {
      int node1, node2;

      cin >> node1 >> node2;             //  they're connected

      graph[node1][node2] = 1;
      graph[node2][node1] = 1;

    }

    // for(int r = 0; r < graph.size(); r++) {
    //   for(int c = 0; c < graph.size(); c++) {
    //     cout << graph[r][c] << " ";
    //   }
    //   cout << '\n';
    // }

    
    if(isBipartite(graph, numNodes, numGuards)) {
      // cout << "answer: ";
      cout << numGuards << '\n';
    }
    else {
      // cout << "answer: ";
      cout << -1 << '\n';
    }

    numGuards = 0;
  }
	
	return 0;
}
