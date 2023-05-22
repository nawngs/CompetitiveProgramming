#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, d[503][503], cnt[503][503];

vector < pii > adj[503];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			d[i][j] = INF;
			if (i == j) d[i][j] = 0;
		}
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, c}); adj[v].push_back({u, c});
		d[u][v] = min(d[u][v], c); d[v][u] = d[u][v];
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			for (auto e : adj[i]) {
				if (d[i][j] == d[e.fi][j] + e.se) cnt[i][j] ++;
			}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			int res = 0;
			for (int k = 1; k <= n; k++) if (d[i][k] + d[k][j] == d[i][j]) res += cnt[k][j];
			cout << res << ' ';
		}
	
}