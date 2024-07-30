// [+] dinhmanhhungwillwinioi2024
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

int n, a[N];

int pre[N], dp[N];

inline int cong(int x, int y) {
	return (x += y) >= mod ? x - mod : x;
}

inline int tru(int x, int y) {
	return (x -= y) < 0 ? x + mod : x;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i + n] = a[i];
	vector<pair<int, int>> prv, cur;
	for (int i = 1; i <= n * 2; i++) {
		cur.emplace_back(a[i], i);
		for (const auto &elem: prv) {
			if (elem.first % cur.back().first == 0) continue;
			cur.emplace_back(__gcd(cur.back().first, elem.first), elem.second);
			if (cur.back().first == 1) break;
		}
		pre[i] = (cur.back().first > 1 ? 1 : cur.back().second + 1);
		swap(prv, cur);
		cur.clear();
	}
	dp[n - 1] = 1;
	for (int i = n; i < n * 2; i++) 
		dp[i] = cong(dp[i - 1], tru(dp[i - 1], dp[max(pre[i] - 2, 0)]));
	int ans = tru(dp[n + n - 1], dp[n + n - 2]), gcd = a[n];
	for (int i = n - 1; i > 0; i--) {
		if (__gcd(gcd, a[i]) != gcd) {
			gcd = __gcd(gcd, a[i]);
			if (gcd == 1) break;
			for (int j = i - 1; j < n; j++)
				dp[j] = 1;
			for (int j = n; j < i + n; j++)
				dp[j] = cong(dp[j - 1], tru(dp[j - 1], dp[max(pre[j] - 2, 0)]));
		}
		ans = cong(ans, tru(dp[i + n - 1], dp[i + n - 2]));
	}
	cout << ans;
	return 0;
}