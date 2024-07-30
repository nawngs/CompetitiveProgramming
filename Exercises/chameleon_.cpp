#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const int N = 2e5 + 5;
int n, m, a, b, c;
void add(ll&x, ll y) {
    x += y;
    if (x >= mod) x-=mod;
}
using pii = pair<int, int>;
#define fi first
#define se second
pii ed[N];
vector<int> adj[N];
int num[N], low[N], sz[N], in[N], out[N];
bool cau[N], used[N];

void dfs(int u) {
    num[u] = low[u] = ++num[0];
    in[u] = ++in[0];
    for (auto c: adj[u]) {
        if (used[c]) continue;
        int v = ed[c].fi + ed[c].se - u;

        used[c] = 1;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
                cau[c] = 1;
        }
    }
    out[u] = in[0];
}

int f[105][105], g[105][105];

bool vis[105];
void dfs1(int u) {
    vis[u] = 1;
    for (auto c: adj[u]) {
        if (used[c]) continue;
        int v = ed[c].fi + ed[c].se - u;
        if (vis[v]) continue;
        dfs1(v);
    }
}

void dfs2(int u) {
    if (used[u]) return;
    vis[u] = 1;
    for (auto c: adj[u]) {
        int v = ed[c].fi + ed[c].se - u;
        if (used[v]) continue;
        if (vis[v]) continue;
        dfs2(v);
    }
}
void solve1() {
    memset(used, 0, sizeof used);
    for (int i = 1; i <= m; i++) {
        used[i] = 1;
        for (int j = 1; j <= n; j++) {
            memset(vis, 0, sizeof vis);
            dfs1(j);
            for (int k = j+1; k <= n; k++)
                if (!vis[k]) f[j][k]++;
        }
        used[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        used[i] = 1;
        for (int j = 1; j <= n; j++) {
            memset(vis, 0, sizeof vis);
            dfs2(j);
            for (int k = j+1; k <= n; k++)
                if (!vis[k]) g[j][k]++;
        }
        used[i] = 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            ll v = (1LL*f[i][j]*a%mod + 1LL*g[i][j]*b%mod)%mod;
            if (c == 1) add(ans, v);
            else add(ans, v*v%mod);
        }
    }
    cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("chameleon.inp", "r", stdin);
	freopen("chameleon.out", "w", stdout);
    cin >> n >> m >> a >> b >> c;
    for (int i = 1; i <= m; i++) {
        cin >> ed[i].fi >> ed[i].se;
        adj[ed[i].fi].push_back(i);
        adj[ed[i].se].push_back(i);
    }
    if (n <= 100) return solve1(), 0;
    assert(0);
    // else if (b == 0 && c == 1) solve2();
    // else if (a == 0 && c == 1) solve3();
}