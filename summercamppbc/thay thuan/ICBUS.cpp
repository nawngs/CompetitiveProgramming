#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
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

int n, m, d[5003][5003];

pii a[5003];

vector < int > adj[5003];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= n; j++) d[i][j] = INF;
	d[1][a[1].se] = a[1].fi;
	priority_queue < piii, vector < piii >, greater < piii > > heap;
	heap.push({a[1].fi, {1, a[1].se}});
	int res = INF;
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se.fi][u.se.se]) continue;
		if (u.se.fi == n) res = min(res, u.fi);
		if (u.se.se != 0) {
			for (auto v : adj[u.se.fi]) {
				if (d[v][u.se.se - 1] > u.fi) {
					d[v][u.se.se - 1] = u.fi;
					heap.push({u.fi, {v, u.se.se - 1}});
				}
			}
		}
		if (d[u.se.fi][a[u.se.fi].se] > u.fi + a[u.se.fi].fi) {
			d[u.se.fi][a[u.se.fi].se] = u.fi + a[u.se.fi].fi;
			heap.push({d[u.se.fi][a[u.se.fi].se], {u.se.fi, a[u.se.fi].se}});
		}
	}
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
