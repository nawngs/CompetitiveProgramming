#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

ll n, m, s, t;

pll d_s[100003], d_t[100003];

vector < pll > adj[100003];

plll edges[200003];

void dijkstra(int pos, pll d[]) {
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

ll sqr(ll x) {
	x %= MOD;
	return (x * x) % MOD;
}

signed main() {
	fast;
	fre();
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
		edges[i] = {{u, v}, c};
	}
	dijkstra(s, d_s);
	dijkstra(t, d_t);
	ll res = (d_s[t].se * d_s[t].se) % MOD;
	for (int i = 1; i <= m; i++) {
		int u = edges[i].fi.fi;
		int v = edges[i].fi.se;
		int c = edges[i].se;
		if (d_s[u].fi + d_t[v].fi + c == d_s[t].fi && abs(d_s[u].fi - d_t[v].fi) < c) {
			res -= sqr(d_s[u].se * d_t[v].se);
			res = (res % MOD + MOD) % MOD;
		}
		else{
			swap(u, v);
			if (d_s[u].fi + d_t[v].fi + c == d_s[t].fi && abs(d_s[u].fi - d_t[v].fi) < c) res -= sqr(d_s[u].se * d_t[v].se);
			res = (res % MOD + MOD) % MOD;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d_s[i].fi + d_t[i].fi == d_s[t].fi && d_s[i].fi == d_t[i].fi) res -= sqr(d_s[i].se * d_t[i].se);
		res = (res % MOD + MOD) % MOD;
	}
	cout << res;
}
