#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
bool adjMatrix[maxn][maxn];
bool visited[maxn];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int i = 0; i < maxn; i++) {
            if (adjMatrix[curr][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int node, edges;
    cin >> node >> edges;

    // Initialize adjacency matrix and visited array
    memset(adjMatrix, false, sizeof(adjMatrix));
    memset(visited, false, sizeof(visited));

    // Input graph edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = adjMatrix[v][u] = true; // undirected graph
    }

    // Start BFS from node 0
    bfs(0);

    return 0;
}

INPUT:
6 7
0 1
0 2
1 3
1 4
2 5
2 6
4 5
Output:
0 1 2 3 4 5 6
