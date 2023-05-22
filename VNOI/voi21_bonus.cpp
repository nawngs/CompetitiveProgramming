#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

using namespace std;

struct Node {
    int nxt[26];
    ll val;
};

const int BLOCK = 650;
const int NMAX = 1E5;
const int MMAX = 3E5;

using Trie = vector < Node >;

int n, m, id[300003], connected[NMAX + 5][MMAX / BLOCK + 3];

ll f[NMAX + 3], g[NMAX + 3];

pair < string, int > a[300003];

vector < int > adj[NMAX + 3], big;

Trie Tree;

void add_node() {
    Node x;
    for (int i = 0; i < 26; i++) x.nxt[i] = -1;
    x.val = 0;
    Tree.push_back(x);
}

pair < ll, int > add_string(const string &s) {
    int node = 0;
    ll res = 0;
    for (auto c : s) {
        res = max(res, Tree[node].val);
        if (Tree[node].nxt[c - 'A'] == -1) {
            Tree[node].nxt[c - 'A'] = Tree.size();
            add_node();
        }
        node = Tree[node].nxt[c - 'A'];
    }
    return make_pair(res, node);
}

int main() {
    cin >> n >> m;
    for (int i = n; i >= 1; i--)
        cin >> a[i].fi >> a[i].se;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    memset(id, 255, sizeof(id));
    for (int i = 1; i <= NMAX; i++)
        if (adj[i].size() >= BLOCK) {
            id[i] = big.size();
            big.push_back(i);
        }
    for (int i = 1; i <= NMAX; i++)
        for (auto x : adj[i])
            if (id[x] != -1)
                connected[i][id[x]] = 1;
    add_node();
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int u = a[i].se;
        ll curdp = f[u];
        if (adj[u].size() < BLOCK)
            for (auto v : adj[u])
                curdp = max(curdp, g[v] + u);
        for (auto v : big)
            if (connected[u][id[v]]) curdp = max(curdp, g[v] + u);
        pair < ll, int > temp = add_string(a[i].fi);
        curdp = max(curdp, temp.fi + u); Tree[temp.se].val = max(Tree[temp.se].val, curdp);
        res = max(res, curdp); g[u] = max(g[u], curdp);
        if (adj[u].size() < BLOCK)
            for (auto v : adj[u])
                f[v] = max(f[v], curdp + v);
        /*int u = a[i].se;
        curdp = f[u];
        curdp = max(curdp, add_string(a[i].fi, u)); update(a[i].fi, curdp);
        res = max(res, curdp);
        for (auto v : adj[u])
            f[v] = max(f[v], curdp + v);*/
    }
    cout << res;
}
