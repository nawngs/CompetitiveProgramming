#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define pllll pair < pll, pll >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "pathMM";
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

ll n, m, d[200003][2][2], max_edge[200003][2][2], min_edge[200003][2][2];

vector < pll > adj[200003];

void dijkstra() {
	priority_queue < pllll, vector < pllll >, greater < pllll > > heap;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				d[i][j][k] = LINF;
				max_edge[i][j][k] = -LINF;
				min_edge[i][j][k] = LINF;
			}
		}
	}
	d[1][0][0] = 0;
	heap.push({{d[1][0][0], 1}, {0, 0}});
	while (heap.size()) {
		auto x = heap.top();
		heap.pop();
		ll val = x.fi.fi;
		int u = x.fi.se;
		int j = x.se.fi;
		int k = x.se.se;
		if (val != d[u][j][k]) continue;
		for (auto e : adj[u]) {
			int v = e.fi;
			ll c = e.se;
			if ((j == 1 && c < min_edge[u][j][k]) || (k == 1 && c > max_edge[u][j][k])) continue;
			for (int p = 0; p < 2; p++) {
				if (p < j) continue;
				for (int q = 0; q < 2; q++) {
					if (q < k) continue;
					//if (p == 0 && q == 0) cout << d[v][p][q] << " " << val + c << '\n';
					if (p == 0 && q == 0 && d[v][p][q] > val + c) {
						d[v][p][q] = val + c;
						ll min_e = min(min_edge[u][j][k], c);
						ll max_e = max(max_edge[u][j][k], c);
						min_edge[v][p][q] = min_e;
						max_edge[v][p][q] = max_e;
						heap.push({{d[v][p][q], v}, {p, q}});
					}
					if (p == 0 && q == 1) {
						ll min_e = min(min_edge[u][j][k], c);
						ll max_e = max_edge[u][j][k];
						if (k == 0) max_e = max(max_e, c);
						if (d[v][p][q] > val + c - (k == 0) * max_e) {
							d[v][p][q] = val + c - (k == 0) * max_e;
							min_edge[v][p][q] = min_e;
							max_edge[v][p][q] = max_e;
							heap.push({{d[v][p][q], v}, {p, q}});
						}
					}
					if (p == 1 && q == 0) {
						ll min_e = min_edge[u][j][k];
						ll max_e = max(max_edge[u][j][k], c);
						if (j == 0) min_e = min(min_e, c);
						if (d[v][p][q] > val + c + (j == 0) * min_e) {
							d[v][p][q] = val + c + (j == 0) * min_e;
							min_edge[v][p][q] = min_e;
							max_edge[v][p][q] = max_e;
							heap.push({{d[v][p][q], v}, {p, q}});
						}
					}
					if (p == 1 && q == 1) {
						ll min_e = min_edge[u][j][k];
						ll max_e = max_edge[u][j][k];
						if (j == 0) min_e = min(min_e, c);
						if (k == 0) max_e = max(max_e, c);
						if (d[v][p][q] > val + c + (j == 0) * min_e - (k == 0) * max_e) {
							d[v][p][q] = val + c + (j == 0) * min_e - (k == 0) * max_e;
							min_edge[v][p][q] = min_e;
							max_edge[v][p][q] = max_e;
							heap.push({{d[v][p][q], v}, {p, q}});
						}
					} 
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) cout << d[i][1][1] << ' ';
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dijkstra();
}
