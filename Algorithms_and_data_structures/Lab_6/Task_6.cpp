#include <algorithm>
#include <iostream>
#include <vector>

enum Color { WHITE, GRAY, BLACK };

std::vector<std::vector<int>> adj;
std::vector<Color> color;
std::vector<int> depth;
int cycle_length = 0;
int visited_count = 0;

void DFS(int u, int p, int d) {
  color[u] = GRAY;
  depth[u] = d;
  visited_count++;

  for (int v : adj[u]) {

    if (v == p) {
      continue;
    }

    if (color[v] == WHITE) {
      DFS(v, u, d + 1);
    } else if (color[v] == GRAY) {
      cycle_length = std::abs(depth[u] - depth[v]) + 1;
    }
  }
  color[u] = BLACK;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  if (n != m || n < 3) {
    std::cout << "EUCLID";
    return 0;
  }

  adj.resize(n + 1);
  color.assign(n + 1, WHITE);
  depth.assign(n + 1, 0);

  int u, v;
  for (int i = 0; i < m; i++) {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  DFS(1, -1, 0);

  if (cycle_length >= 3 && visited_count == n) {
    std::cout << "ARCHIMEDES";
    return 0;
  }

  std::cout << "EUCLID";
  return 0;
}