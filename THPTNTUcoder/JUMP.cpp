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

ll n, a[30003], dp[30003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = 0;
	dp[2] = abs(a[2] - a[1]);
	for (int i = 3; i <= n; i++) dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + 3 * abs(a[i] - a[i - 2]));
	cout << dp[n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
