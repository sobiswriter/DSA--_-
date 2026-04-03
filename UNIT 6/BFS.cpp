#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<int> adj[], int n) {
    // BFS traversal
    vector<bool> visited(n, false);
    // visited array
    queue<int> q;
    // queue for BFS

    visited[start] = true;
    // mark start visited
    q.push(start);
    // push start

    while (!q.empty()) {
        int node = q.front();
        // get front
        q.pop();
        // remove from queue

        cout << node << " ";
        // print node

        for (int neighbor : adj[node]) {
            // for each neighbor
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                // mark visited
                q.push(neighbor);
                // push to queue
            }
        }
    }
}

int main() {
    int n = 5; // number of nodes
    vector<int> adj[n];

    // edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(3);
    adj[3].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    bfs(0, adj, n);

    return 0;
}