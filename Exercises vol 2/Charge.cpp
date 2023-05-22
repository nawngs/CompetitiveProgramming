#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "charge";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".ans";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int u, v, c;
} a[100003];

int n, m, x, d[10003];

vector < pii > adj[10003];

int dijkstra() {
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[1] = 0;
	heap.push({0, 1});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
	return d[n];
}	

int get(int x) {
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i <= m; i++) {
		if (a[i].c <= x) {
			adj[a[i].u].push_back({a[i].v, a[i].c});
			adj[a[i].v].push_back({a[i].u, a[i].c});
		}
	}
	return dijkstra();
}

signed main() {
	fast;
	fre();
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].c;
		adj[a[i].u].push_back({a[i].v, a[i].c});
		adj[a[i].v].push_back({a[i].u, a[i].c});
	}
	int tam = dijkstra();
	int longest_path = tam + (tam * x) / 100;
	int l = 1, r = 1e12, mid, ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (get(mid) <= longest_path) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}
