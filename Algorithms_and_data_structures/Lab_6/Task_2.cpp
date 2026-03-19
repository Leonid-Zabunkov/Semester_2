#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

void BFS(std::vector<int> &dist, std::queue<int> &q,
         std::vector<std::vector<int>> &adj) {
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int neighbor : adj[curr]) {
      if (dist[neighbor] == -1) {
        dist[neighbor] = dist[curr] + 1;
        q.push(neighbor);
      }
    }
  }
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m, k;
  std::cin >> n;
  std::cin >> m >> k;
  
  int u, v;
  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::vector<int> dist(n + 1, -1);
  std::queue<int> q;

  dist[1] = 0;
  q.push(1);
  BFS(dist, q, adj);

  bool found = false;
  for (int i = 1; i <= n; i++) {
    if (dist[i] == k) {
      std::cout << i << "\n";
      found = true;
    }
  }
  if (!found) {
    std::cout << "NO" << std::endl;
  }
}