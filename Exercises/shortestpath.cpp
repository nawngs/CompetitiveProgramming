#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "shortestpath";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, p, CntScc = 0, InScc[500003];

bool vs[500003], calced[500003];

vector < int > Scc[500003];

vector < pii > Edges[500003], ArcStart[500003];

ll d[500003];

void dfs(int u) {
	Scc[CntScc].push_back(u);
	InScc[u] = CntScc;
	vs[u] = 1;
	for (auto v : Edges[u]) {
		if (vs[v.fi]) continue;
		dfs(v.fi);
	}
}

void dijkstra(int id) {
	if (calced[id]) return ;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	for (auto v : Scc[id]) {
		for (auto u : ArcStart[v]) {
			if (!calced[InScc[u.fi]]) dijkstra(InScc[u.fi]);
			if (d[u.fi] == INF) continue;
			d[v] = min(d[v], d[u.fi] + 1ll * u.se);
		}
	}
	for (auto v : Scc[id]) if (d[v] != INF) heap.push({d[v], v});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : Edges[u.se]) {
			if (d[v.fi] > u.fi + 1ll * v.se) {
				d[v.fi] = u.fi + 1ll * v.se;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
	calced[id] = 1;
}

int main() {
	fast;
	fre();
	cin >> n >> m >> p;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		Edges[u].push_back({v, c});
		Edges[v].push_back({u, c});
	}
	for (int i = 1; i <= p; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		ArcStart[v].push_back({u, c});
	}
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			CntScc++;
			dfs(i);
		}
		d[i] = INF;
	}
	d[1] = 0;
	for (int i = 1; i <= CntScc; i++) dijkstra(i);
	for (int i = 1; i <= n; i++) cout << (d[i] == INF ? -1 : d[i]) << " ";
}