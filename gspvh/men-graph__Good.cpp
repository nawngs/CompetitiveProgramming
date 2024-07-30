#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
const int N = 2e5 + 5;
int n, m;
vector<int> adj[N];
ll fac[N], inv[N];
ll Exp(ll a, ll b) {
    if (b == 0) return 1;
    ll tmp = Exp(a, b/2);
    tmp = tmp * tmp % mod;
    if (b&1) tmp = tmp * a % mod;
    return tmp;
}
ll Ckn(int k, int n) {
    if (k > n) return 0;
    return fac[n] * inv[k] % mod * inv[n-k] % mod;
}
ll Chon[5][N];
bool ok[N];
void add(ll &x, ll y) {
    x += y;
    if (x >= mod) x -= mod;
}
bool cmp(int i, int c) {
    if (adj[i].size() == adj[c].size()) return i < c;
    return adj[i].size() < adj[c].size();
}
ll Take(int i, int j) {
    if (i > j || j < 0) return 0;
    return Chon[i][j];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("men-graph.inp", "r", stdin);
    freopen("men-graph.out", "w", stdout);
    fac[0] = 1;
    for (int i = 1; i <= N-5; i++)
        fac[i] = fac[i-1] * i % mod;
    inv[N-5] = Exp(fac[N-5], mod-2);
    for (int i = N-6; i >= 0; i--)
        inv[i] = inv[i+1] * (i+1) % mod;
    cin >> n >> m;
    for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= n; j++)
        Chon[i][j] = Ckn(i, j);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);
        for (auto c: adj[i]) ok[c] = 1;
        for (auto c: adj[i]) {
            if (cmp(c, i)) {
                int si = adj[i].size() - 1;
                int sc = adj[c].size() - 1;
                int simp = 0;
                for (auto v: adj[c])
                    if (ok[v]) simp++;
                add(ans, Take(2, sc - simp) * Take(3, si) % mod);
                // chon 1
                add(ans, Take(1, simp) * Take(1, sc - simp) % mod * Take(3, si - 1) % mod);
                // chon 2
                add(ans, Take(2, simp) * Take(3, si - 2) % mod);
                // c 3 i 2
                // chon 0
                add(ans, Take(3, sc - simp) * Take(2, si) % mod);
                // chon 1
                add(ans, Take(1, simp) * Take(2, sc - simp) % mod * Take(2, si - 1) % mod);
                // chon 2
                add(ans, Take(2, simp) * Take(1, sc - simp) % mod * Take(2, si - 2) % mod);
                // chon 3
                add(ans, Take(3, simp) * Take(2, si - 3) % mod);

            } else break;
        }
        for (auto c: adj[i]) ok[c] = 0;
    }

    cout << ans;

}