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

int m, n, dp[20][(1 << 16)];

vector < int > a[10003], adj[(1 << 16)];

void sol() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		a[i].clear();
		a[i].resize(n);
		for (auto &x : a[i]) cin >> x;
	}
	for (int mask = 1; mask < (1 << n); mask++) {
		adj[mask].clear();
		for (int change = 1; change < n; change++) {
			int new_mask = ((mask << change) | (mask >> (n - change))) & ((1 << n) - 1);
			adj[mask].push_back(new_mask);
		}

	}
	sort(a + 1, a + m + 1, [&](vector < int > &x, vector < int > &y) {
		int val1 = 0, val2 = 0;
		for (auto val : x) val1 = max(val1, val);
		for (auto val : y) val2 = max(val2, val);
		return val1 > val2;
	});
	for (int i = 0; i <= min(m, n); i++)
		for (int j = 0; j < (1 << n); j++) dp[i][j] = -INF;
	dp[0][0] = 0;
	for (int i = 1; i <= min(m, n); i++) {
		for (int mask = 0; mask < (1 << n); mask++) {
			dp[i][mask] = max(dp[i][mask], dp[i - 1][mask]);
			for (int j = 0; j < n; j++) if (mask & (1 << j)) dp[i][mask] = max(dp[i][mask], dp[i][mask ^ (1 << j)] + a[i][j]);
		}
		for (int mask = 1; mask < (1 << n); mask++) 
			for (auto x : adj[mask]) dp[i][x] = max(dp[i][x], dp[i][mask]);
	}
	cout << dp[min(m, n)][(1 << n) - 1] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
