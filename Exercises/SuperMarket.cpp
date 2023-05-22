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

const string NAME = "supermarket";
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

int n, a[1003], dp[1003][1003];

int calc(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (j >= n) return max(a[i], a[j]);
	dp[i][j] = min(calc(i, j + 2) + max(a[j], a[j + 1]), min(calc(j + 1, j + 2) + max(a[i], a[j]), calc(j, j + 2) + max(a[i], a[j + 1])));
	return dp[i][j];
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = -INF;
	memset(dp, 255, sizeof(dp));
	cout << calc(1, 2) << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
