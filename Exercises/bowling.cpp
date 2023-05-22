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

const string NAME = "bowling";
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

ll n, a[400003], dp[400003], r, s[400003], max_dp[400003], max_temp[400003];

void sol() {
	cin >> n >> r;	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= r; i++) {
		n ++;
		a[n] = 0;
	}
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	ll ans = -INF;
	for (int i = 1; i <= 2 * r + 1; i++) {
		if (i > n) break;
		if (i <= r) dp[i] = 0;
		else dp[i] = s[i] - s[0];
		max_dp[i] = max(max_dp[i - 1], dp[i]);
		max_temp[i] = max(max_temp[i - 1], max_dp[i] - s[i]);
		if (i > r) ans = max(ans, dp[i]);
	} 
	for (int i = 2 * r + 2; i <= n; i++) {
		dp[i] = s[i] + max_temp[i - 2 * r - 1];
		ans = max(ans, dp[i]);
		max_dp[i] = max(max_dp[i - 1], dp[i]);
		max_temp[i] = max(max_temp[i - 1], max_dp[i] - s[i]); 
	}
	//for (int i = 1; i <= n; i++) cout << i << " " << s[i] << " " << max_temp[i] << " " << dp[i] << '\n';
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
