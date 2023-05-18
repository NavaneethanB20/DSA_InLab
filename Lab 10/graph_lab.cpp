#include <iostream>
#include <list>
using namespace std;

struct Node {
    int label;  // Label of the node
    list<int> neighbours;  // List of neighbours (adjacent vertices)
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n];

    void initializeNodes() {
        // Iterate through the nodes and assign labels
        for (int i = 0; i < n; i++) {
            nodes[i].label = i + 1;  // Labels start from 1
        }
    }

    void addEdge(int u, int v) {
        // Select node u and add v to its neighbours
        nodes[u - 1].neighbours.push_back(v);

        // Select node v and add u to its neighbours
        nodes[v - 1].neighbours.push_back(u);
    }

    void print() {
        // Iterate through each node and print its neighbours
        for (int i = 0; i < n; i++) {
            cout << nodes[i].label << " --> ";
            for (auto it = nodes[i].neighbours.begin(); it != nodes[i].neighbours.end(); ++it) {
                cout << *it;
                if (next(it) != nodes[i].neighbours.end()) {
                    cout << " --> ";
                }
            }
            cout << " /\n";
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();

    // Add edges for the graph here
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);

    // Print the graph adjacency list
    g->print();

    return 0;
}