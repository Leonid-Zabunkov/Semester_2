#include <algorithm>
#include <iostream>
#include <vector>

enum Color { WHITE, GRAY, BLACK };

std::vector<std::vector<int>> adj, adj_rev;
std::vector<Color> color;
std::vector<int> order, component, component_id;

void visit1(int u) {
  color[u] = GRAY;
  for (int v : adj[u]) {
    if (color[v] == WHITE) {
      visit1(v);
    }
  }
  color[u] = BLACK;
  order.push_back(u);
}

void visit2(int u, int id) {
  color[u] = GRAY;
  component_id[u] = id;
  for (int v : adj_rev[u]) {
    if (color[v] == WHITE)
      visit2(v, id);
  }
  color[u] = BLACK;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m, q;
  std::cin >> n >> m >> q;

  adj.resize(n + 1);
  adj_rev.resize(n + 1);
  component_id.resize(n + 1);

  int u, v;
  for (int i = 0; i < m; i++) {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj_rev[v].push_back(u);
  }

  color.assign(n + 1, WHITE);
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE) {
      visit1(i);
    }
  }
  color.assign(n + 1, WHITE);
  std::reverse(order.begin(), order.end());

  int current_id = 0;
  for (int v : order) {
    if (color[v] == WHITE) {
      visit2(v, current_id++);
    }
  }

  int a, b;

  for (int i = 0; i < q; i++) {
    std::cin >> a >> b;
    if (component_id[a] == component_id[b]) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}