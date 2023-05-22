#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

struct Rec {
    int bot, top, left,right;
} a[100003];

struct Segment {
    int l, r, id;
    Segment(int _l, int _r, int _id) {
        l = _l, r = _r, id = _id;
    }
    bool operator < (const Segment &oth) {
        if (l != oth.l) return l < oth.l;
        return r < oth.r;
    }
};

struct Edge {
    int u, v;
    bool bridge;
    Edge (int _u, int _v) {
        u = _u, v = _v;
        bridge = 0;
    }
    bool operator < (const Edge &oth) {
        return make_pair(u, v) < make_pair(oth.u, oth.v);
    }
    bool operator == (const Edge &oth) {
        return u == oth.u && v == oth.v && bridge == oth.bridge;
    }
};

vector < Edge > edges;

int n, f[100003], num[100003], low[100003], timeDFS = 0, NumNode, id[100003], sz[100003], ID;

vector < int > adj[100003];

vector < Segment > Ox[200003], Oy[200003];

void build(vector < Segment > &f) {
    sort(f.begin(), f.end());
    int cur = 0;
    for (int i = 1; i < f.size(); i++) {
        if (f[i].l <= f[cur].r) edges.push_back({f[cur].id, f[i].id});
        if (f[i]. r >= f[cur].r) cur = i;
    }
}

void dfs(int u, int e) {
    NumNode ++; id[u] = ID;
    f[u] = 1;
    num[u] = low[u] = ++ timeDFS;
    for (auto i : adj[u]) {
        int v = edges[i].u ^ edges[i].v ^ u;
        if (v == e) continue;
        if (num[v] == 0) {
            dfs(v, u);  f[u] += f[v];
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) edges[i].bridge = 1;
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("building.inp", "r", stdin);
    freopen("building.out", "w", stdout);
    cin >> n;
    vector < int > val1, val2;
    for (int i = 1; i <= n; i++)
        cin >> a[i].left >> a[i].top >> a[i].right >> a[i].bot;

    for (int i = 1; i <= n; i++) {
        val1.push_back(a[i].left); val1.push_back(a[i].right);
        val2.push_back(a[i].bot); val2.push_back(a[i].top);
    }
    sort(val1.begin(), val1.end()); val1.erase(unique(val1.begin(), val1.end()), val1.end());
    sort(val2.begin(), val2.end()); val2.erase(unique(val2.begin(), val2.end()), val2.end());
    for (int i = 1; i <= n; i++) {
        a[i].left = lower_bound(val1.begin(), val1.end(), a[i].left) - val1.begin();
        a[i].right = lower_bound(val1.begin(), val1.end(), a[i].right) - val1.begin();
        a[i].top = lower_bound(val2.begin(), val2.end(), a[i].top) - val2.begin();
        a[i].bot = lower_bound(val2.begin(), val2.end(), a[i].bot) - val2.begin();
        Ox[a[i].left].push_back(Segment(a[i].bot, a[i].top, i));
        Ox[a[i].right].push_back(Segment(a[i].bot, a[i].top, i));
        Oy[a[i].top].push_back(Segment(a[i].left, a[i].right, i));
        Oy[a[i].bot].push_back(Segment(a[i].left, a[i].right, i));
    }
    for (int i = 0; i < val1.size(); i++)
        build(Ox[i]);

    for (int i = 0; i < val2.size(); i++)
        build(Oy[i]);
    /*
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (a[i].bot == a[j].top) {
                int l = max(a[i].left, a[j].left);
                int r = min(a[i].right, a[j].right);
                if (l <= r) edges.push_back(Edge(i, j));
            }
            if (a[i].right == a[j].left) {
                int bot = max(a[i].bot, a[j].bot);
                int top = min(a[i].top, a[j].top);
                if (bot <= top) edges.push_back(Edge(i, j));
            }
        }
    */
    for (auto &e : edges)
        if (e.u > e.v) swap(e.u, e.v);
    sort(edges.begin(), edges.end()); edges.erase(unique(edges.begin(), edges.end()), edges.end());
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            NumNode = 0; ID ++;
            dfs(i, 0);
            sz[ID] = NumNode;
        }
    }
    int res = INT_MAX;
    for (int u = 1; u <= n; u++)
        for (auto i : adj[u]) {
            if (!edges[i].bridge) continue;
           int v = edges[i].u ^ edges[i].v ^ u;
           if (num[v] < num[u]) continue;
           res = min(res, abs(sz[id[u]] - 2 * f[v]));
        }
    cout << (res == INT_MAX ? -1 : res);
}
