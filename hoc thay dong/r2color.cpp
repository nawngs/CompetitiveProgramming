#include <bits/stdc++.h>

using namespace std;

const int NMAX = 3E5;
const int INF = 1E9 + 7;

int n, m, color[NMAX + 3], vs[NMAX + 3], timer = 0, dem = 0, a[NMAX + 3];

bool change[NMAX + 3];

vector < int > adj[NMAX + 3];

void reset(int u) {
    if (vs[u] == timer) return ;
    color[u] = a[u];
    vs[u] = timer;
    for (auto v : adj[u]) reset(v);
}

void dfs(int u, int c, int &dem) {
    if ((vs[u] == timer || change[u] == 0) && color[u] != c) {
        dem = INF;
        return ;
    }
    if (vs[u] == timer) return ;
    vs[u] = timer;
    if (color[u] != c) {
        dem ++;
        color[u] = c;
    }
    for (auto v : adj[u])
        dfs(v, (c == 1 ? 2 : 1) , dem);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
        a[i] = color[i];
    }
    for (int i = 1; i <= n; i++) cin >> change[i];
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (!vs[i]) {
        timer ++; dem = 0; dfs(i, 1, dem);
        int tam = dem;
        timer ++; reset(i);
        timer ++; dem = 0; dfs(i, 2, dem);
        tam = min(tam, dem);
        if (tam >= n) {
            cout << -1 << '\n';
            return 0;
        }
        ans += tam;
    }
    cout << ans;
}
