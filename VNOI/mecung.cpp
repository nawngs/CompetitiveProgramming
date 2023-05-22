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

int n, m, d[100003];

vector < pii > adj[100003];

vector < int > res;

void dijkstra() {
	priority_queue < pii, vector < pii > , greater < pii > > heap;
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[n] = 0;
	heap.push({0, n});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > d[u.se] + 1) {
				d[v.fi] = d[u.se] + 1;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
	cout << d[1] << '\n';
}

void dfs(int u, int pos) {
	if (u == n) return;
	for (auto v : adj[u]) {
		if (d[v.fi] == d[u] - 1 && res[pos] >= v.se) {
			res[pos] = min(res[pos], v.se);
			dfs(v.fi, pos + 1);
		}
		if (v.se > res[pos]) break;
	}

}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= n; i++) 	
		sort(adj[i].begin(), adj[i].end(), [](pii &x, pii &y) {
			return x.se < y.se;
		});
	dijkstra();
	res.resize(d[1], INF);
	dfs(1, 0);
	for (int i = 0; i < d[1]; i++) cout << res[i] << " ";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
