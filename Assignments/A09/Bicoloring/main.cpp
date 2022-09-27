// C++ program to find out whether
// a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;


// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(vector<vector<int>> G, int src, int colorArr[], int numNodes)
{

  int V = numNodes;
  
	colorArr[src] = 1;

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
				q.push(v);
			}

			// An edge from u to v exists and destination
			// v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// If we reach here, then all adjacent vertices can
	// be colored with alternate color
	return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(vector<vector<int>> G, int numNodes)
{
  int V = numNodes;
  
	// Create a color array to store colors assigned to all
	// vertices. Vertex/ number is used as index in this
	// array. The value '-1' of colorArr[i] is used to
	// indicate that no color is assigned to vertex 'i'.
	// The value 1 is used to indicate first color is
	// assigned and value 0 indicates second color is
	// assigned.
	int colorArr[V];
	for (int i = 0; i < V; ++i) {
    colorArr[i] = -1;
  }

	// This code is to handle disconnected graph
	for (int i = 0; i < V; i++) {
    if (colorArr[i] == -1) {
      if (isBipartiteUtil(G, i, colorArr, numNodes) == false)
				return false;
    }
  }

	return true;
}



// Driver code
int main()
{
  int numNodes;
  int numEdges;

  cin >> numNodes;          // get the number of nodes

  while(numNodes != 0) {
    cin >> numEdges;        // get the number of edges

    vector<vector<int>> graph(numNodes, vector<int> (numNodes));

    for(int i = 0; i < numEdges; i++) {
      int node1; 
      int node2;
      cin >> node1 >> node2;
      graph[node1][node2] = 1;
      graph[node2][node1] = 1;
    }

    //isBipartite(graph, numNodes) ? cout << "BICOLORABLE.\n" : cout << "BICOLORABLE.\n";
    if(isBipartite(graph, numNodes)) {
      cout << "BICOLORABLE.\n";
    }
    else {
      cout << "NOT BICOLORABLE.\n";
    }

    cin >> numNodes;
  }
	
	return 0;
}
