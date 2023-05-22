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

const string NAME = "xorseg";
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

int n, q, a[50003];

namespace sub1 {
	int l, r, s, res = 0, cur = 0;
	void back_track(int pos) {
		if (pos == r + 1) {
			res += (cur == s);
			return ;
		}
		for (int i = 0; i < 2; i++) {
			if (i) cur ^= a[pos];
			back_track(pos + 1);
			if (i) cur ^= a[pos];
		}
	}
	void solve() {
		while(q--) {
			int t;
			cin >> t;
			if (t == 2) {
				cin >> l >> r >> s;
				res = 0;
				back_track(l);
				cout << res << '\n';
			}
			else {
				int u, v;
				cin >> u >> v;
				a[u] = v;
			}
		}
	}
}

namespace sub2 {
	ll dp[50003][1003];
	void solve() {
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 1000; j++) {
				dp[i][j] = dp[i - 1][j];
				dp[i][j] = (dp[i][j] + dp[i - 1][(j ^ a[i])]) % MOD;
			}
		}
		while (q--) {
			int t, l, r, s;
			cin >> t >> l >> r >> s;
			cout << dp[r][s] - (s == 0) << '\n';
		}
	}
}

int main() {
	fast;
	fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 20 && q <= 20) sub1::solve();
	else sub2::solve();
}
