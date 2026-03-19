#include <iostream>
#include <queue>
#include <vector>

void BFS(std::vector<bool> &visited, std::queue<int> &q,
         std::vector<std::vector<int>> &adj) {
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int neighbor : adj[curr]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  std::cin >> n >> m;
  int u, v;
  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::vector<bool> visited(n + 1, false);
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }
    count++;
    std::queue<int> q;
    q.push(i);
    visited[i] = true;
    BFS(visited, q, adj);
  }
  std::cout << count << std::endl;
}