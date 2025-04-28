#include <iostream>
#include "depthFirst.h"
#include "breadthFirst.h"

using namespace std;


int main() {
    GraphforDFS g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Depth-First Traversal (starting from vertex 2):" << endl;
    vector<int> dfsResult = g.dfs(2);
    
    for (int vertex : dfsResult) {
        cout << vertex << " ";
    }
    cout << endl << endl;

    cout << "Breadth-First Traversal" << endl;
    GraphForBFS g1;
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    g1.addEdge(3, 3);
    
    cout << "Breadth-First Traversal (starting from vertex 2):" << endl;
    vector<int> bfsResult = g1.bfs(2);
    
    for (int vertex : bfsResult) {
        cout << vertex << " ";
    }
    cout << endl;
    
    return 0;
}