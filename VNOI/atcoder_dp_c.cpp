#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se seond
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, a[100005], b[100005], c[100005], dp[100005][5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

	for (int i = 1; i <= n; i++) {
		dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + a[i];
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + b[i];
		dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + c[i];
	}
	cout << max(dp[n][1], max(dp[n][2], dp[n][3]));
}
