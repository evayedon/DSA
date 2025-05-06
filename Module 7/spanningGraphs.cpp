#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

// Class to represent an undirected graph
class Graph {
private:
    int V;  // Number of vertices
    unordered_map<int, list<int>> adj;  // Adjacency list representation

    // Utility function to perform DFS
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;

        for (int u : adj[v]) {
            if (!visited[u])
                DFSUtil(u, visited);
        }
    }

public:
    // Constructor
    Graph(int V) {
        this->V = V;
    }

    // Function to add an edge to the undirected graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Function to remove an edge from the graph
    void removeEdge(int u, int v) {
        // Find and remove v from adjacency list of u
        adj[u].remove(v);
        // Find and remove u from adjacency list of v
        adj[v].remove(u);
    }

    // Function to count the number of vertices reachable from v
    int countReachableVertices(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
        
        int count = 0;
        for (bool b : visited) {
            if (b) count++;
        }
        return count;
    }

    // Function to check if an edge u-v is a bridge
    // An edge is a bridge if removing it increases the number of connected components
    bool isBridge(int u, int v) {
        // If there's only one edge
        if (adj[u].size() == 1)
            return false;

        // Count reachable vertices from u
        int count1 = countReachableVertices(u);

        // Remove the edge
        removeEdge(u, v);

        // Count reachable vertices from u after removing the edge
        int count2 = countReachableVertices(u);

        // Add the edge back
        addEdge(u, v);

        // If count1 is greater, then edge u-v is a bridge
        return (count1 > count2);
    }

    // Function to check if the graph has an Eulerian path or circuit
    // Returns:
    // 0 - Graph has no Eulerian path (not connected or more than 2 odd vertices)
    // 1 - Graph has an Eulerian path but not an Eulerian circuit (exactly 2 odd vertices)
    // 2 - Graph has an Eulerian circuit (all vertices have even degree)
    int hasEulerianPathOrCircuit() {
        // Count vertices with odd degree
        int oddCount = 0;
        for (auto& p : adj) {
            if (p.second.size() & 1) {
                oddCount++;
            }
        }

        // Check if graph is connected
        if (!adj.empty()) {
            vector<bool> visited(V, false);
            int startVertex = adj.begin()->first;
            DFSUtil(startVertex, visited);

            for (auto& p : adj) {
                if (!visited[p.first])
                    return 0; // Graph is not connected
            }
        }

        // If there are more than 2 vertices with odd degree, there's no Eulerian path
        if (oddCount > 2)
            return 0;
        
        // If there are exactly 2 vertices with odd degree, there's an Eulerian path
        if (oddCount == 2)
            return 1;
        
        // If all vertices have even degree, there's an Eulerian circuit
        return 2;
    }

    // Function to find an odd degree vertex
    int findOddDegreeVertex() {
        for (auto& p : adj) {
            if (p.second.size() & 1)
                return p.first;
        }
        // If no odd vertex, return first vertex
        return adj.begin()->first;
    }

    // Fleury's Algorithm to find Eulerian path or circuit
    void fleuryAlgorithm() {
        int eulerType = hasEulerianPathOrCircuit();
        
        if (eulerType == 0) {
            cout << "The graph does not have an Eulerian path" << endl;
            return;
        }

        int startVertex;
        if (eulerType == 1) {
            // Start with an odd degree vertex for Eulerian path
            startVertex = findOddDegreeVertex();
            cout << "The graph has an Eulerian path" << endl;
        } else {
            // Start with any vertex for Eulerian circuit
            startVertex = adj.begin()->first;
            cout << "The graph has an Eulerian circuit" << endl;
        }

        // Print the Eulerian path/circuit
        cout << "Eulerian Path/Circuit: ";
        printEulerianPathOrCircuit(startVertex);
        cout << endl;
    }

    // Function to print Eulerian path or circuit
    void printEulerianPathOrCircuit(int startVertex) {
        // Create a copy of the graph
        unordered_map<int, list<int>> adjCopy = adj;

        // Use stack for DFS
        stack<int> currentPath;
        vector<int> circuit;

        // Start from the given vertex
        currentPath.push(startVertex);

        int currentVertex = startVertex;

        while (!currentPath.empty()) {
            // If current vertex has no neighbors
            if (adjCopy[currentVertex].size() == 0) {
                // Add current vertex to circuit
                circuit.push_back(currentVertex);
                // Backtrack to the last visited vertex
                currentVertex = currentPath.top();
                currentPath.pop();
            } else {
                // Push current vertex to stack
                currentPath.push(currentVertex);

                // Get next vertex from adjacency list
                int nextVertex = adjCopy[currentVertex].front();

                // If there's more than one edge, choose a non-bridge if possible
                if (adjCopy[currentVertex].size() > 1) {
                    for (int v : adjCopy[currentVertex]) {
                        if (!isBridge(currentVertex, v)) {
                            nextVertex = v;
                            break;
                        }
                    }
                }

                // Remove the edge between current vertex and chosen next vertex
                adjCopy[currentVertex].remove(nextVertex);
                adjCopy[nextVertex].remove(currentVertex);

                // Move to next vertex
                currentVertex = nextVertex;
            }
        }

        // Print the circuit in reverse order
        for (int i = circuit.size() - 1; i >= 0; i--) {
            cout << circuit[i];
            if (i > 0)
                cout << " -> ";
        }
    }

    // Function to print the graph
    void printGraph() {
        for (auto& p : adj) {
            cout << "Vertex " << p.first << ": ";
            for (int v : p.second) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Example 1: A graph with an Eulerian circuit
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);

    cout << "Graph representation:" << endl;
    g.printGraph();
    cout << endl;

    // Find and print Eulerian path or circuit
    g.fleuryAlgorithm();

    // Example 2: A graph with an Eulerian path but not a circuit
    cout << "\n\nExample 2:" << endl;
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);

    cout << "Graph representation:" << endl;
    g2.printGraph();
    cout << endl;

    // Find and print Eulerian path or circuit
    g2.fleuryAlgorithm();

    return 0;
}