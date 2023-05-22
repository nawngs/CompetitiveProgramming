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
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[200003], id[200003];

vector < int > adj[200003];

multiset < int > ms[200003], tam;

void dfs(int u, int e) {
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		if (ms[v].size() > ms[u].size()) {
			tam = ms[u];
			ms[u] = ms[v];
			for (auto x : tam) ms[u].insert(x);
		}
		else for (auto x : ms[v]) ms[u].insert(x);
	}
	auto pos = ms[u].lower_bound(a[u]);
	if (pos == ms[u].end()) ms[u].insert(a[u]);
	else {
		ms[u].erase(pos);
		ms[u].insert(a[u]);
	}
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> a[i] >> u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}
	dfs(1, 0);
	cout << ms[1].size();
}
