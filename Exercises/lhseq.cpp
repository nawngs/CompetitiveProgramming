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

const string NAME = "lhseq";
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

int n, a[50003], f[50003], g[50003];

map < int, int > dp;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	f[1] = 1;
	dp.clear();
	dp[a[1]] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = 1;
		if (dp.find(a[i] - 1) != dp.end()) f[i] = max(f[i], dp[a[i] - 1] + 1);
		dp[a[i]] = max(dp[a[i]], f[i]);
	}
	dp.clear();
	g[n] = 1;
	dp[a[n]] = 1;
	for (int i = n - 1; i >= 1; i--) {
		g[i] = 1;
		if (dp.find(a[i] - 1) != dp.end()) g[i] = max(g[i], dp[a[i] - 1] + 1);
		dp[a[i]] = max(dp[a[i]], g[i]);
	}
	int res = 0;
	for (int i = 1; i < n; i++) {
		int len = min(2 * f[i] - 1, 2 * g[i] - 1);
		res = max(res, len);
	}
	cout << (n - res >= n - 1 ? -1 : n - res) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
