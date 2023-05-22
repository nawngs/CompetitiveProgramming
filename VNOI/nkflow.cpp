#include <bits/stdc++.h>

#define SIZ(x) ((int)(x).size())

using namespace std;

const int INF = 1E9 + 7;

struct Edge {
    int from, to, capa, flow;
    Edge(int _from = 0, int _to = 0, int _capa = 0) {
        from = _from, to = _to, capa = _capa;
        flow = 0;
    }
};

struct MaxFlow {
    int NumNode;
    vector < vector < int > > adj;
    vector < Edge > edges;
    vector < bool > vs;
    vector < int > trace;
    void init(int n) {
        NumNode = n;
        adj.assign(n + 5, vector < int >());
        edges.clear();
        vs.assign(n + 5, 0);
        trace.assign(n + 5, -1);
    }
    void add_edge(int from, int to, int capa) {
        adj[from].push_back(SIZ(edges));
        edges.push_back(Edge(from, to, capa));
        adj[to].push_back(SIZ(edges));
        edges.push_back(Edge(to, from, 0));
    }
    bool bfs(int s, int t) {
        for (int i = 1; i <= NumNode; i++) vs[i] = 0;
        vs[s] = 1; queue < int > que; que.push(s);
        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (auto i : adj[u])
                if (edges[i].flow < edges[i].capa && !vs[edges[i].to]) {
                    vs[edges[i].to] = 1;
                    trace[edges[i].to] = i;
                    que.push(edges[i].to);
                }
        }
        return vs[t];
    }
    int get_flow(int s, int t) {
        int res = 0;
        while (bfs(s, t)) {
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

int n, m, s, t;

int main() {
    cin >> n >> m >> s >> t;
    MaxFlow lmfao; lmfao.init(n);
    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;
        lmfao.add_edge(u, v, c);
    }
    cout << lmfao.get_flow(s, t);
}
