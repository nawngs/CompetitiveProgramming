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

const string NAME = "paths";
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

int n, m;

int d[503][503], cnt[503][503];

vector < pii > adj[503];

int main() {
	fast;
	int O; cin >> O;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) d[i][j] = INF;
		d[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
		d[u][v] = c;
		d[v][u] = c;
	}
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto v : adj[i]) {
				if (d[i][j] == d[v.fi][j] + v.se) cnt[i][j] ++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int res = 0;
			for (int x = 1; x <= n; x++) if (d[i][x] + d[x][j] == d[i][j]) res += cnt[x][j];
			cout << res << " ";
		}
		cout << '\n';
	}
}
