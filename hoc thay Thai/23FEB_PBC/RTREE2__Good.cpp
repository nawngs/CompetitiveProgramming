#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;
using pii = pair<int, int>;
#define fi first
#define se second
int n, m, sz[N], head[N],
in[N], out[N], sp[N][20], dep[N];
vector<int> adj[N];
pii ed[N];
void dfs_sz(int p, int u) {
    sz[u] = 1;
    sp[u][0] = p;
    dep[u] = dep[p]+1;
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == p) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
    for (auto &c: adj[u]) {
        dfs_sz(u, c);
        sz[u] += sz[c];
        if (sz[c] > sz[adj[u][0]]) swap(c, adj[u][0]);
    }
}

void dfs_hld(int u) {
    in[u] = ++in[0];
    if (u == 1) head[u] = 1;
    for (auto c: adj[u]) {
        head[c] = (c == adj[u][0] ? head[u] : c);
        dfs_hld(c);
    }
    out[u] = in[0];
}

pii seg[4*N];
void push(int root, int v) {
    seg[root].fi += v;
    seg[root].se += v;
}
void update(int root, int tl, int tr, int l, int r, int v) {
    if (tl > r || tr < l) return;
    if (tl >= l && tr <= r) {
        push(root, v);
        return;
    }
    int tm = (tl + tr) / 2;
    push(2*root, seg[root].se);
    push(2*root+1, seg[root].se);
    seg[root].se = 0;
    update(2*root, tl, tm, l, r, v);
    update(2*root + 1, tm +1, tr, l, r, v);
    seg[root].fi = seg[2*root].fi + seg[2*root + 1].fi;
}

int get(int root, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) return 0;
    if (tl >= l && tr <= r) return seg[root].fi;
    int tm = (tl + tr) / 2;
    push(2*root, seg[root].se);
    push(2*root+1, seg[root].se);
    seg[root].se = 0;
    return get(2*root, tl, tm, l, r) + get(2*root+1, tm+1, tr, l, r);
}
int lca(int u, int v) {
    if (dep[u]<dep[v]) swap(u, v);
    int dis = dep[u]-dep[v];
    for (int t = 18; t >= 0; t--)
    if (dis&(1<<t)) u = sp[u][t];
    if (u == v) return u;
    for (int t = 18; t >= 0; t--) {
        if (sp[u][t] != sp[v][t]) {
            u = sp[u][t];
            v = sp[v][t];
        }
    }
    return sp[u][0];
}

void upd(int u, int v) {
    //cout << "cur : " << u << " " << v << '\n';
    while (dep[u] > dep[v]) {
        update(1, 1, n, max(in[v]+1, in[head[u]]), in[u], 1);
        //cout << max(in[v]+1, in[head[u]]) << ", " << in[u] << '\n';
        u = head[u];
        u = sp[u][0];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ed[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_sz(0, 1);
    dfs_hld(1);
    for (int t = 1; t <= 18; t++)
    for (int i = 1; i <= n; i++) {
        if (sp[i][t - 1]) sp[i][t] = sp[sp[i][t - 1]][t - 1];
    }
    //for (int i = 1; i <= n; i++) cout << head[i] << ", ";
    //cout << '\n';
    for (int i = 1; i < n; i++)
        if (dep[ed[i].fi] < dep[ed[i].se])
        swap(ed[i].fi, ed[i].se);
    while (m--) {
        //cout << "trc upd : " << get(1, 1, n, in[2], in[2]) << '\n';
        //cout << "ok : " << get(1, 1, n, in[3], in[3]) << '\n';
        int c;
        cin >> c;
        if (c == 1) {
            int u, v;
            cin >> u >> v;
            int l = lca(u, v);
            upd(u, l);
            upd(v, l);
        } else {
            int i;
            cin >> i;

            cout << get(1, 1, n, in[ed[i].fi], in[ed[i].fi]) << '\n';
        }
    }

}
/*
5 5
1 2
1 3
1 4
3 5
1 1 5
1 2 4
1 2 5
2 2
2 4
*/