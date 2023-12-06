#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
bool adjMatrix[maxn][maxn];
bool visited[maxn];

void dfs(int node) {
    cout << node << " ";
    visited[node] = true;

    for (int i = 0; i < maxn; i++) {
        if (adjMatrix[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // Initialize adjacency matrix and visited array
    memset(adjMatrix, false, sizeof(adjMatrix));
    memset(visited, false, sizeof(visited));

    // Input graph edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = adjMatrix[v][u] = true; // undirected graph
    }

    // Start DFS from node 0
    cout << "DFS Traversal:" << endl;
    dfs(0);

    return 0;
}

Input:
6 7
0 1
0 2
1 3
1 4
2 5
3 4
4 5
The output would be:
DFS Traversal:
0 1 3 4 5 2
