#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& seen) {
    seen[v] = true; cout << v << ' ';
    for (int u : g[v]) if (!seen[u]) dfs(u, g, seen);
}
void bfs(int start, const vector<vector<int>>& g) {
    vector<bool> seen(g.size(), false); queue<int> q;
    seen[start] = true; q.push(start);
    while (!q.empty()) {
        int v = q.front(); q.pop(); cout << v << ' ';
        for (int u : g[v]) if (!seen[u]) { seen[u] = true; q.push(u); }
    }
}
int main() {
    int n, m;
    cout << "Number of campus locations and paths: ";
    if (!(cin >> n >> m) || n < 1 || n > 100 || m < 0) return 1;
    vector<vector<int>> g(n);
    cout << "Enter each path as two location numbers (0 to " << n-1 << "):\n";
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        if (a < 0 || a >= n || b < 0 || b >= n) { cout << "Invalid edge.\n"; return 1; }
        g[a].push_back(b); g[b].push_back(a);
    }
    int start; cout << "Starting location: "; cin >> start;
    if (start < 0 || start >= n) { cout << "Invalid start.\n"; return 1; }
    cout << "BFS: "; bfs(start, g);
    vector<bool> seen(n, false);
    cout << "\nDFS: "; dfs(start, g, seen); cout << '\n';
    return 0;
}
