#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;
const ll oo = 1e15;

int n;
vector<pi> adj[N];
ll h[N], d[N], f[N], g[N];
ll ans;
struct options{
    ll st, nd, rd;
};

void dfs(int u, int pu){
    pi mx = {0, 0};
    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;

        dfs(v, u);

        ll tmp = h[v] + w;

        h[u] = max(h[u], tmp);
        if ( mx.fi < tmp ) mx = {tmp, mx.fi};
        else if ( mx.se < tmp ) mx = {mx.fi, tmp};
        f[u] = max(f[u], f[v]);
    }
    f[u] = max({f[u], h[u], mx.fi + mx.se});
}

void go(int u, int pu){
    options opt = {0, 0, 0};
    pi mx = {0, 0};
    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;

        ll tmp = h[v] + w;

        if ( opt.st < tmp ) opt = {tmp, opt.st, opt.nd};
        else if ( opt.nd < tmp ) opt = {opt.st, tmp, opt.nd};
        else if ( opt.rd < tmp ) opt = {opt.st, opt.nd, tmp};

        if ( mx.fi < f[v] ) mx = {f[v], mx.fi};
        else if ( mx.se < f[v] ) mx = {mx.fi, f[v]};
    }

    for (auto it : adj[u]){
        int v = it.fi, w = it.se;

        if ( v == pu ) continue;

        ll tmp = 0;

        // cap nhat d[v]
        if ( opt.st == h[v]+w ) tmp = opt.nd + w;
        else tmp = opt.st + w;
        d[v] = max(d[u]+w, tmp);

        // lay thang d[u] + thang dai nhat la anh em cua v
        g[v] = max(g[u], tmp+d[u]);
        tmp = ( mx.fi == f[v] ? mx.se : mx.fi );
        // dia dai nhat la anh em cua v
        g[v] = max(g[v], tmp);

        // lay 2 thang dai nhat la anh em cua v
        tmp = opt.st + opt.nd;
        if ( opt.st == h[v]+w ) tmp += -opt.st + opt.rd;
        else if ( opt.nd == h[v]+w ) tmp += -opt.nd + opt.rd;
        g[v] = max(tmp, g[u]);

        ans = min(ans, abs(g[v]-f[v]));

        g[v] = max(g[v], d[v]);

        go(v, u);
    }
}

void solve(){
    ans = oo;
    for (int i = 1; i <= n; i ++){
        adj[i].clear();
        f[i] = g[i] = d[i] = h[i] = 0;
    }

    for (int i = 2, p, l; i <= n; i ++){
        cin >> p >> l;
        adj[p].pb({i, l});
        adj[i].pb({p, l});
    }

    dfs(1, 0);

    
    go(1, 0);

//    for (int i = 1; i <= n; i ++)
//        cout << f[i] << ' ' << g[i] << '\n';

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("K.inp", "r") ){
        freopen("K.inp", "r", stdin);
        freopen("K.out", "w", stdout);
    }

    while ( cin >> n )
        if ( n ) solve();
        else break;

    return 0;
}
