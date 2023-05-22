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

int n, res[100003], cnt_child[100003];

bool used[100003];

vector < int > adj[100003];

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
		if (v == e || used[v]) continue;
		if (cnt_child[v] * 2 > sze) return get_centroid(v, sze, u);
	}
	return u;
}

void centroid(int u = 1, int num = 0) {
	int C = get_centroid(u, dfs(u));
	used[C] = 1;
	res[C] = num;
	for (auto v : adj[C]) 
		if (!used[v]) centroid(v, num + 1);
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid();
	for (int i = 1; i <= n; i++) if (res[i] > 26) {
		cout << "Impossible!" << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) cout << (char) (res[i] + 'A') << ' ';
}
