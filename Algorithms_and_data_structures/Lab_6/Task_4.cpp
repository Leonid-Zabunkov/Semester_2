#include <algorithm>
#include <iostream>
#include <vector>

enum Color { WHITE, GRAY, BLACK };

std::vector<std::vector<int>> adj;
std::vector<Color> color;
bool found_cycle = false;

void DFS(int u, int p) {
  color[u] = GRAY;
  for (int v : adj[u]) {

    if (v == p) {
      continue;
    }

    if (color[v] == WHITE) {
      DFS(v, u);
    } else if (color[v] == GRAY) {
      found_cycle = true;
    }
  }
  color[u] = BLACK;
}

void DFS(int n) {
  color.assign(n + 1, WHITE);
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE) {
      DFS(i, -1);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  adj.resize(n + 1);

  int u, v;
  for (int i = 0; i < m; i++) {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  DFS(n);

  if (found_cycle) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}