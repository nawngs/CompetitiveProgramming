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

	const string NAME = "candy";
	const string NAME2 = "TEST";
	const ll ESP = 1e-9;
	const ll INF = 1e18;
	const ll nmax = 2e5;
	const ll MOD = 1e9 + 7;
	const ll base = 1e9 + 7;

	void fre() {
		string finp = NAME + ".inp";
		string fout = NAME + ".out";
		freopen(finp.c_str(), "r", stdin);
		freopen(fout.c_str(), "w", stdout);
	}

	struct Edge {
		int v, c, id;
		Edge(int _v, int _c, int _id) : v(_v), c(_c), id(_id) {};
	};

	int n, m, res[20003];

	pll d[603][603];

	vector < Edge > adj[603];

	vector < int > Edge_id;

	pii a[20003];

	void dijkstra(int start) {
		priority_queue < pll, vector < pll >, greater < pll > > heap;
		for (int i = 1; i <= n; i++) d[start][i] = {INF, 0};
		d[start][start] = {0, 1};
		heap.push({d[start][start].fi, start});
		while (heap.size()) {
			auto u = heap.top();
			heap.pop();
			if (d[start][u.se].fi != u.fi) continue;
			for (auto v : adj[u.se]) {
				if (d[start][v.v].fi > u.fi + v.c) {
					d[start][v.v] = d[start][u.se];
					d[start][v.v].fi += v.c;
					heap.push({d[start][v.v].fi, v.v});
				}
				else if (d[start][v.v].fi == u.fi + v.c) d[start][v.v].se = (d[start][v.v].se + d[start][u.se].se) % MOD;
			}
		}
	}

	 main() {
		fast;
		//fre();
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int u, v, c;
			cin >> u >> v >> c; 
			adj[u].push_back({v, c, i});
			adj[v].push_back({u, c, i});
			a[i] = make_pair(u, v);
		}
		for (int i = 1; i <= n; i++) dijkstra(i);
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (d[i][j].fi == INF) continue;
				Edge_id.clear();
				int cur = i;
				while (cur != j) {
					for (auto x : adj[cur]) {
						if (d[cur][j].fi == x.c + d[x.v][j].fi) {
							Edge_id.push_back(x.id);
							cur = x.v;
							break;
						}
					}
				}
				for (auto index : Edge_id) {
					int u = a[index].fi;
					int v = a[index].se;
					if ((d[i][j].se == (d[i][u].se * d[v][j].se) % MOD && d[i][u].fi + d[u][v].fi + d[v][j].fi == d[i][j].fi)
					 || (d[i][j].se == (d[i][v].se * d[u][j].se) % MOD) && d[i][v].fi + d[u][v].fi + d[u][j].fi == d[i][j].fi) res[index] ++;
				}
			}
		}
		for (int i = 1; i <= m; i++) cout << res[i] << '\n';
	}

