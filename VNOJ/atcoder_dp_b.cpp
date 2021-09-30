#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se seond
#define pll pair < ll, ll >

using namespace std;

const ll INF = 2e9 + 7;
const ll nmax = 1e7;
const ll MOD = 1;

int n, a[100005], dp[100005], k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) dp[i] = INF;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) 
		for (int j = i - 1; j >= max(1, i - k); j--) dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));

	cout << dp[n];	
}
