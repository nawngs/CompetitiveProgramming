#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define plll pair < pll, ll >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "quanho";
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

int n, m, p[100003];

vector < pii > adj[100003];

pll d[100003];

void dijkstra() {
	priority_queue < plll, vector < plll >, greater < plll > > heap;
	for (int i = 1; i <= n; i++) d[i] = make_pair(INF, INF);
	d[1] = {0, p[1]};
	heap.push({d[1], 1});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi].fi > u.fi.fi + v.se) {
				d[v.fi] = u.fi;
				d[v.fi].fi += v.se;
				d[v.fi].se += p[v.fi];
				heap.push({d[v.fi], v.fi});
			}
			else if (d[v.fi].fi == u.fi.fi + v.se && d[v.fi].se < u.fi.se + p[v.fi]) {
				d[v.fi] = u.fi;
				d[v.fi].fi += v.se;
				d[v.fi].se += p[v.fi];
				heap.push({d[v.fi], v.fi});
			}
		}
	}
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dijkstra();
	if (d[n].fi == INF) cout << "impossible" << '\n';
	else cout << d[n].fi << " " << d[n].se << '\n';
}
