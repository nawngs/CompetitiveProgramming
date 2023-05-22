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

const string NAME = "dienbien";
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

int t, n, k, dp[300003], ans = 0;

bool invalid[300003];

vector < int > adj[300003];

bool th = true;

void dfs(int u, int e) {
	if (!th) return ;
	if (invalid[u]) {
		for (auto v : adj[u]) {
			if (v == e) continue;
			if (invalid[v]) {
				th = false;
				return ;
			}
			dfs(v, u);
			if (dp[v]) ans ++;
		}
	}
	else {
		for (auto v : adj[u]) {
			if (v == e) continue;
			dfs(v, u);
			if (invalid[v]) dp[u] ++;
			else dp[u] += dp[v];
		}
		if (dp[u] > 1) {
			dp[u] = 0;
			ans ++;
		}
	}
	

} 

int main() {
	fast;
	//fre();
	cin >> t;
	while (cin >> n >> k && n != -1 && k != -1) {
		for (int i = 1; i <= n; i++) {
			invalid[i] = false;
			adj[i].clear();
			dp[i] = 0;
		}
		for (int i = 1; i <= k; i++) {
			int x;
			cin >> x;
			invalid[x] = 1;
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		th = 1;
		ans = 0;
		dfs(1, 0);
		cout << (th ? ans : -1) << '\n';
	}

}
