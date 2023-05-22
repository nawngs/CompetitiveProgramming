#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define plll pair < ll, pll >
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

ll n, m, D;

vector < pll > adj[200003];

void dijkstra(int s) {
	priority_queue < plll, vector < plll >, greater < plll > > heap;
	heap.push({0, {1, -LINF}});
	while (heap.size()) {
		auto x = heap.top();
		heap.pop();
		ll d = x.fi, u = x.se.fi, pre = x.se.se;
		if (u == n) {
			cout << d << '\n';
			return ;
		}
		while (adj[u].size()) {
			if (pre + D > adj[u].back().se) break;
			heap.push({d + adj[u].back().se, {adj[u].back().fi, adj[u].back().se}});
			adj[u].pop_back();
		}
	}
	cout << -1 << '\n';
}

int main() {
	cin >> n >> m >> D;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), [&](pll &x, pll &y) {
			return x.se < y.se;
		});
	}
	dijkstra(1);
}
