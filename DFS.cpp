#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[v] = true;
    cout << v << "-> ";
    for(auto child:adj[v]){
        if(!visited[child]){
            dfs(child,adj,visited);
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> adj(vertices + 1);
    vector<bool> visited(vertices + 1, false);

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, adj, visited);

    return 0;
}
