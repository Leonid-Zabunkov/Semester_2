#include <algorithm>
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

enum Color { WHITE, GRAY, BLACK };

std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<Color> color;
bool found_cycle = false;

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

void DFS(int n) {
  color.assign(n + 1, WHITE);
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE) {
      visit(i, -1);
    }
  }
}