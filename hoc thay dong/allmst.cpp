#include <bits/stdc++.h>

#define int long long
#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int NMAX = 1e6;
const int LG = 20;

struct Edge {
    int u, v, c, id;
	Edge(int _u, int _v, int _c, int _id) : u(_u), v(_v), c(_c), id(_id) {};
};

vector < Edge > edges;

int n, m, par[NMAX + 3], p[NMAX + 3][LG + 3], h[NMAX + 3], val[NMAX + 3][LG + 3];

bool used[NMAX + 3];

vector < pii > adj[NMAX + 3];

int find(int u) {
    if (u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    par[u] = v;
    return true;
}

void dfs(int u) {
    h[u] = h[p[u][0]] + 1;
    for (int i = 1; i <= LG; i++) {
        p[u][i] = p[p[u][i - 1]][i - 1];
        val[u][i] = max(val[u][i - 1], val[p[u][i - 1]][i - 1]);
    }
    for (auto v : adj[u]) {
        if (v.fi == p[u][0]) continue;
        p[v.fi][0] = u; val[v.fi][0] = v.se;
        dfs(v.fi);
    }
}

int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int res = 0;
    for (int i = LG; i >= 0; i--)
        if (h[p[u][i]] >= h[v]) {
            res = max(res, val[u][i]);
            u = p[u][i];
        }
    if (u == v) return res;
    for (int i = LG; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            res = max(res, max(val[u][i], val[v][i]));
            u = p[u][i]; v = p[v][i];
        }
    }
    res = max(res, max(val[u][0], val[v][0]));
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges.push_back({u, v, c, i});
    }
    sort(edges.begin(), edges.end(), [](Edge &x, Edge &y) {
        return x.c < y.c;
    });
    for (int i = 1; i <= n; i++) par[i] = i;
    long long ans = 0;
    for (auto e : edges) {
        if (join(e.u, e.v)) {
            ans += e.c;
            used[e.id] = 1;
            adj[e.u].push_back({e.v, e.c}); adj[e.v].push_back({e.u, e.c});
        }
    }
    dfs(1);
     sort(edges.begin(), edges.end(), [](Edge &x, Edge &y) {
        return x.id < y.id;
    });
    for (auto e : edges) {
        if (used[e.id]) cout << ans << '\n';
        else cout << ans - LCA(e.u, e.v) + e.c << '\n';
    }
}
