#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, ans = 0;

bool vs[100003];

vector < ll > adj[100003];

void dfs(int u, int e1, int e2) {
	if (e1 != 0 && e2 != 0) ans ++;
	vs[u] = 1;
	int dem = 0, cnt = 0;
	for (auto v : adj[u]) {
		if (v == e2) {
			dem ++;
			ans --;
		}
		if (vs[v]) continue;
		cnt ++;
		dfs(v, u, e1);
	}
	ans += cnt * (cnt - 1) / 2 - dem;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0);
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
