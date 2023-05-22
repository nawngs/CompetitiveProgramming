#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >	
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll dp[70][70], m, k;

ll calc(ll r, ll cnt) {
	ll res = (__builtin_popcountll(r) == cnt);
	for (ll i = 63; i >= 0; i--) {
		if ((r >> i) & 1ll) {
			res += dp[i][cnt];
			cnt --;
			if (cnt < 0) break;
		}
	}
	return res;
}

int main() {
	fast;
	dp[0][0] = 1;
	for (int i = 1; i <= 63; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) 
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	}
	cin >> m >> k;
	if (m == 0) {
		cout << 1 << '\n';
		return 0;
	}
	ll l = m, r = LINF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (calc(mid * 2, k) - calc(mid, k) >= m) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}
