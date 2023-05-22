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

ll n, m, a[1000005], dp[1000005];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[(i - 1) * m + j];
			dp[(i - 1) * m + j] = -INF;
		}
	}

	ll tam = a[1];
	dp[1] = tam;
	for (int j = 2; j <= m; j++) {
		dp[j] = max(tam + a[j], a[j]);
		tam = max(tam + a[j], a[j]);
	}
	tam = a[m];
	for (int j = m - 1; j >= 1; j--) {
		dp[j] = max(dp[j], tam + a[j]);
		tam = max(tam + a[j], a[j]);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) dp[(i - 1) * m + j] = max(dp[(i - 1) * m + j], dp[(i - 2) * m + j] + a[(i - 1) * m + j]);
		ll tam = dp[(i - 2) * m + 1] + a[(i - 1) * m + 1];
		for (int j = 2; j <= m; j++) {
			dp[(i - 1) * m + j] = max(dp[(i - 1) * m + j], tam + a[(i - 1) * m + j]);
			tam = max(tam, dp[(i - 2) * m + j]) + a[(i - 1) * m + j];
		}
		tam = dp[(i - 1) * m] + a[i * m];
		for (int j = m - 1; j >= 1; j--) {
			dp[(i - 1) * m + j] = max(dp[(i - 1) * m + j], tam + a[(i - 1) * m + j]);
			tam = max(tam, dp[(i - 2) * m + j]) + a[(i - 1) * m + j];
			}
	}
	ll ans = -INF;
	for (int i = 1; i <= m; i++) ans = max(ans, dp[(n - 1) * m + i]);
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
