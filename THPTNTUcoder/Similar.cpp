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

int n, a[1005], b[1005], s[1005], dp[1005][1005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		s[i] = s[i - 1] + (a[i] == b[i]);
		dp[i][i] = (a[i] == b[i]);
	}	
	for (int k = 2; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
			dp[i][j] = dp[i + 1][j - 1] + (b[j] == a[i]) + (a[j] == b[i]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) 
			ans = max(ans, s[i - 1] + dp[i][j] + s[n] - s[j]);
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
