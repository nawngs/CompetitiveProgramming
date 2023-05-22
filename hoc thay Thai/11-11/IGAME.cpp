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

int n, dem[2000003], sze[2000003];

bool CanWin[2000003];

vector < int > adj[2000003], res;

void dfs(int u, int e) {
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		sze[u] ++;
		dem[u] += !CanWin[v];
	}
	CanWin[u] = (dem[u] == sze[u]);
}

void re_root(int u, int e) {
	if (CanWin[u]) 
		res.push_back(u);
	for (auto v : adj[u]) {
		if (v == e) continue;
		sze[u] --;
		dem[u] -= (!CanWin[v]);
		CanWin[u] = (dem[u] == sze[u]);
		sze[v] ++;
		dem[v] += (!CanWin[u]);
		CanWin[v] = (dem[v] == sze[v]);
		re_root(v, u);
		sze[v] --;
		dem[v] -= (!CanWin[u]);
		CanWin[v] = (dem[v] == sze[v]);
		sze[u] ++;
		dem[u] += (!CanWin[v]);
		CanWin[u] = (dem[u] == sze[u]);
	}
	cout << dem[u] << " " << sze[u] << " " << CanWin[u] << '\n';
	
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	dfs(1, 0);
	re_root(1, 0);
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << '\n';
}
