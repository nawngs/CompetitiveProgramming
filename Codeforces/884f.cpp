#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[103], cnt[30];

string s;

struct Edge {
	int from, to, flow, capa, cost;
	Edge(int _from, int _to, int _capa, int _cost) {
		from = _from; to = _to; flow = 0; capa = _capa; cost = _cost;
	}
};

struct Mincost {
	int NumNode;
	vector < vector < int > > adj;
	vector < Edge > edges;
	vector < int > dist, pre;
	vector < bool > InQueue;
	void init(int x = 0) {
		NumNode = x;
		adj.resize(NumNode + 5, vector < int >());
		edges.clear();
		dist.resize(NumNode + 5); pre.resize(NumNode + 5); InQueue.resize(NumNode + 5);
	}
	void AddEdge(int from, int to, int capa, int cost) {
		adj[from].push_back(sz(edges));
		edges.push_back(Edge(from, to, capa, cost));
		adj[to].push_back(sz(edges));
		edges.push_back(Edge(to, from, 0, -cost));
	}
	bool check(int s, int t) {
		for (int i = 1; i <= NumNode; i++) {
			dist[i] = INF;
			pre[i] = 0;
			InQueue[i] = false;
		}
		dist[s] = 0; InQueue[s] = 1;
		queue < int > que;
		que.push(s);
		while (!que.empty()) {
			int u = que.front(); que.pop();
			InQueue[u] = false;
			for (auto id : adj[u]) {
				if (edges[id].capa > edges[id].flow) {
					int v = edges[id].to;
					if (dist[v] > dist[u] + edges[id].cost) {
						dist[v] = dist[u] + edges[id].cost;
						pre[v] = id;
						if (!InQueue[v]) que.push(v);
						InQueue[v] = 1;
					}
				}
			}
		}
		return (dist[t] != INF);
	}
	pii get_flow(int src, int snk) {
		pii res = {0, 0};
		while (check(src, snk)) {
			int delta = INF;
			for (int u = snk; u != src; u = edges[pre[u]].from)
				delta = min(delta, edges[pre[u]].capa - edges[pre[u]].flow);
			for (int u = snk; u != src; u = edges[pre[u]].from) {
				edges[pre[u]].flow += delta;
				edges[pre[u] ^ 1].flow -= delta;
			}
			res.fi += delta;
			res.se += delta * dist[snk];
		}
		return res;
	}
};

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (auto c : s) {
		cnt[c - 'a' + 1] ++;
	}
	s = ' ' + s;
	int src = 26 + n / 2 + 1, snk = src + 1;
	Mincost mc;
	mc.init(snk);
	for (int i = 1; i <= 26; i++) {
		mc.AddEdge(src, i, cnt[i], 0);
		for (int j = 1; j <= n / 2; j++) {
			int val = 0;
			if (s[j] - 'a' + 1 == i) val = max(val, a[j]);
			if (s[n - j + 1] - 'a' + 1 == i) val = max(val, a[n - j + 1]);
			mc.AddEdge(i, j + 26, 1, -val);
		}
	}
	for (int j = 1; j <= n / 2; j++) 
		mc.AddEdge(j + 26, snk, 2, 0);
	cout << -mc.get_flow(src, snk).se;
}