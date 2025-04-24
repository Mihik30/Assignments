#include <iostream>
using namespace std;

const int MAX = 100;     // Maximum number of departments (nodes)
const int INF = 9999;    // A large value to represent infinity (for unreachable paths)

int cost[MAX][MAX];      // Adjacency matrix: cost[i][j] = weight of edge from i to j
bool visited[MAX];       // Tracks whether a node is included in MST
int parent[MAX];         // parent[i] = the node through which i is connected in MST
int key[MAX];            // key[i] = minimum weight edge to include i in MST
int n;                   // Number of departments (nodes)

// Function to find the unvisited node with the minimum key value
int minKey() {
    int min = INF, idx = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            idx = i;
        }
    }
    return idx;
}

// Main Prim’s algorithm
void prim() {
    // Initialize keys as INF, visited as false, and parent as -1
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    // Start from the first department (node 0)
    key[0] = 0;

    // Run n-1 times to include all nodes in MST
    for (int i = 0; i < n - 1; i++) {
        int u = minKey();        // Pick the node with the smallest key value
        visited[u] = true;       // Mark it as part of MST

        // Update keys and parent for adjacent vertices
        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !visited[v] && cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    // Print the MST
    cout << "\nMinimum Spanning Tree (MST):\n";
    for (int i = 1; i < n; i++) {
        cout << "Dept " << parent[i] << " - Dept " << i
             << " : Distance = " << cost[i][parent[i]] << "\n";
    }
}

int main() {
    cout << "Enter number of departments: ";
    cin >> n;

    cout << "Enter distance matrix (0 if no direct path):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    prim();

    return 0;
}
