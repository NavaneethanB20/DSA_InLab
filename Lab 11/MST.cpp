#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define V 6 // Define the number of vertices in the graph

void primMST(const vector<vector<int>>& graph, int startNode) {
    vector<int> minWeight(V, INT_MAX); // Initialize a vector to store the weight of each vertex, initially set to infinity
    vector<bool> visited(V, false); // Initialize a vector to track which vertices have been added to the MST, initially set to false
    vector<int> parent(V, -1); // Initialize a vector to store the parent of each vertex in the MST, initially set to -1

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Create a priority queue to store edges sorted by weight
    
    pq.push(make_pair(0, startNode)); // Push the starting node onto the priority queue with a weight of 0
    minWeight[startNode] = 0; 

    while (!pq.empty()) { // Start the MST algorithm
        int currentNode = pq.top().second; // Get the next vertex with the minimum weight
        pq.pop(); 

        if (visited[currentNode]) // If the vertex has already been added to the MST, continue to the next iteration
            continue;

        visited[currentNode] = true; // Mark the vertex as added to the MST

        for (int adjacentNode = 0; adjacentNode < V; adjacentNode++) { 
            int weight = graph[currentNode][adjacentNode]; // Get the weight of the edge between the current vertex and the adjacent vertex

            if (weight && !visited[adjacentNode] && weight < minWeight[adjacentNode]) { // If there is an edge, the adjacent vertex has not been added to the MST, and the weight of the edge is less than the current weight of the adjacent vertex
                parent[adjacentNode] = currentNode; 
                minWeight[adjacentNode] = weight; 
                pq.push(make_pair(minWeight[adjacentNode], adjacentNode)); // Add the adjacent vertex to the priority queue with its updated weight
            }
        }
    }

    // Print MST edges and weights
    cout << "Minimum Spanning Tree:" << endl;
    cout << "-----------------------------" << endl;
    cout << "Edge \t   Weight" << endl; 
    for (int i = 1; i < V; i++)
        cout << parent[i] << " -- " << i << " \t   " << minWeight[i] << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    vector<vector<int>> adjacencyMatrix = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    primMST(adjacencyMatrix, 0); 

    return 0; 
}