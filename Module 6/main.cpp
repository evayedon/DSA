#include <iostream>
#include "depthFirst.h"
#include "breadthFirst.h"

using namespace std;


int main() {
    GraphforDFS g;
    g.addEdge(1, 20);
    g.addEdge(1, 30);
    g.addEdge(5, 30);
    g.addEdge(5, 10);
    g.addEdge(2, 40);
    g.addEdge(40, 40);
    
    cout << "Depth-First Traversal (starting from vertex 2):" << endl;
    vector<int> dfsResult = g.dfs(2);
    
    for (int vertex : dfsResult) {
        cout << vertex << " ";
    }
    cout << endl << endl;

    cout << "Breadth-First Traversal" << endl << endl;
    GraphForBFS g1;
    g1.addEdge(5, 3);
    g1.addEdge(5, 3);
    g1.addEdge(2, 3);
    g1.addEdge(9, 4);
    g1.addEdge(2, 12);
    g1.addEdge(2, 12);
    
    cout << "Breadth-First Traversal (starting from vertex 2):" << endl;
    vector<int> bfsResult = g1.bfs(2);
    
    for (int vertex : bfsResult) {
        cout << vertex << " ";
    }
    cout << endl;
    
    return 0;
}