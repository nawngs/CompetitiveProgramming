#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, b, c[5003], d[5003], dp[5003][5003][2], cnt_child[5003];

vector < int > adj[5003];

void dfs(int u) {
    dp[u][0][0] = 0;
    dp[u][1][0] = c[u];
    dp[u][1][1] = c[u] - d[u];
    cnt_child[u] = 1;
    int &sze = cnt_child[u];
    for (auto v : adj[u]) {
        dfs(v);
        for (int i = sze; i >= 0; i--)
            for (int j = 0; j <= cnt_child[v]; j++) {
                dp[u][i + j][0] = min(dp[u][i + j][0], dp[u][i][0] + dp[v][j][0]);
                dp[u][i + j][1] = min(dp[u][i + j][1], dp[u][i][1] + min(dp[v][j][1], dp[v][j][0]));
            }
        sze += cnt_child[v];
    }
}

main() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
        if (i != 1) {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }
    memset(dp, 64, sizeof(dp));
    dfs(1);
    for (int i = n; i >= 0; i--) {
        if (dp[1][i][0] <= b || dp[1][i][1] <= b) {
            cout << i << '\n';
            return 0;
        }
    }
}
