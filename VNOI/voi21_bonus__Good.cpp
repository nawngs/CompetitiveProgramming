#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

using namespace std;

struct Node {
    int nxt[26];
    ll val;
};

const int BLOCK = 320;
const int NMAX = 1E5;

using Trie = vector < Node >;

int n, m, id[300003], connected[BLOCK + 5][BLOCK + 5];

ll f[NMAX + 3];

pair < string, int > a[300003];

vector < int > adj[NMAX + 3], big;

Trie Tree;

void add_node() {
    Node x;
    for (int i = 0; i < 26; i++) x.nxt[i] = -1;
    x.val = 0;
    Tree.push_back(x);
}

ll add_string(const string &s, int v) {
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
    res += 1ll * v;
    Tree[node].val = max(Tree[node].val, res);
    return res;
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
                connected[id[i]][id[x]] = 1;
    add_node();
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int u = a[i].se;
        ll cur = f[u];
        if (adj[u].size() < BLOCK)
            for (auto v : adj[u])
                cur = max(cur, f[v] + u);
        else {
            for (auto v : big)
                if (connected[id[u]][id[v]]) cur = max(cur, f[v] + u);
        }
        cur = max(cur, add_string(a[i].fi, u));
        res = max(res, cur);
        f[u] = max(f[u], cur);
        if (adj[u].size() <= BLOCK)
            for (auto v : adj[u])
                f[v] = max(f[v], f[u] + v);
    }
    cout << res;
}
