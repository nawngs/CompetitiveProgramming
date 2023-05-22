#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "addminedge";
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

int n, m, d[200003][2], min_e[200003][2];

vector < pii > adj[200003];

void dijkstra() {
	priority_queue < piii, vector < piii >, greater < piii > > heap;
	for (int i = 1; i <= n; i++) {
		d[i][0] = d[i][1] = INF;
		min_e[i][0] = min_e[i][1] = INF;
	}
	d[1][0] = 0;
	heap.push({d[1][0], {1, 0}});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se.fi][u.se.se]) continue;
		for (auto v : adj[u.se.fi]) {
			if (u.se.se == 1) {
				if (v.se > min_e[u.se.fi][1] && d[v.fi][1] > u.fi + v.se) {
					d[v.fi][1] = u.fi + v.se;
					min_e[v.fi][1] = min_e[u.se.fi][1];
					heap.push({d[v.fi][1], {v.fi, 1}});
				} 
			}
			else {
				if (d[v.fi][0] > u.fi + v.se) {
					d[v.fi][0] = u.fi + v.se;
					min_e[v.fi][0] = min(min_e[u.se.fi][0], v.se);
					heap.push({d[v.fi][0], {v.fi, 0}});
				}
				int tam = min(min_e[u.se.fi][0], v.se);
				if (d[v.fi][1] > u.fi + v.se + tam) {
					d[v.fi][1] = u.fi + v.se + tam;
					min_e[v.fi][1] = tam;
					heap.push({d[v.fi][1], {v.fi, 1}});
				}
				
			}
		}
	}
	for (int i = 2; i <= n; i++) cout << d[i][1] << ' ';
}

 main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dijkstra();
}
