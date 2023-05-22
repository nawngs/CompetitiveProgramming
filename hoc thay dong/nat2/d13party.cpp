#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, color[NMAX + 3];

int par[NMAX + 3];

vector < int > adj[NMAX + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[v] = u; return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u; cin >> u;
		if (u != -1) adj[u].pb(i), adj[i].pb(u);
		par[i] = i;
		color[i] = -1;
	}
	int q; cin >> q;
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) {
			color[a] = b;
			for (auto x : adj[a]) 
				if (color[x] == b) join(a, x);
		}
		else {
			a = find(a), b = find(b);
			cout << (a == b ? "YES" : "NO") << '\n';
		}
	}
}