#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se seond
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

int n, a[100005], dp[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[2] = abs(a[2] - a[1]);
	for (int i = 3; i <= n; i++) dp[i] = min(dp[i - 2] + abs(a[i] - a[i - 2]), dp[i - 1] + abs(a[i] - a[i - 1]));
	cout << dp[n];
}
