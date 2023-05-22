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

const string NAME = "gps";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, dis1[10003], dis2[10003], res[10003];

vector < pii > adj1[10003], adj2[10003];

vector < piii > edge[10003];

void dijkstra(int st, vector < pii > adj[], int dis[]) {
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[st] = 0;
	heap.push({0, st});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dis[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (dis[v.fi] > u.fi + v.se) {
				dis[v.fi] = u.fi + v.se;
				heap.push({dis[v.fi], v.fi});
			}
		}
	}
}

void dijkstra_res() {
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (int i = 1; i <= n; i++) res[i] = INF;
	res[1] = 0;
	heap.push({0, 1});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != res[u.se]) continue;
		for (auto v : edge[u.se]) {
			int c = 0;
			c += (dis1[v.fi] + v.se.fi > dis1[u.se]);
			c += (dis2[v.fi] + v.se.se > dis2[u.se]);
			if (res[v.fi] > res[u.se] + c) {
				res[v.fi] = res[u.se] + c;
				heap.push({res[v.fi], v.fi});
			}
		}
	}
	cout << res[n] << '\n';
}

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c1, c2;
		cin >> u >> v >> c1 >> c2;
		adj1[v].push_back({u, c1});
		adj2[v].push_back({u, c2});
		edge[u].push_back({v, {c1, c2}});
	}
	dijkstra(n, adj1, dis1);
	dijkstra(n, adj2, dis2);
	dijkstra_res();
}
