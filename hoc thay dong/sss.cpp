#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1E9 + 7;
const ll prime[19] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

ll n, cnt[73], pw[100003], dp[74][(1 << 19)];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		cnt[x] ++;
	}
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = (pw[i - 1] * 2) % MOD;
	if (cnt[1] == 0) dp[1][0] = 1;
	else dp[1][0] = pw[cnt[1]];
	for (int i = 2; i <= 70; i++) {
		if (cnt[i]) {
			int msk = 0, x = i;
			for (int j = 0; j < 19; j++) {
				int cnt = 0;
				while (x % prime[j] == 0) {
					cnt ^= 1;
					x /= prime[j];
				}
				if (cnt) msk ^= (1 << j);
			}
			for (int mask = 0; mask < (1 << 19); mask++)
				dp[i][mask] = (dp[i - 1][mask] * pw[cnt[i] - 1] + dp[i - 1][mask ^ msk] * pw[cnt[i] - 1]) % MOD;
		}
		else for (int msk = 0; msk < (1 << 19); msk++) dp[i][msk] = dp[i - 1][msk];	
	}
	cout << (dp[70][0] - 1 + MOD) % MOD;
}

