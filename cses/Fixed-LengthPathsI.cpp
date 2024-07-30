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

const string NAME = "tree-distance";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, cnt_child[NMAX + 3], res = 0, cnt[NMAX + 3];

bool used[NMAX + 3];

vector < int > adj[NMAX + 3];

int dfs(int u, int e = 0) {
	cnt_child[u] = 1;
	for (auto v : adj[u]) {
		if (v == e || used[v]) continue;
		cnt_child[u] += dfs(v, u);
	}
	return cnt_child[u];
}

int get_centroid(int u, int sze, int e = 0) {
	for (auto v : adj[u]) {
		if (used[v] || v == e) continue;
		if (cnt_child[v] * 2 > sze) return get_centroid(v, sze, u);
	}
	return u;
}

void dfs2(int u, int e, int len, bool update) {
	if (len > k) return ;
	if (update) res += cnt[k - len];
	else cnt[len] ++;
	for (auto v : adj[u]) {
		if (v == e || used[v]) continue;
		dfs2(v, u, len + 1, update);
	}
}

void centroid(int u = 1) {
	int C = get_centroid(u, dfs(u));
	used[C] = 1;
	cnt[0] = 1;
	for (auto v : adj[C]) 		
		if (!used[v]) {
			dfs2(v, C, 1, 1);
			dfs2(v, C, 1, 0);
		}
	int i = 1;
	while (cnt[i] != 0) {
		cnt[i] = 0;
		i ++;
	}
	for (auto v : adj[C]) 
		if (!used[v]) centroid(v);
}

int main() {
	fast;
	fre();
	cin >> n >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid();
	cout << res;
}
