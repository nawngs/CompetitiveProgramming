#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "stalingrad";
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

int n, ance[400003], children[400003], cnt[400003], q, par[400003][20], h[400003], Daddy[400003], in[400003], timer = 0, val[400003];

vector < int > adj[400003];

set < int > ms[400003];

void dfs(int u) {
	in[u] = ++ timer;
	val[in[u]] = u;
	children[u] = 1;
	for (auto v : adj[u]) {
		if (u == 1) ance[v] = v;
		else ance[v] = ance[u];
		par[v][0] = u;
		h[v] = h[u] + 1;
		dfs(v);
		children[u] += children[v];
	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = 19; j >= 0; j --) {
			 if (h[par[v][j]] >= h[u]) {
			 	v = par[v][j];
			 }
		} 
	}
	if (u == v) return u;
	for (int j = 19; j >= 0; j --) {
		if (par[u][j] != par[v][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int main() {
	fast;
	fre();
	int O; cin >> O;
	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	dfs(1);
	for (int j = 1; j <= 19; j++)
		for (int i = 1; i <= n; i++) 
			par[i][j] = par[par[i][j - 1]][j - 1];
	int res = 0, total = 0;
	while (q--) {
		char c; int u;
		cin >> c >> u;
		int p = ance[u];
		if (cnt[p] != 0) total = total - (children[Daddy[p]] - cnt[p]);
		if (c == '+') {
			cnt[p] ++;
			if (cnt[p] == 1) res ++;
			ms[p].insert(in[u]);
			Daddy[p] = LCA(val[*ms[p].begin()], val[*ms[p].rbegin()]);
			total = total + (children[Daddy[p]] - cnt[p]);
			cout << res << " " << total << '\n';
		}
		else {
			cnt[p] --;
			if (cnt[p] == 0) res --;
			ms[p].erase(in[u]);
			if (!ms[p].empty()) {
				Daddy[p] = LCA(val[*ms[p].begin()], val[*ms[p].rbegin()]);
				total = total + (children[Daddy[p]] - cnt[p]);
			}
			cout << res << " " << total << '\n';
		}
	}
}
