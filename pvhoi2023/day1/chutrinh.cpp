#include <bits/stdc++.h>

#define ll long long
#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const ll MOD = 1E9 + 19972207;

int n;

pii edges[150003];

vector < int > adj[150003];

ll q, seed, mul, add, cnt = 0, cur = 0, deg[1500003];

ll get_random(int n) {
    cur = (mul * cur + add) % MOD;
    return 1 + cur % n;
}

void back_track(int pos) {
    if (pos == n) {
        for (int i = 1; i <= n; i++) if (deg[i] != 2 && deg[i] != 0) return ;
        cnt ++;
        return ;
    }
    for (int i = 0; i < 2; i++) {
        if (i == 1) deg[edges[pos].fi] ++, deg[edges[pos].se] ++;
        back_track(pos + 1);
        if (i == 1) deg[edges[pos].fi] --, deg[edges[pos].se] --;
    }
}

int query(int e1, int u1, int v1, int e2, int u2, int v2) {
    pii temp1 = edges[e1], temp2 = edges[e2];
    edges[e1] = {u1, v1}; adj[u1].push_back(e1); adj[v1].push_back(e1);
    edges[e2] = {u2, v2}; adj[u2].push_back(e2); adj[v2].push_back(e2);
    cnt = -1;
    back_track(1);
    edges[e1] = temp1, edges[e2] = temp2;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("chutrinh.inp", "r", stdin);
    freopen("chutrinh.out", "w", stdout);
    int O; cin >> O;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(i); adj[v].push_back(i);
        edges[i] = {u, v};
    }
    cin >> q >> seed >> mul >> add;
    cur = seed;
    ll res = 0;
    for (int i = 1; i <= q; i++) {
        int e1 = get_random(n - 1);
        int u1 = get_random(n), v1 = get_random(n);
        int e2 = get_random(n - 1);
        int u2 = get_random(n), v2 = get_random(n);
        int tmp =  e1 == e2 || u1 == v1 || u2 == v2 ? MOD - 1 : query(e1, u1, v1, e2, u2, v2);
        res = (227ll * res + tmp) % MOD;
    }
    cout << res;
}



