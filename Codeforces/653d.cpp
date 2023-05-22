#include <bits/stdc++.h>

#define ll long long
#define int ll

using namespace std;

const ll BASE = 1E8;

const int INF = 1E9 + 7;

int n, m, x, a[503], b[503];

ll c[503];

struct Edge {
    int from, to, flow, capa;
    Edge(int _from = 0, int _to = 0, int _capa = 0) {
        from = _from, to = _to, capa = _capa;
        flow = 0;
    }
};

struct FFMaxFLow {
    int numnode;
    vector < int > adj[53], trace;
    vector < Edge > edges;
    vector < bool > vs;
    FFMaxFLow(int n = 0) {
        numnode = n;
        edges.clear();
        trace.assign(n + 7, 0);
        vs.assign(n + 7, 0);
        for (int i = 1; i <= numnode; i++)
            adj[i].clear();
    }
    void addEdge(int from, int to, int capa) {
        adj[from].push_back(edges.size());
        edges.push_back(Edge(from, to, capa));
        adj[to].push_back(edges.size());
        edges.push_back(Edge(to, from, 0));
    }
    bool SPFA(int s, int t) {
        for (int i = 1; i <= n; i++) vs[i] = false;
        vs[s] = 1; queue < int > q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto id : adj[u]) {
                if (edges[id].flow < edges[id].capa && !vs[edges[id].to]) {
                    vs[edges[id].to] = 1;
                    trace[edges[id].to] = id;
                    q.push(edges[id].to);
                }
            }
        }
        return vs[t];
    }
    int Flow(int s, int t) {
        int res = 0;
        while (SPFA(s, t)) {
            int delta = INF;
            for (int u = t; u != s; u = edges[trace[u]].from)
                delta = min(delta, edges[trace[u]].capa - edges[trace[u]].flow);
            for (int u = t; u != s; u = edges[trace[u]].from) {
                edges[trace[u]].flow += delta;
                edges[trace[u] ^ 1].flow -= delta;
            }
            res += delta;
        }
        return res;
    }
};

bool check(ll val) {
    FFMaxFLow ak47(n);
    for (int i = 1; i <= m; i++) {
        ak47.addEdge(a[i], b[i], floor(c[i] / val));
    }
    return ak47.Flow(1, n) >= x;
}

signed main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] *= BASE;
    }
    ll l = 0, r = 1e15, mid, ans;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << fixed << setprecision(8) << (1.0 * ans / BASE) * 1.0 * x;
}
