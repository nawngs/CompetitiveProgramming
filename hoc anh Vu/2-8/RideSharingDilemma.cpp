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

struct Edge {
	int u, v, c;
} edges[40003];

int n, m, d[203][203], first_edge[203][203], res[40003];

vector < int > adj[203];

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	for (int ily = 1; ily <= t; ily++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = INF;
				first_edge[i][j] = -1;
			}
			d[i][i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			res[i] = INF;
			int u, v, c;
			cin >> u >> v >> c;
			u ++;
			v ++;
			d[u][v] = d[v][u] = c;
			first_edge[u][v] = first_edge[v][u] = i;
			adj[u].push_back(i);
			adj[v].push_back(i);
			edges[i].u = u;
			edges[i].v = v;
			edges[i].c = c;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
						first_edge[i][j] = first_edge[i][k];
					}
				}
			}
		}
		// for (int i = 1; i <= n; i++)
		// 	for (int j = 1; j <= n; j++) cout << i << " " << j << " " << d[i][j] << '\n';
		for (int s = 1; s <= n; s++) {
			for (auto x : adj[s]) {
				auto tam = edges[x];
				if (d[tam.u][tam.v] < tam.c) res[x] = min(res[x], d[tam.u][tam.v]);
			}
			for (int i = 1; i <= m; i++) {
				auto tam = edges[i];
				if (tam.u == s || tam.v == s) continue;
				if (first_edge[s][tam.u] == first_edge[s][tam.v]) continue;
				int circle = d[s][tam.u] + d[tam.v][s] + tam.c;
				//cout << s << " " << tam.u << " " << tam.v << " " << tam.c << " " << circle << '\n';
				int id = first_edge[s][tam.u];
				res[id] = min(res[id], circle - edges[id].c);
				id = first_edge[s][tam.v];
				res[id] = min(res[id], circle - edges[id].c);
				//cout << circle << '\n';
			}
		}
		cout << "Case " << ily << ":\n";
		for (int i = 1; i <= m; i++) {
			if (res[i] == INF) cout << "impossible" << '\n';
			else cout << res[i] + 1 << '\n';
		}
	}
}
