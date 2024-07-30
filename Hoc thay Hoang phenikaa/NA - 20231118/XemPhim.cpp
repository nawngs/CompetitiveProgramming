#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k;
string s;
int a[N];

int nxt[N][4];
pair<int, int> dp[N][3];

inline void upd(pair<int, int> &x, const pair<int, int> &y) {
	if (x.first > y.first) x = y;
	else if (x.first == y.first && x.second < y.second)
		x = y;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> k >> s;
	for (int i = 1; i <= n; i++)
		a[i] = (isdigit(s[i - 1]) ? s[i - 1] - '0' : 3);
	
	for (int i = 1; i <= n * 2; i++)
		for (int j = 1; j <= 2; j++)
			dp[i][j] = {n + 1, n + 1};
	
	for (int s: {1, 2, 3}) nxt[2 * n + 1][s] = 2 * n + 1;
	for (int i = 2 * n; i > 0; i--) {
		for (int s: {1, 2, 3}) 
			nxt[i][s] = nxt[i + 1][s];
		if (i <= n) nxt[i][a[i]] = i;
	}
	
	if (a[1] != 2) upd(dp[k][1], {1, 2});
	if (a[1] != 1) upd(dp[k][2], {1, 2});
	upd(dp[k][1], {2, k + 1});
	upd(dp[k][2], {2, k + 1});
	
	for (int i = k; i <= n; i++) {
		{ // dp[i][1]
			auto cur = dp[i][1];
			int pos = nxt[cur.second][2];
			if (pos <= i) {
				upd(dp[pos + k - 1][2], {cur.first + 1, i + 1});
			} else {
				if (a[i + 1] != 2) upd(dp[i + k][1], {cur.first + 1, i + 1});
				if (a[i + 1] != 1) upd(dp[i + k][2], {cur.first + 1, i + 1});
				upd(dp[i + k][1], {cur.first + 2, i + k});
				upd(dp[i + k][2], {cur.first + 2, i + k});
			}
		}
		{ // dp[i][2]
			auto cur = dp[i][2];
			int pos = nxt[cur.second][1];
			if (pos <= i) {
				upd(dp[pos + k - 1][1], {cur.first + 1, i + 1});
			} else {
				if (a[i + 1] != 2) upd(dp[i + k][1], {cur.first + 1, i + 1});
				if (a[i + 1] != 1) upd(dp[i + k][2], {cur.first + 1, i + 1});
				upd(dp[i + k][1], {cur.first + 2, i + k});
				upd(dp[i + k][2], {cur.first + 2, i + k});
			}
		}
	}
	
	// for (int i = 1; i <= n; i++)
		// for (int j = 1; j <= 2; j++)
			// cerr << "dp " << i << ", " << j << " >> " << dp[i][j].first << ", " << dp[i][j].second<<"\n";
	
	int ans = n;
	for (int i = n; i <= n * 2; i++)
		for (int j = 1; j <= 2; j++)
			ans = min(ans, dp[i][j].first + (nxt[dp[i][j].second][3 - j] <= n));
		
	cout << ans;
	
	return 0;
}