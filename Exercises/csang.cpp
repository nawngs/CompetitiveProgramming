#pragma GCC optimize ("O3")	
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, k, a[10005], dp[10005][105], f[10005];

pair < int, int > p[105];

int bs(int val) {
	int l = 1, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("CSANG.inp", "r", stdin);
	freopen("CSANG.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> p[i].fi >> p[i].se;
	sort(p + 1, p + k + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = 1e9 + 7;
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= k; j++) dp[i][j] = 1e9 + 7;
	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			for (int j = k; j >= 1; j --) {
				int temp = bs(a[i] - p[j].fi);
				if (temp >= i) break;
				dp[i][0] = min(dp[i][0], dp[temp][j]);
			}
		}
		f[i] = min(f[i], dp[i][0]);
		for (int j = 1; j <= k; j++) {
			int temp = bs(a[i] - p[j].fi);
			dp[i][j] =  min(dp[i][j], f[temp - 1] + p[j].se);
			f[i] = min(f[i], dp[i][j]);
		}
	}	
	cout << f[n];
}