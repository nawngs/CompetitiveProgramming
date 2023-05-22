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

const string NAME = "MINDIST";
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

ll n, m, k, res = INF, d[100003], st[100003];

bool valid[100003];

vector < pll > adj[100003];

void dijkstra() {
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	for (int i = 1; i <= n; i++) {
		st[i] = -1;
		if (valid[i]) {
			d[i] = 0;
			st[i] = i;
			heap.push({0, i});
		}
		else d[i] = INF;
	}
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (st[v.fi] != st[u.se] || st[v.fi] == -1) res = min(res, d[v.fi] + d[u.se] + v.se);
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				st[v.fi] = st[u.se];
				heap.push({d[v.fi], v.fi});
			}
			else if (d[v.fi] == u.fi + v.se && st[v.fi] != st[u.se]) st[v.fi] = -1;
		}
	}
}


int main() {
	fast;
	//fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		valid[x] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dijkstra();
	cout << res;
}
