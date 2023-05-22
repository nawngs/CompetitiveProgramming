#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
    string finp = NAME + ".inp";
    string fout = NAME + ".out";
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

struct Edge {
    int u, v, w, id;
    bool operator < (const Edge &oth) {
        return w < oth.w;
    }
} edges[1000003];

int par[100003], mst[1000003], p[100003][18], maxe[100003][18], up[100003], h[100003], res[1000003];

int n, m;

vector < Edge > adj[100003];

int Find(int u) {
    return (u == par[u] ? u : par[u] = Find(par[u]));
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if (u != v) {
        par[u] = v;
        return true;
    }
    else return false;
}


void dfs(int u) {
    h[u] = h[p[u][0]] + 1;
    for (auto i : adj[u]) {
        int v = i.u + i.v - u;
        if (v == p[u][0]) continue;
        p[v][0] = u;
        maxe[v][0] = i.w;
        up[v] = i.id;
        dfs(v);
    }
}

pii LCA(int u, int v) {
    int len = 0;
    if (h[u] < h[v]) swap(u, v);
    for (int i = 17; i >= 0; i--)
        if (h[p[u][i]] >= h[v]) {
            len = max(len, maxe[u][i]);
            u = p[u][i];
        }
    if (u == v)
        return make_pair(u, len);
    for (int i = 17; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            len = max(len, max(maxe[u][i], maxe[v][i]));
            u = p[u][i];
            v = p[v][i];
        }
    }
    return make_pair(p[u][0], max(len, max(maxe[u][0], maxe[v][0])));
}

int main() {
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }
    sort(edges + 1, edges + m + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= m; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (Join(u, v)) {
            adj[u].push_back(edges[i]);
            adj[v].push_back(edges[i]);
            mst[i] = 1;
        }
    }
    dfs(1);
    for (int i = 1; i <= 17; i++)
        for (int u = 1; u <= n; u++) {
            p[u][i] = p[p[u][i - 1]][i - 1];
            maxe[u][i] = max(maxe[u][i - 1], maxe[p[u][i - 1]][i - 1]);
        }
    memset(res, 255, sizeof(res));
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= m; i++) {
        if (!mst[i]) {
            int u = edges[i].u, v = edges[i].v;
            pii tmp = LCA(u, v);
            u = Find(u);
            v = Find(v);
            res[edges[i].id] = tmp.se;
            while (h[u] > h[tmp.fi]) {
                par[u] = p[u][0];
                res[up[u]] = edges[i].w;
                u = Find(u);
            }
            while (h[v] > h[tmp.fi]) {
                par[v] = p[v][0];
                res[up[v]] = edges[i].w;
                v = Find(v);
            }
        }
    }
    for (int i = 1; i <= m; i++)
        cout << (res[i] == -1 ? INF : res[i]) << '\n';
}
