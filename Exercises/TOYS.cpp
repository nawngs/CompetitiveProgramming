#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

int n, a[55], dp[55][1505][1505], f[17];

long long sum1 = 0, sum2 = 0, ans = -1, sum = 0;

void backtrack(int pos) {
	for (int i = 0; i <= 2; i++) {
		f[pos] = i;
		if (pos == n) {
			long long sum1 = 0, sum2 = 0;
			for (int j = 1; j <= n; j++) {
				if (f[j] == 1) sum1 += a[j];
				if (f[j] == 2) sum2 += a[j];
			}
			if (sum1 == sum2) ans = max(ans, sum1);
		}
		else backtrack(pos + 1);
	}
}

void sub1() {
	backtrack(1);
	cout << ans;
}

void sub2() {
	int res = -1;
	dp[0][0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum / 2; j++) {
			for (int k = 0; k <= sum / 2; k++) {
				dp[i][j][k] = dp[i - 1][j][k];
				if (j - a[i] >= 0) dp[i][j][k] = dp[i][j][k] | dp[i - 1][j - a[i]][k];
				if (k - a[i] >= 0) dp[i][j][k] = dp[i][j][k] | dp[i - 1][j][k - a[i]];
				if (dp[i][j][k] == 1 && j == k) res = max(res, j);
			}
		}
	}
	cout << res;
	return ;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("TOYS.inp", "r", stdin);
	freopen("TOYS.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (n <= 15) sub1();
	else sub2();
}