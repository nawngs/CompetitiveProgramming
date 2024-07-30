#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb emplace_back
#define pf emplace_front
#define fi first
#define se second
#define T pair<int,int>
#define all(val) val.begin(), val.end()
#define SZ(val) (int)val.size()
#define db(val) "[" #val " = " << (val) << "] "

const int maxn = 1e5 + 4;
const int N = 18;
const int mod = 1e9 + 7;
const int INF = 1e9;

void coding() {
    if (fopen("inputf.in", "r")) {
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
        freopen("log.out", "w", stderr);
    }
    if (fopen("BUILDTREE.INP", "r")) {
        freopen("BUILDTREE.INP", "r", stdin);
        freopen("BUILDTREE.OUT", "w", stdout);
    }
}

int n, m, wgh[maxn], sz[maxn], res;
vector<T> adj[maxn];

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto it : adj[u]) {
        int v, w; tie(v, w) = it;
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int dfs(int u, int p, int tot) {
    for (auto it : adj[u])
        if (it.fi != p && sz[it.fi] > tot / 2)
            return dfs(it.fi, u, tot);
    return u;
}

void dfs2(int u, int p) {
    sz[u] = 1;
    for (auto it : adj[u]) {
        int v, w; tie(v, w) = it;
        if (v == p) continue;
        dfs2(v, u);
        sz[u] += sz[v];
        res += 1LL * sz[v] * (n - sz[v]) % mod * w % mod;
        res %= mod;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // coding();
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> wgh[i];
    for (int i = 1, u, v, w; i < n - m; i++) {
        cin >> u >> v >> w;
        adj[u].pb(v, w);
        adj[v].pb(u, w);
    }
    vector<int> nodes;
    for (int i = 1; i <= n; i++) if (!sz[i]) {
        dfs(i, 0);
        int c = dfs(i, 0, sz[i]);
        cout << c << '\n';
        nodes.pb(c);
        dfs(c, 0);
    }
    sort(all(nodes), [](int u, int v) {
        return sz[u] < sz[v];
    });
    dfs2(43540, 0);
    cout << res;
    return 0;
    sort(wgh + 1, wgh + 1 + m, greater<int>());
    for (int i = 1; i <= m; i++)
        adj[nodes.back()].pb(nodes[i - 1], wgh[i]);
    dfs2(nodes.back(), 0);
    cout << res;
}

