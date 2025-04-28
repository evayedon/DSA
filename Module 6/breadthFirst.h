#ifndef BREADTH_FIRST_H
#define BREADTH_FIRST_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class GraphForBFS {
private:
    // Adjacency list representation
    unordered_map<int, vector<int>> adjacencyList;

public:
    // Add an edge from vertex u to vertex v
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }

    // BFS traversal starting from a given vertex
    vector<int> bfs(int startVertex) {
        unordered_set<int> visited;
        queue<int> queue;
        vector<int> result;
        
        // Mark the start vertex as visited and enqueue it
        visited.insert(startVertex);
        queue.push(startVertex);
        
        while (!queue.empty()) {
            // Dequeue a vertex from queue
            int vertex = queue.front();
            queue.pop();
            result.push_back(vertex);
            
            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent vertex hasn't been visited, mark it visited and enqueue it
            if (adjacencyList.find(vertex) != adjacencyList.end()) {
                for (int neighbor : adjacencyList[vertex]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        queue.push(neighbor);
                    }
                }
            }
        }
        
        return result;
    }
};

#endif // BREADTH_FIRST_H