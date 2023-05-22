#include <bits/stdc++.h>

using namespace std;

int X, Y, m, visited[1003], assigned[1003], timer = 0;

vector < int > adj[1003];

bool kuhn(int u) {
    if (visited[u] == timer) return false;
    visited[u] = timer;
    for (auto v : adj[u]) {
        if (assigned[v] == -1 || kuhn(assigned[v])) {
            assigned[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> X >> Y >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(assigned, 255, sizeof(assigned));
    int res = 0;
    for (int i = 1; i <= X; i++) {
        timer ++; res += kuhn(i);
    }
    cout << res;
}
