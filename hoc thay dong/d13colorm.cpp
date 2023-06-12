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

int n, m, a[33][33], color[63];

bool vs[63], th;

vector < int > adj[63];

void dfs(int u) {
	//cout << u << " " << color[u] << '\n';
	vs[u] = 1;
	if (color[u]) th = false;
	for (auto v : adj[u]) {
		if (color[u] != 0 && color[u] == color[v]) {
			cout << 0;
			exit(0);
		}
		if (!vs[v]) {
			if (color[u] != 0) color[v] = 3 - color[u];
			dfs(v);
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	ll full3 = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 3) {
				adj[i].push_back(j + n); adj[j + n].push_back(i);
			}
			else {
				if (a[i][j] == 1 || a[i][j] == 2) {
					full3 = false;
					if ((color[i] && color[i] != a[i][j]) || (color[j + n] && color[j + n] != a[i][j])) {
						cout << 0 << '\n';
						exit(0);
					}
					color[i] = color[j + n] = a[i][j];
				}
			}
		}
	ll res = 1;
	for (int i = 1; i <= n; i++) 
		if (color[i] && !vs[i]) {
			dfs(i);
		}
	for (int i = 1; i <= m; i++) 
		if (color[i + n] && !vs[i + n]) dfs(i + n);
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			dfs(i);
			res = (res * 2ll);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!vs[i + n]) {
			dfs(i + n);
			res = (res * 2ll);
		}
	}
	cout << res - full3;
}