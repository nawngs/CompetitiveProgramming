#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, cnt[65][8];

int main() {
	fastflow;
	cin >> n;
	if (n == 1) {
		cout << 6 << '\n';
		return 0;
	}
	cnt[n][1] = 1;
	cnt[n][2] = 1;
	cnt[n][3] = 1;
	cnt[n][4] = 1;
	cnt[n][5] = 1;
	cnt[n][6] = 1;

	ll ans = 0;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= 6; j++) {
			for (int cl1 = 1; cl1 <= 6; cl1++) {
				for (int cl2 = 1; cl2 <= 6; cl2 ++) {
					if (cl1 == j || cl1 == (j % 2 == 1 ? j + 1 : j - 1) 
					 || cl2 == j || cl2 == (j % 2 == 1 ? j + 1 : j - 1)) continue;
						cnt[i][j] += (cnt[i + 1][cl1] * cnt[i + 1][cl2]) % MOD;
						cnt[i][j] %= MOD;
				}
			}
			if (i == 1) ans = (ans + cnt[i][j]) % MOD;
		}
	}
	cout << ans;
}
