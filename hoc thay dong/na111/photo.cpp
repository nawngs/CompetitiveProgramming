#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k, f[5003];

pii a[5003];

pll dp[5003];

int get(int l, int r) {
	if (r < l) return 0;
	return (r - l + 1) * (r - l + 1);
}

pii calc(ll x) {
	for (int i = 1; i <= m; i++) dp[i] = {LINF, k + 1};
	for (int i = 1; i <= n; i++) {
		int st = a[i].fi;
		for (int pre = i - 1; pre >= 0; pre--) {
			pll val = dp[f[st - 1]];
			val.fi += get(st, a[i].se) - get(st, f[st - 1]) + x; val.se ++;
			dp[a[i].se] = min(dp[a[i].se], val);
			st = min(st, a[pre].fi);
		}
	}
	//cout << x << " " << dp[a[n].se].fi - dp[a[n].se].se * x << " " << dp[a[n].se].se << '\n';
	return dp[a[n].se];
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
		f[a[i].fi] = max(f[a[i].fi], a[i].se);
	}
	for (int i = 1; i <= m; i++) f[i] = max(f[i], f[i - 1]);
	sort(a + 1, a + n + 1, [&](pii &x, pii &y) {
		if(x.se != y.se) return x.se < y.se;
		return x.fi > y.fi;
	});
	ll l = 1, r = 1e8, mid, ans = LINF;
	while (l <= r) {
		mid = (l + r) / 2;
		pii res = calc(mid);
		if (res.se <= k) ans = res.fi - mid * res.se, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
}