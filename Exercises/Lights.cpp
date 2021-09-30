#include <bits/stdc++.h>

using namespace std;

int n, m, b[23][23], a[23][23], f[23], ans = 1e9, dem = 0;

void backtrack(int pos) {
	if (pos == n + m + 1) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) a[i][j] = b[i][j];

		for (int i = 1; i <= n + m; i++) {
			if (f[i] == 1) {
				if (i <= n) {
					for (int j = 1; j <= m; j++) a[i][j] = (!a[i][j]);
				}
				else for (int j = 1; j <= n; j++) a[j][i - n] = (!a[j][i - n]);
			}
		}
		bool th = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] != 1) {
					th = false;
					break;
				}
			}
		}
		if (th) {
			ans = min(ans, dem);
			return ;
		}
		th = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] != 0) {
					th = false;
					break;
				}	
			}
		}
		if (th) {
			ans = min(ans, dem);
			return ;
		}
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		f[pos] = i;
		dem += f[pos];
		backtrack(pos + 1);
		dem -= f[pos];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> b[i][j];

	backtrack(1);
	if (ans == 1e9) cout << "No solution";
	else cout << ans;
}