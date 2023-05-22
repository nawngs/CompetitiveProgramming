#include <bits/stdc++.h>

using namespace std;

int n, a[10003];

bitset < 103 > dp[10003][103];

vector < int > adj[10003];

void dfs(int u) {
    dp[u][a[u]][a[u]] = 1;
    sort(adj[u].begin(), adj[u].end(), [&](int &x, int &y) {
        return a[x] < a[y];
    });
    for (auto v :adj[u]) {
        if (a[v] <= a[u]) continue;
        dfs(v);
        for (int l = 1; l <= 100; l++)
            for (int r = l; r <= 100; r++) {
                if (dp[u][l][r]) dp[u][l] |= dp[v][r + 1];
                if (dp[v][l][r]) dp[u][l] |= dp[u][r + 1];
            }
    }
    reverse(adj[u].begin(), adj[u].end());
    for (auto v :adj[u]) {
        if (a[v] >= a[u]) continue;
        dfs(v);
        for (int l = 1; l <= 100; l++)
            for (int r = l; r <= 100; r++) {
                if (dp[u][l][r]) dp[u][l] |= dp[v][r + 1];
                if (dp[v][l][r]) dp[u][l] |= dp[u][r + 1];
            }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1);
    long long res = 0;
    for (int l = 1; l <= 100; l++)
        res += 1ll * dp[1][l].count();
    cout << res;
}
