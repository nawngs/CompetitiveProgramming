#include <bits/stdc++.h>

using namespace std;

struct dsu_save {
    int v, rnkv, u, rnku, tim;

    dsu_save() {}

    dsu_save(int _v, int _rnkv, int _u, int _rnku, int _tim)
        : v(_v), rnkv(_rnkv), u(_u), rnku(_rnku), tim(_tim) {}
};

struct DSURollBack {
    vector < int > par, rnk;
    stack < dsu_save > st;
    int cur;
    void init(int n) {
        par.resize(n + 3); rnk.resize(n + 3);
        for (int i = 1; i <= n; i++)
            par[i] = i, rnk[i] = 0;
            cur = 0;
    }
    int find(int u) {
        if (u == par[u]) return u;
        return find(par[u]);
    }
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        cur ++;
        if (rnk[u] < rnk[v]) swap(u, v);
        st.push({v, rnk[v], u, rnk[u], cur});
        par[v] = u;
        if (rnk[u] == rnk[v]) rnk[u] ++;
        return true;
     }
     void roll_back(int tim) {
        while (!st.empty() && st.top().tim > tim) {
            auto x = st.top();
            par[x.v] = x.v; rnk[x.v] = x.rnkv;
            rnk[x.u] = x.u;
            st.pop();
        }
        cur = tim;
     }
} DSU;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) {
        u = _u, v = _v, w = _w;
    }
    bool operator < (const Edge &oth) {
        return w < oth.w;
    }
};

const int INF = INT_MAX;

int n, m, s, t;

long long res = 1e15;

vector < Edge > edgea, edgeb;

void calc(int l, int r, int optl, int optr) {
    // add den l - 1 va den optl - 1
    if (l > r) return ;
    int temp = DSU.cur;
    int mid = (l + r) / 2;
    for (int i = l; i <= mid; i++)
        DSU.merge(edgea[i].u, edgea[i].v);
    int tam = DSU.cur;
    int opt = optl; DSU.merge(edgeb[opt].u, edgeb[opt].v);
    while (DSU.find(s) != DSU.find(t)) {
        opt ++;
        DSU.merge(edgeb[opt].u, edgeb[opt].v);
    }
    res = min(res, 1LL * edgea[mid].w + 1LL * edgeb[opt].w);
    DSU.roll_back(tam);
    calc(mid + 1, r, optl, opt);
    DSU.roll_back(temp);
    for (int i = optl; i < opt; i++)
        DSU.merge(edgeb[i].u, edgeb[i].v);
    calc(l, mid - 1, opt, optr);
    DSU.roll_back(temp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("bus.inp", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, c, w; cin >> c >> u >> v >> w;
        if (c == 1) edgea.push_back(Edge(u, v, w));
        else edgeb.push_back(Edge(u, v, w));
    }
    edgeb.push_back(Edge(1, 1, 0));
    for (int i = 1; i < n; i++)
        edgeb.push_back(Edge(i, i + 1, INF));
    DSU.init(n);
    sort(edgea.begin(), edgea.end()); sort(edgeb.begin(), edgeb.end());
    calc(0, edgea.size() - 1, 0, edgeb.size() - 1);
    cout << res;
}
