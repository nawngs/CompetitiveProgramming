#include <bits/stdc++.h>

using namespace std;

int t, res[53][53];

void sol(int n, int m, int a, int b) {
	memset(res, -1, sizeof(res));
	if (n + m - 1 > a || n + m - 1 > b) {
		cout << "Impossible" << '\n';
		return ;
	}
	cout << "Possible" << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 || i == n || j == m) res[i][j] = 1;
			if (res[i][j] == -1) res[i][j] = 1000;		
		}
		//cout << '\n';
	}
	res[1][1] = a - (n + m - 2);
	res[n][1] = b - (n + m - 2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << res[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	freopen("2021_round1_b.inp", "r", stdin);
	freopen("2021_round1_b.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << "Case #" << i << ": ";
		sol(a, b, c, d);
	}
}