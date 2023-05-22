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

const string NAME = "graph";
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

int n, m, k, mask[100003], dis[100003][4];

vector < int > adj[100003];

bool minimize(int &x, int y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

void dijkstra() {
	priority_queue < piii, vector < piii >, greater < piii > > heap;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) 
			dis[i][j] = INF;
		dis[i][mask[i]] = 0;
		if (mask[i] != 0) heap.push({0, {i, mask[i]}});
	}
	while (heap.size()) {
		auto x = heap.top(); heap.pop();
		int d = x.fi, u = x.se.fi, msk = x.se.se;
		if (minimize(dis[u][3], d + dis[u][3 - msk])) 
			heap.push({dis[u][3], {u, 3}});
		for (auto v : adj[u]) {
			if (minimize(dis[v][msk], d + 1)) 
				heap.push({dis[v][msk], {v, msk}});
		}
	}
	int res = min(dis[1][3], dis[1][2] + dis[1][1]);
	if (res >= INF) cout << "impossible" << '\n';
	else cout << res << '\n';
}

int main() {
	fast;
	fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u; cin >> u;
		mask[u] ^= 1;
	}
	for (int i = 1; i <= k; i++) {
		int u; cin >> u;
		mask[u] ^= 2;
	}
	for (int i = 1; i <= n; i++) {
		int d; cin >> d;
		while (d --) {
			int u; cin >> u;
			adj[u].push_back(i);
		}
	}
	dijkstra();
}
