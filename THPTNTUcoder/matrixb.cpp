#include <bits/stdc++.h>

using namespace std;

int n, m, a[305][305], s[305][305], d[305][305];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) a[i][j] = -1;
			s[i][j] = s[i][j - 1] + a[i][j]; 
		}
	}
	int ans = -1e9;
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			d[i][j] = s[1][j] - s[1][i - 1];
			ans = max(ans, d[i][j]);
			//cout << i << " " << j << " " << d[i][j] << '\n';
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			for (int j = k + 1; j <= m; j++) {
				ans = max(ans, d[k][j] + s[i][j] - s[i][k - 1]);
				d[k][j] = max(d[k][j] + a[i][k] + a[i][j], s[i][j] - s[i][k - 1]);
				//cout << i << " " << k << " " << j << " " << ans << '\n';
			}
		}
	}
	cout << ans;
}