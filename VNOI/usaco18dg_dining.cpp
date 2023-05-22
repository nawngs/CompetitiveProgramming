#pragma GCC optimize ("O3")
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
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, k, val[50003], dist1[500003], dist2[500003];

vector < pii > adj[50003], hay;

void dijkstra1() {
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for (int i = 1; i <= n; i++) dist1[i] = INF;
	dist1[n] = 0;
	heap.push({dist1[n], n});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dist1[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (dist1[v.fi] > dist1[u.se] + v.se) {
				dist1[v.fi] = dist1[u.se] + v.se;
				heap.push({dist1[v.fi], v.fi});
			}
		}
	}
}

void dijkstra2() {
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for (int i = 1; i <= n; i++) dist2[i] = INF;
	for (auto u : hay) {
		dist2[u.fi] = dist1[u.fi] - u.se;
		heap.push({dist2[u.fi], u.fi});
	}
	while(heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dist2[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (dist2[v.fi] > u.fi + v.se) {
				dist2[v.fi] = u.fi + v.se;
				heap.push({dist2[v.fi], v.fi});
			}
		}
	}
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});	
	}
	dijkstra1();
	for (int i = 1; i <= k; i++) {
		int u, c;
		cin >> u >> c;
		hay.push_back({u, c});
	}
	dijkstra2();
	for (int i = 1; i < n; i++) cout << (dist2[i] <= dist1[i]) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
