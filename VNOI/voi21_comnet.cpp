#include <bits/stdc++.h>

using namespace std;

int n, k, a, b;

long long dp[1003][1003][5], res = 0;

int s[1003][5];

vector < int > adj[1003];

void dfs(int u, int e) {
    dp[u][0][1] = 1; dp[u][0][0] = 1;
    for (auto v : adj[u]) {
        if (v == e) continue;
        dfs(v, u);
        for (int i = k; i >= 0; i--)
            for (int vi = b; vi >= 0; vi--)
                for (int j = 1; j <= i; j++)
                    for (int vj = 0; vj <= min(vi - 1, s[v][j]); vj++) {
                        if (vi - vj - 1 > s[u][i - j]) continue;
                        dp[u][vi][i] += dp[u][vi - vj - 1][i - j] * dp[v][vj][j];
                        if (i == k && vi >= a && i - j != 0)  res += dp[u][vi - vj - 1][i - j] * dp[v][vj][j];
                        s[u][i] = max(s[u][i], vi);
                    }
    }
}

int main() {
    cin >> n >> k >> a >> b;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << res;
}


