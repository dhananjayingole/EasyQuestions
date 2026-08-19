#include <bits/stdc++.h>
using namespace std;

int farthestComputer(int n, vector<vector<int>>& connections) {
    // create adjacency list
    vector<vector<int>> adj(n);
    for (const auto& conn : connections) {
        int u = conn[0];
        int v = conn[1];
        adj[u].push_back(v); // Fixed typo here
        adj[v].push_back(u);
    }

    // BFS
    vector<bool> visited(n, false);
    queue<pair<int, int>> q; // {current_computer, distance_from_0}

    // Start BFS from computer 0
    q.push({0, 0});
    visited[0] = true;

    int max_dist = 0;
    int visited_count = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        visited_count++;
        max_dist = max(max_dist, dist);

        // Check all adjacent computers
        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push({it, dist + 1});
            }
        }
    }

    // Return max_dist only if all computers were reached
    if (visited_count == n) {
        return max_dist;
    }
    return -1;
}

int main() {
    // --- Test Case 1 ---
    int n1 = 6;
    vector<vector<int>> connections1 = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {4, 5}
    };
    cout << "Example 1 Output: " << farthestComputer(n1, connections1) << " (Expected: 3)" << endl;

    // --- Test Case 2 ---
    int n2 = 5;
    vector<vector<int>> connections2 = {
        {0, 1},
        {1, 2},
        {2, 3}
    };
    cout << "Example 2 Output: " << farthestComputer(n2, connections2) << " (Expected: -1)" << endl;

    // --- Test Case 3 ---
    int n3 = 4;
    vector<vector<int>> connections3 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {0, 3}
    };
    cout << "Example 3 Output: " << farthestComputer(n3, connections3) << " (Expected: 2)" << endl;

    return 0;
}
