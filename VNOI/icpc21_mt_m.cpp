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

ll n, m, f[100005], ans = 0, cnt = 0;

bool vs[100005];

vector < int > adj[100005];

void create() {
	f[3] = 6;
	for (int i = 4; i <= 100000; i ++) f[i] = (f[i - 1] * 1ll * i) % MOD;
}

void dfs(int u) {
	if (vs[u]) return ;
	cnt ++;
	vs[u] = true;
	for (auto v : adj[u]) if (!vs[v]) dfs(v);
	
}

void sol() {
	create();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			cnt = 0;
			dfs(i);
			ans = (ans + f[cnt]) % MOD;
		}
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
