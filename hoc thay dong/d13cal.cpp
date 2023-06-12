#include <bits/stdc++.h>

#define int long long
#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int MOD = 1e4 + 7;
const int val[16] = {0, 0, 0, 120, 3200, 5139, 6959, 3988, 8968, 4108, 9728, 444, 2199, 305, 9043, 2425};

vector < pii > a;

int inv[20][20];

int mu(int a, int b) {
	if (b == 0) return 1;
	int x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

signed main() {
	for (int i = 0; i <= 15; i++) a.push_back({i, val[i]});
	for (int i = 0; i <= 15; i++)
		for (int j = 0; j <= 15; j++) {
			inv[i][j] = mu((i - j + MOD) % MOD, MOD - 2);
		}
	int n;
	while (cin >> n && n != 0) {
		if (n <= 15) {
			cout << val[n] << '\n';
			continue;
		}
		int res = 0;
		for (int i = 1; i <= 15; i++) {
			int ans = 1;
			for (int j = 1; j <= 15; j++) if (i != j) 
				ans = (ans * (n - a[j].fi) * inv[a[i].fi][a[j].fi]) % MOD;
			res = (res + a[i].se * ans) % MOD;
		}
		cout << res << '\n';
	}
}