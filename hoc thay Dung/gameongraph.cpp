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

int n, m, par[100003];

bool deleted[100003];

set < int > in[100003], out[100003];

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		out[u].insert(v); in[v].insert(u);
	}
	stack < int > st;
	for (int i = 1; i <= n; i++) 
		if (out[i].empty()) st.push(i);
	while (!st.empty()) {
		int u = st.top(); st.pop(); deleted[u] = 1;
		for (auto v : in[u]) {
			out[v].erase(u);
			if (out[v].empty()) st.push(v);
		}
	}	
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		if (sz(out[i]) == 1) st.push(i);
	}
	while (!st.empty()) {
		int u = st.top(), v = *out[u].begin(); st.pop();
		u = find(u); v = find(v);
		if (u == v) continue;
		if (sz(in[u]) > sz(in[v])) swap(u, v);
		for (auto x : in[u]) {
			out[x].erase(u); out[x].insert(v); in[v].insert(x);
			if (sz(out[x]) == 1) st.push(x); 
		}
		par[u] = v; 
	}
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		if (deleted[u] || deleted[v] || find(u) == find(v)) cout << 'B';
		else cout << "H";
	}
}