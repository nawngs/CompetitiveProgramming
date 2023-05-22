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

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m;

pll d1[100003], d2[100003];

vector < pll > adj1[100003], adj2[100003];

plll edges[100003];

void dijkstra(int pos, pll d[], vector < pll > adj[]) {
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	for (int i = 1; i <= n; i++) d[i] = {LINF, 0};
	d[pos] = {0, 1};
	heap.push({d[pos].fi, pos});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se].fi) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi].fi > u.fi + v.se) {
				d[v.fi] = d[u.se];
				d[v.fi].fi += v.se;
				heap.push({d[v.fi].fi, v.fi});
			}
			else if (d[v.fi].fi == u.fi + v.se) d[v.fi].se = (d[v.fi].se + d[u.se].se) % MOD;
		}
	}
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj1[u].push_back({v, c});
		adj2[v].push_back({u, c});
		edges[i] = {{u, v}, c};
	}
	dijkstra(1, d1, adj1);
	dijkstra(2, d2, adj2);
	for (int i = 1; i <= m; i++) {
		ll u = edges[i].fi.fi;
		ll v = edges[i].fi.se;
		ll c = edges[i].se;
		if (d1[v].fi + d2[u].fi + c < d1[2].fi) {
			cout << "HAPPY" << '\n';
			continue;
		}
		if (d1[u].fi + d2[v].fi + c == d1[2].fi && (d1[u].se * d2[v].se) % MOD == d1[2].se) cout << "SAD" << '\n';
		else cout << "SOSO" << '\n';
	}
}
