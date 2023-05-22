#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int INF = 2E9;

const int nmax = 4e5;

int q, timer = 1, len[nmax + 3], id = 0, res[nmax + 3], in[nmax + 3];

vector < int > adj[nmax + 3];

vector < pii > Query[nmax + 3];

struct Node {   
    int child[2], val;
};

struct Trie_Tree {
    vector < pii > q;
    vector < Node > trie;
    void add_node() {
        Node tam;
        tam.child[0] = tam.child[1] = -1;
        tam.val = INF;
        trie.push_back(tam);
    }
    void insert(pii v) {
        q.push_back(v);
        int cur = 0;
        for (int i = 30; i >= 0; i--) {
            trie[cur].val = min(trie[cur].val, v.se);
            int bit = (v.fi >> i) & 1;
            if (trie[cur].child[bit] == -1) {
                add_node();
                trie[cur].child[bit] = trie.size() - 1;
            }
            cur = trie[cur].child[bit];
        }
        trie[cur].val = min(trie[cur].val, v.se);
    }
    void find_res(pii u) {
        int ans = 0;
        int cur = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (u.fi >> i) & 1;
            bit ^= 1;
            int nxt = trie[cur].child[bit];
            if (nxt != -1 && trie[nxt].val < u.se) {
                ans ^= (1 << i);
                cur = nxt;
            }
            else cur = trie[cur].child[bit ^ 1];
        }
        res[u.se] = ans;
    }
};

Trie_Tree dfs(int u) {
    Trie_Tree cur;
    cur.add_node();
    cur.insert({len[u], in[u]});
    //cout << u << " " << cur.q.size() << '\n';
    for (auto v : adj[u]) {
        Trie_Tree Q = dfs(v);
        if (cur.q.size() < Q.q.size())
            swap(cur, Q);
        for (auto x : Q.q)
            cur.insert(x);
    }
    // cout << u << '\n';
    // for (auto x : cur.q) cout << x.fi << " " << x.se << '\n';
    // cout << "//##############################################################################" << '\n';
    for (auto x : Query[u])
        cur.find_res(x);
    return cur;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    cin >> q;
    string s; int a, b;
    for (int i = 1; i <= q; i++) {
        cin >> s >> a >> b;
        if (s == "Add") {
            len[++ timer] = len[a] ^ b;
            in[timer] = i;
            adj[a].push_back(timer);
        }
        else Query[b].push_back({len[a], i});
    }
    memset(res, 255, sizeof(res));
    dfs(1);
    for (int i = 1; i <= q; i++)
        if (res[i] != -1) cout << res[i] << '\n';
}
