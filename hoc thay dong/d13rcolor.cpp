#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int d1x[5] = {0, -1, -1, 1, 1};
const int d1y[5] = {0, -1, 1, -1, 1};
const int d2x[4] = {-1, 0, 0, 1};
const int d2y[4] = {0, -1, 1, 0};

int m, n;

char s[1005][1005], a[1005][1005];

void solve() {
	int dem = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
			a[i][j] = '.';
		}
	}
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++) {
		bool th = 1;
		for (int p = 0; p < 5; p++) {
			int newi = i + d1x[p], newj = j + d1y[p];
			if (newi < 1 || newj < 1 || newi > m || newj > n) continue;
			if (s[newi][newj] != '*') {
				th = false;
				break;
			}
		}
		if (!th) continue;
		for (int p = 0; p < 5; p++) {
			int newi = i + d1x[p], newj = j + d1y[p];
			if (newi < 1 || newj < 1 || newi > m || newj > n) continue;
			a[newi][newj] = '*';
		}
	}
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++) {
		bool th = 1;
		for (int p = 0; p < 4; p++) {
			int newi = i + d2x[p], newj = j + d2y[p];
			if (newi < 1 || newj < 1 || newi > m || newj > n) continue;
			if (s[newi][newj] != '*') {
				th = false;
				break;
			}
		}
		if (!th) continue;
		for (int p = 0; p < 4; p++) {
			int newi = i + d2x[p], newj = j + d2y[p];
			if (newi < 1 || newj < 1 || newi > m || newj > n) continue;
			a[newi][newj] = '*';
		}
	}
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++) if (s[i][j] == '*' && a[i][j] == '.'){
		cout << "NO" << '\n';
		return ;
	}
	cout << "YES" << '\n';
}

int main() {
	while (cin >> m >> n) solve();
}