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

int a, b, m, id[2003][2003], assigned[2003][2003], color[100003];

vector < int > adj[2003];

void dfs(int u, int v, int c1, int c2) {
	int z = assigned[v][c2];
	if (!z) {
		assigned[v][c1] = 0;
		return ;
	}
	dfs(v, z, c2, c1);
	assigned[v][c1] = z; assigned[z][c1] = v;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> a >> b >> m;
	int res = 0;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v; v += a;
		id[u][v] = id[v][u] = i;
		adj[u].push_back(v); adj[v].push_back(u);
		res = max(res, sz(adj[u])); res = max(res, sz(adj[v]));
	}
	cout << res << '\n';
	for (int u = 1; u <= a; u++) {
		for (auto v : adj[u]) {
			bool th = false;
			for (int i = 1; i <= res; i++) {
				if (!assigned[u][i] && !assigned[v][i]) {
					th = 1;
					assigned[u][i] = v; assigned[v][i] = u;
					break;
				}
			}
			if (th) continue;
			int coloru = 0, colorv = 0;
			for (int i = 1; i <= res; i++) {
				if (assigned[u][i] && !assigned[v][i]) coloru = i;
				if (!assigned[u][i] && assigned[v][i]) colorv = i;
			}
			dfs(u, v, coloru, colorv);
			assigned[u][colorv] = v;
			assigned[v][colorv] = u;
		}
	}
	for (int u = 1; u <= a; u++)
		for (int c = 1; c <= res; c++) if (assigned[u][c]) color[id[u][assigned[u][c]]] = c;
	for (int i = 1; i <= m; i++) cout << color[i] << ' ';
}