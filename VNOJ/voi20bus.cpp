#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair < long long, long long >

using namespace std;

const ll INF = 1e9 + 7;

struct Edge {
	int v, cty, w;
	Edge(int _v, int _cty, int _w) : v(_v), cty(_cty), w(_w) {};
};

ll n, m, s, t;

vector < Edge > adj[50005];

void dijkstra() {
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	ll max1[50005];
	ll max2[50005];
	ll d[50005];
	for(int i = 1; i <= n; i++) {
		d[i] = INF;
		max2[i] = 0;
		max1[i] = 0;
	}
	d[s] = 0;
	heap.push({0, s});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		//cout << u.fi << " " << u.se << '\n';
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			int temp1 = max1[u.se], temp2 = max2[u.se];
			if (v.cty == 1) temp1 = max(temp1, v.w);
			else temp2 = max(temp2, v.w);
			//	cout << u.se << " " << v.v << " " << temp1 << " " << temp2 << '\n';
			if (d[v.v] > temp1 + temp2) {
				d[v.v] = temp1 + temp2;
				max1[v.v] = temp1;
				max2[v.v] = temp2;
				heap.push({d[v.v], v.v});
			}
		}
	}
	cout << d[t];
}

int main() {
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int u, v, cty, w;
		cin >> cty >> u >> v >> w;
		adj[u].push_back({v, cty, w});
		adj[v].push_back({u, cty, w});
	}
	dijkstra();
}