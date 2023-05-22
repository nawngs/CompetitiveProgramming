#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int from, to, capa, flow;
	Edge (int _from = 0, int _to = 0, int _capa = 0) {
		from = _from;
		to = _to;
		capa = _capa;
		flow = 0;
	}
};

int n, m, x, trace[53], maxc = 0;

vector < Edge > edges;

vector < int > adj[53];

bool vs[53];

pair < pii, int > a[503];

ld res = 0;

void add_edge(int u, int v, int c) {
	adj[u].push_back(edges.size());
	edges.push_back(Edge(u, v, c));
	adj[v].push_back(edges.size());
	edges.push_back(Edge(v, u, 0));
}

bool find(int s, int t) {
	memset(vs, false, sizeof(vs));
	queue < int > q;
	vs[s] = 1;
	q.push(s);
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int id : adj[u]) {
			if (edges[id].flow < edges[id].capa && !vs[edges[id].to]) {
				vs[edges[id].to] = 1;
				trace[edges[id].to] = id;
				q.push(edges[id].to);
			}
		}
	}
	return vs[t];
}

int max_flow(int s, int t) {
	int flow = 0;
	while (find(s, t)) {
		int delta = INF;
		for (int u = t; u != s; u = edges[trace[u]].from) {
			delta = min(delta, edges[trace[u]].capa - edges[trace[u]].flow);
		}
		for (int u = t; u != s; u = edges[trace[u]].from) {
			edges[trace[u]].flow += delta;
			edges[trace[u] ^ 1].flow -= delta;
		}
		flow += delta;
	}
	return flow;
}

bool check(int val) {
	edges.clear();
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i <= m; i++) add_edge(a[i].fi.fi, a[i].fi.se, floor(a[i].se / val));
 	return (max_flow(1, n) >= x);
}

main() {
	fast;
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
		a[i].se *= 1e8;
	}
	int l = 1, r = 1e15, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << fixed << setprecision(8) << ((ld) ans / (ld) 100000000) * x;
}
