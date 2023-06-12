#include<bits/stdc++.h>

#define int ll
#define ll long long

using namespace std;

const ll MOD = 111539786;

ll m, n, a[2903][2903];

int get_id(int i, int j) {
	return (i - 1) * n + j;
}

signed main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			a[get_id(i, j)][0] = x;
			if (i > 1) a[get_id(i, j)][get_id(i - 1, j)] = 1;
			if (j > 1) a[get_id(i, j)][get_id(i, j - 1)] = 1;
			if (i < m) a[get_id(i, j)][get_id(i + 1, j)] = 1;
			if (j < n) a[get_id(i, j)][get_id(i, j + 1)] = 1;
		}	
	for (int i = 1; i <= m * n; i++) {
		for (int j = 1; j <= m * n; j++) if (a[i][j]) {
			for (int k = i + 1; k <= n * m; k++) if (a[k][j] != 0) {
				int mul = (a[k][j] != a[i][j] ? 1 : 2);
				for (int p = 0; p <= n * m; p++)
					a[k][p] = (a[k][p] + mul * a[i][p]) % 3;
			}
		}
	}
	ll res = 1;
	for (int i = 1; i <= n * m; i++) {
		bool th = 1;
		for (int j = 1; j <= n * m; j++)
			if (a[i][j]) th = false;
		if (th && a[i][0]) res = 0;
		if (th && !a[i][0]) res = (res * 3) % MOD;
	}
	cout << res;
}