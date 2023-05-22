#include <bits/stdc++.h>

using namespace std;

int n, m, num[100003], low[100003], bridges = 0, timer = 0;

bool joint[100003];

vector < int > adj[100003];

void dfs(int u, int e) {
    num[u] = low[u] = ++ timer;
    int cnt = 0;
    for (auto v : adj[u]) {
        if (v == e) continue;
        if (!num[v]) {
            cnt ++; dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) bridges ++;
            if (e == 0 && cnt > 1) joint[u] = true;
            if (e != 0 && low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
     }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) if (!num[i]) dfs(i, 0);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += joint[i];
    cout << res <<  " " << bridges << '\n';
}
