#include <bits/stdc++.h>

using namespace std;

int n, q, par[100003], Cnt[100003];

vector < int > adj[100003];

int timer = 0, in[100003], chain_id[100003], chain_head[100003], nchain = 0, Val[100003];

void dfs(int u) {
    Cnt[u] = 1;
    for (auto v : adj[u]) {
        if (v == par[u]) continue;
        par[v] = u; dfs(v);
        Cnt[u] += Cnt[v];
    }
}

void hld(int u) {
    in[u] = ++ timer;
    Val[timer] = u;
    chain_id[u] = nchain;
    if (!chain_head[nchain]) chain_head[nchain] = u;
    int maxv = -1;
    for (auto v : adj[u]) {
        if (v == par[u]) continue;
        if (maxv == -1 || Cnt[v] > Cnt[maxv]) maxv = v;
    }
    if (maxv != -1) hld(maxv);
    for (auto v : adj[u]) {
        if (v == par[u] || v == maxv) continue;
        nchain ++;
        hld(v);
    }
}

int it[400003];

#define lnode node * 2, l, mid
#define rnode node * 2 + 1, mid + 1, r

void build(int node, int l, int r) {
    it[node] = n + 1;
    if (l == r) return ;
    int mid = (l + r) / 2;
    build(lnode); build(rnode);
}

void update(int node, int l, int r, int pos) {
    if (pos < l || pos > r) return ;
    if (l == r) {
        it[node] = (it[node] == pos ? n + 1 : pos);
        return ;
    }
    int mid = (l + r) / 2;
    update(lnode, pos); update(rnode, pos);
    it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
    if (v < l || r < u) return n + 1;
    if (u <= l && r <= v) return it[node];
    int mid = (l + r) / 2;
    return min(query(lnode, u, v), query(rnode, u, v));
}

int query(int u) {
    int id = chain_id[u];
    int res = n + 1;
    while (1) {
        if (id == chain_id[1]) {
            res = min(res, query(1, 1, n, in[1], in[u]));
            break;
        }
        res = min(res, query(1, 1, n, in[chain_head[id]], in[u]));
        u = par[chain_head[id]]; id = chain_id[u];
    }
    return (res == n + 1 ? -1 : Val[res]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1); hld(1);
    build(1, 1, n);
    while (q--) {
        int t, x; cin >> t >> x;
        if (t == 0) update(1, 1, n, in[x]);
        else {
            cout << query(x) << '\n';
        }
    }
}
