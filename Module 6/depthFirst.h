#ifndef DEPTH_FIRST_H
#define DEPTH_FIRST_H


#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

class GraphforDFS {
    private:
        // Adjacency list representation
        unordered_map<int, vector<int>> adjacencyList;
    
        // Recursive helper function for DFS
        void dfsHelper(int vertex, unordered_set<int>& visited, vector<int>& result) {
            // Mark the current vertex as visited and add to result
            visited.insert(vertex);
            result.push_back(vertex);
    
            // Recur for all adjacent vertices if they haven't been visited
            if (adjacencyList.find(vertex) != adjacencyList.end()) {
                for (int neighbor : adjacencyList[vertex]) {
                    if (visited.find(neighbor) == visited.end()) {
                        dfsHelper(neighbor, visited, result);
                    }
                }
            }
        }
    
    public:
        // Add an edge from vertex u to vertex v
        void addEdge(int u, int v) {
            adjacencyList[u].push_back(v);
        }
    
        // DFS traversal starting from a given vertex
        vector<int> dfs(int startVertex) {
            unordered_set<int> visited;
            vector<int> result;
            
            dfsHelper(startVertex, visited, result);
            
            return result;
        }
};

#endif // DEPTH_FIRST_H    