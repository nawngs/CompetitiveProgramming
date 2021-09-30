#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll > 
#define fi first
#define se second

using namespace std;

const ll INF = 1E18 + 711;

ll n, m, q, d[411][411], temp[411][411];

vector < pll > tam[405], tam2[405], adj1[405], adj2[405];

void dijkstra(ll start, bool dau, vector < pll > adj[]) {
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	ll f[411];
	for (int i = 1; i <= n + 3; i++) f[i] = INF;
	f[start] = 0;
	heap.push({f[start], start});
	while (heap.size()) {
		pll u = heap.top();
		heap.pop();
		if (u.fi != f[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (f[v.fi] > f[u.se] + v.se) {
				f[v.fi] = f[u.se] + v.se;
				heap.push({f[v.fi], v.fi});
			}
		}
	}
	//if (start == n + 2 && dau == false) for (int i = 1; i <= n + 3; i++) cout << f[i] << '\n';
	if (start <= n) {
		if (dau == true) for (int i = 1; i <= n + 3; i++) temp[start][i] = f[i];
		else for (int i = 1; i <= n + 3; i++) temp[i][start] = f[i];
	}
	else {
		if (dau == true) for (int i = 1; i <= n + 3; i++) d[start][i] = f[i];
		else for (int i = 1; i <= n + 3; i++) d[i][start] = f[i];
	}
	
}

void create() {
	for (int i = 1; i <= n + 4; i++) {
		for (int j = 1; j <= n + 4; j++) {
			if (i == j) d[i][j] = 0;
			else if (i <= n && j <= n) d[i][j] = temp[i][j];
			else d[i][j] = INF;

		}
	}
	for (int i = 1; i <= n + 3; i++) {
			adj1[i] = tam[i];
			adj2[i] = tam2[i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("DIJ.INP", "r", stdin);
	freopen("DIJ.OUT", "w", stdout);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		tam[u].push_back({v, c});
		tam2[v].push_back({u, c});
	}

	for (int i = 1; i <= n; i++) dijkstra(i, 1, tam);

	while (q --) {
		create();

		int e;
		cin >> e;

		for (int i = 1; i <= e; i++) {
			ll u, v, c;
			cin >> u >> v >> c;
			adj1[u].push_back({v, c});
			adj2[v].push_back({u, c});
		}
		//cout << d[1][2] << '\n';
		for (int i = n + 1; i <= n + 3; i++) dijkstra(i, 1, adj1);
		for (int i = n + 1; i <= n + 3; i++) dijkstra(i, 0, adj2);
		//cout << d[1][2] << '\n';
		for (int k = n + 1; k <= n + 3; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		ll sum = 0;
		for (int i = 1; i <= n + 3; i++) {
			for (int j = 1; j <= n + 3; j++) {
				sum += d[i][j];
			}
		}
		cout << sum << '\n';
	}
}