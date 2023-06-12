#include <bits/stdc++.h>
using namespace std;

const int mxN = 300;
const int inf = 2e9;
const int X[] = {0, 0, 1, -1};
const int Y[] = {1, -1, 0, 0};

int m, n, T, a[mxN][mxN], id[mxN][mxN];

struct Edgee {
  int to, cost, cap, flow, backEdge;
};
struct MCMF {
  int s, t, n;
  vector<Edgee> g[mxN];
  MCMF() {}
  MCMF(int _s, int _t, int _n) {
    s = _s, t = _t, n = _n;
  }
  void addEdge(int u, int v, int cost, int cap) {
  	// cerr << u << ' ' << v << ' ' << cost << '\n';
    Edgee e1 = { v, cost, cap, 0, g[v].size() };
    Edgee e2 = { u, -cost, 0, 0, g[u].size() };
    g[u].push_back(e1); g[v].push_back(e2);
  }
  pair<int, int> minCostMaxFlow() {
    int flow = 0, cost = 0;
    vector<int> state(n), from(n), from_edge(n), d(n);
    deque<int> q;
    while (true) {
      for (int i = 0; i < n; i++)
        state[i] = 2, d[i] = -inf, from[i] = -1;
      state[s] = 1; q.clear(); q.push_back(s); d[s] = 0;
      while (!q.empty()) {
        int v = q.front(); q.pop_front(); state[v] = 0;
        for (int i = 0; i < (int) g[v].size(); i++) {
          Edgee e = g[v][i];
          if (e.flow >= e.cap || d[e.to] >= d[v] + e.cost)
            continue;
          int to = e.to; d[to] = d[v] + e.cost;
          from[to] = v; from_edge[to] = i;
          if (state[to] == 1) continue;
          if (!state[to] || (!q.empty() && d[q.front()] < d[to]))
            q.push_front(to);
          else q.push_back(to);
          state[to] = 1;
        }
      }
      if (d[t] == -inf) break;
      // cerr << 1 << '\n';
      int it = t, addflow = inf;
      while (it != s) {
        addflow = min(addflow,
            g[from[it]][from_edge[it]].cap
            - g[from[it]][from_edge[it]].flow);
        it = from[it];
      }
      it = t;
      while (it != s) {
        g[from[it]][from_edge[it]].flow += addflow;
        g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
        cost += g[from[it]][from_edge[it]].cost * addflow;
        it = from[it];
      }
      flow += addflow;
    }
    return {cost,flow};
  }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> n >> T;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j], id[i][j] = (i-1)*n+j;
	int s = m*n+1, t = m*n+2, si = m*n+3, ti = m*n+4;
	MCMF sol(s, t, m*n+5); 
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if ((i+j)%2) {
				for (int k = 0; k < 4; ++k) {
					int u = i + X[k], v = j + Y[k];
					if (id[u][v]) 
						sol.addEdge(id[i][j], id[u][v], a[i][j]*a[u][v], 1);
						// cerr << id[i][j] << ' ' << id[u][v] << ' ' << a[i][j]*a[u][v] << '\n';
						// cerr << a[i][j]*a[u][v] << '\n';
				}
			}
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if ((i+j)%2) sol.addEdge(si, id[i][j], 0, 1);
			else sol.addEdge(id[i][j], ti, 0, 1);
	sol.addEdge(s, si, 0, T); sol.addEdge(ti, t, 0, T);
	pair < int, int > res = sol.minCostMaxFlow();
	cout << res.first;
	return 0;
}