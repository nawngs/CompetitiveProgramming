#include <bits/stdc++.h>

#define fi first
#define se second
#define pll pair < long long, long long >
#define ll long long

using namespace std;

const ll INF = 1e18 + 711;

ll n, m, k, a[200005], dp[200005], ans = 0;

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int j = 1; j <= k; j++) {
		deque < pll > dq;
		for (int i = 0; i <= j - 1; i++) {
			while (dq.size() && dq.back().fi <= dp[i]) dq.pop_back();
			dq.push_back({dp[i], i});
		}
		for (int i = j; i <= n; i++) {
			while (dq.size() && dq.front().se < i - m) dq.pop_front();
			ll tam = dp[i];
			dp[i] = dq.front().fi + a[i] * j;
			//cout << i << " " << j << " " << dp[i][j] << '\n';
			while (dq.size() && dq.back().fi <= tam) dq.pop_back();
			dq.push_back({tam, i});
			if (j == k) ans = max(ans, dp[i]);
		}
	}
	cout << ans;
}
