#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second
const int N = 105, INF = 1e9;
int n, row[N], col[N], co[2*N];
int a[N][N], b[N][N];
vector<pii> adj[2*N];
bool vis[2*N];
void vono() {
    cout << -1;
    exit(0);
}

vector<int> roll;
bool flag = true;
int dfs(int u, int c) {
    roll.push_back(u);
    co[u] = c;
    vis[u]=true;
    int ret = co[u];
    for (auto v: adj[u]) {
        if (vis[v.fi] && co[v.fi]!=co[u]^v.se) flag = false;
        if (!vis[v.fi]) {
            ret += dfs(v.fi, co[u]^v.se);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        row[i] = ++row[0];
    for (int j = 1; j <= n; j++)
        col[j] = ++row[0];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]*b[i][j] == 0 && a[i][j] != b[i][j])
            return cout << -1, 0;
            if (a[i][j] == b[i][j] && a[i][j])
            adj[row[i]].emplace_back(col[j], 0),
            adj[col[j]].emplace_back(row[i], 0);
            if (a[i][j] != b[i][j])
            adj[row[i]].emplace_back(col[j], 1),
            adj[col[j]].emplace_back(row[i], 1);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (auto c: adj[row[1]]) cout << c.fi << ", " << c.se << '\n';
    }
    */
    int res = 0;
    memset(vis, 0, sizeof vis);
    memset(co, -1, sizeof co);
    for (int i = 1; i <= row[0]; i++) {
        if (co[i] == -1) {
            flag = true;
            roll.clear();
            int v1 = dfs(i, 0);
            if (!flag) v1 = INF;
            flag = true;
            for (auto c: roll) vis[c]=false, co[c]=-1;
            roll.clear();
            int v2 = dfs(i, 1);
            if (!flag) v2 = INF;
            int v = min(v1, v2);
            if (v == INF) vono();
            res += v;
        }
    }
    /*
    if (color == 0) {
        for (int i = 1; i <= n; i++) {
            cout << "row " << i << "::" << co[row[i]] << '\n';
        }
        for (int j = 1; j <= n; j++) {
            cout << "col " << j << "::" << co[col[j]] << '\n';
        }
    }
    */

    cout << res;
}
/*
2
-1 0
0 1
1 0
0 1
*/