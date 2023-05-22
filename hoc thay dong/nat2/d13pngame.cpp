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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n1, n2, m, assgined[2003], visited[2003], t = 0;

vector < int > adj[1003];

bool kuhn(int u) {
	if (visited[u] == t) return false;
	visited[u] = t;
	for (auto v : adj[u]) {
		if (!assgined[v] || kuhn(assgined[v])) {
			assgined[v] = u;
			assgined[u] = v;
			return true;
		}
	}
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n1 >> n2 >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v; v += n1;
		adj[u].pb(v); adj[v].pb(u);
	}
	int mx = 0;
	for (int i = 1; i <= n1; i++) {
		t ++;
		mx += kuhn(i);
	}
	for (int u = 1; u <= n1; u++) {
		if (!assgined[u]) {
			cout << 'P';
			continue;
		}
		int v = assgined[u], cnt = mx;
		assgined[v] = 0; cnt --; 
		t ++;
		cnt += kuhn(v);
		if (cnt == mx) {
			cout << 'P';
			assgined[u] = 0;
		}
		else {
			cout << 'N';
			assgined[v] = u;
		}
		//for (int i = 1; i <= n1; i++) cout << i << " " << assgined[i] << '\n';
	}
	cout << '\n';
	for (int u = n1 + 1; u <= n1 + n2; u++) {
		if (!assgined[u]) {
			cout << 'P';
			continue;
		}
		int v = assgined[u], cnt = mx;
		assgined[v] = 0; cnt --; 
		t ++;
		cnt += kuhn(v);
		if (cnt == mx) {
			cout << 'P';
			assgined[u] = 0;
		}
		else {
			cout << 'N';
			assgined[v] = u;
		}
	}
}