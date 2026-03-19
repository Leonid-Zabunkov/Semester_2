#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<bool> visited;

bool visit(int u, int p) {
  visited[u] = true;
  for (int v : adj[u]) {
    if (!visited[v]) {
      if (visit(v, u))
        return true;
    } else if (v != p) {
      return true;
    }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  adj.resize(n + 1);
  visited.assign(n + 1, false);

  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      if (visit(i, -1)) {
        std::cout << "YES" << std::endl;
        return 0;
      }
    }
  }

  std::cout << "NO" << std::endl;
  return 0;
}