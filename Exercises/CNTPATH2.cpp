#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define fi first
#define se second
#define pb push_back

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1E6;

ll n, m, k;

pll a[N + 3];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

namespace sub1 {
	vector < ll > adj[N + 3];
	ll dp[N + 3], s[N + 3];
	void solve() {
		for (int i = 1; i <= k; i++) adj[a[i].fi].pb(a[i].se);
		dp[0] = 1;
		for (int i = 0; i <= n * m + 1; i++) {
			int l, r;
			if (i != 0) {
				int id = (i + m - 1) / m;
				id --;
				l = max(0ll, id * m - m + 1), r = id * m;
				dp[i] += s[r] - (l == 0 ? 0 : s[l - 1]) + MOD;
				dp[i] %= MOD;
			}
			for (auto v : adj[i]) dp[v] = (dp[v] + dp[i]) % MOD;
			s[i] = (s[i - 1] + dp[i]) % MOD;
		}
		cout << dp[n * m + 1] << '\n';
	}
}

namespace sub3 {
	ll res = 0;
	bool choose[24];
	void back_track(int p) {
		if (p == k + 1) {
			int pre = 0, x = 0;
			ll total = 1;
			for (int i = 1; i <= k; i++) if (choose[i]) {
				int lid = (a[i].fi + m - 1) / m, rid = (a[i].se + m - 1) / m;
				if (pre > lid || (pre == lid && a[i].fi != x)) return ;
				total = (total * mu(m, lid - pre - 1)) % MOD;
				pre = rid;
				x = a[i].se;
			}
			total = (total * mu(m, n - pre)) % MOD;
			res += total;
			return ;
		}
		back_track(p + 1);
		choose[p] = 1;
		back_track(p + 1);
		choose[p] = 0;
	}
	void solve() {
		sort(a + 1, a + k + 1);
		back_track(1);
		cout << res << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("CNTPATH2.inp", "r", stdin);
   	freopen("CNTPATH2.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) cin >> a[i].fi >> a[i].se;
	if (n * m <= 1e6) sub1::solve();
	else if (k <= 20) sub3::solve();
}