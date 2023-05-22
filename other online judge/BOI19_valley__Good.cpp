/*
**  TASK: 
**  LINK: 
*/
 
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define st first
#define nd second
#define file "test"
using namespace std;
const long long INF = 1e18;
const long long N = 2e5 + 5;
 
struct edge {
    ll u, v, w, id;
} g[N];
 
ll n, s, q, e, shop[N], up[20][N], h[N], dpUp[20][N], f[N], dp[N];
vector <int> d[N];
 
void dfs(int p, int u) {
    for (int i: d[u]) {
        int v = g[i].u ^ g[i].v ^ u, w = g[i].w;
        if (v == p) continue;
        h[v] = h[u] + 1; up[0][v] = u; f[v] = f[u] + w;
        for (int j = 1; j < 20; j ++)
            up[j][v] = up[j - 1][up[j - 1][v]];
        dfs(u, v);
        dp[u] = min(dp[u], dp[v] + w);
    }
}
 
void dfs2(int p, int u) {
    for (int i: d[u]) {
        int v = g[i].u ^ g[i].v ^ u, w = g[i].w;
        if (v == p) continue;
        g[i].u = u; g[i].v = v;
        dpUp[0][v] = dp[u] - f[u];
        for (int j = 1; j < 20; j ++)
            dpUp[j][v] = min(dpUp[j - 1][v], dpUp[j - 1][up[j - 1][v]]);
        dfs2(u, v);
    }    
}
 
int jump(int u, int k) {
    for (int i = 19; i >= 0; i --) if ((k >> i) & 1) u = up[i][u];
    return u;
}
 
bool isANC(int p, int u) {
    int delta = h[u] - h[p];
    return jump(u, delta) == p;
}
 
ll get(int u, int k) {
    ll ans = INF;
    for (int i = 19; i >= 0; i --) if ((k >> i) & 1) {
        ans = min(ans, dpUp[i][u]);
        u = up[i][u];
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> s >> q >> e;
    for (int i = 1; i < n; i ++) {
        cin >> g[i].u >> g[i].v >> g[i].w;
        g[i].id = i;
        d[g[i].u].push_back(i);
        d[g[i].v].push_back(i);
    }
 
    for (int i = 0; i < 20; i ++)
        for (int j = 1; j <= n; j ++)
            dpUp[i][j] = INF;
 
    for (int i = 1, x; i <= s; i ++) 
        cin >> x, shop[x] = true;
 
    for (int i = 1; i <= n; i ++)
        if (shop[i]) dp[i] = 0; else dp[i] = INF;
 
    // "e" is root
    dfs(e, e);
    dfs2(e, e);
    int I, R;
    while (q --) {
        cin >> I >> R;
        
        int u = g[I].u, v = g[I].v;
        if (!isANC(v, R)) {
            cout << "escaped\n";
            continue;
        }
 
        if (dp[v] == INF) {
            cout << "oo\n";
            continue;
        }
 
        cout << min(f[R] + get(R, h[R] - h[v]), dp[R]) << '\n';
 
    }
 
    return 0;
}    
/**  /\_/\
*   (= ._.)
*   / >🍵 \>🍮
**/