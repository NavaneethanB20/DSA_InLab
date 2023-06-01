#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // Infinity value for unreachable cities

// Structure to represent a city and its distance from the source city
struct City {
    int index;      
    int distance;   

    City(int index, int distance) : index(index), distance(distance) {}

    
    bool operator>(const City& other) const {
        return distance > other.distance;
    }
};

// Dijkstra's algorithm to find the shortest time from a source city to all other cities
void dijkstra(vector<vector<int>>& graph, int source) {
    int numCities = graph.size();

    vector<int> distances(numCities, INF);

    // Create a priority queue to store the cities to be visited
    priority_queue<City, vector<City>, greater<City>> pq;

    distances[source] = 0;
    pq.push(City(source, 0));

    while (!pq.empty()) {
        // Get the city with the smallest distance from the priority queue
        City current = pq.top();
        pq.pop();

        int currentCity = current.index;
        int currentDistance = current.distance;

        // Ignore if the distance is already greater than the stored distance
        if (currentDistance > distances[currentCity])
            continue;

        // Iterate through all neighboring cities
        for (int neighbor = 0; neighbor < numCities; ++neighbor) {
            int weight = graph[currentCity][neighbor];

            // If there is a road and the new distance is smaller, update the distance
            if (weight > 0 && currentDistance + weight < distances[neighbor]) {
                distances[neighbor] = currentDistance + weight;
                pq.push(City(neighbor, distances[neighbor]));
            }
        }
    }

    // Output the shortest times from the source city to all other cities
    for (int city = 0; city < numCities; ++city) {
        if (city != source) {
            cout << "Shortest time from City " << source << " to City " << city << ": ";
            if (distances[city] == INF)
                cout << "Not reachable" << endl;
            else
                cout << distances[city] << endl;
        }
    }
}

int main() {
    // Define the weighted undirected graph as adjacency matrix
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int numCities = graph.size();

    // Iterate through all cities as source nodes
    for (int source = 0; source < numCities; ++source) {
        dijkstra(graph, source);
        cout << endl;
    }

    return 0;
}