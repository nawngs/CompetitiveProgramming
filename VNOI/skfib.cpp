#include <bits/stdc++.h>

using namespace std;

const int nmax = 4e6;

int t, n, a[2505], dp[2505][2505];
int pos[nmax + 5];
	
void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += 2e6;
	}

	for (int i = 1; i <= nmax; i++) pos[i] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dp[i][j] = 0;

	int ans = 0;
	for (int i = n - 1; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			int temp = a[i] + a[j] - 2e6;
			if (pos[temp] <= j) {
				pos[a[j]] = j;
				continue;
 			}
			//cout << i << " " << j << " " << tam << '\n';
			dp[i][j] = dp[j][pos[temp]] + 1;
			ans = max(ans, dp[i][j]);
			pos[a[j]] = j;
		}
	}
	cout << ans + 2 << '\n';
}

int main() {
	cin >> t;
	while (t --) sol();
}