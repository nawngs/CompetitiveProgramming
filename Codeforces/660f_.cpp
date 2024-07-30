#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[N + 3], s[N + 3], ss[N + 3], res;

double slope(pll x, pll y) {
	return (double)(y.se - x.se) / (x.fi - y.fi);
}

ll get(pll a, ll x) {
	return a.fi * x + a.se;
}

vector < pll > dq;

ll query(ll x) {
	ll l = 0, r = dq.size() - 1, mid, ans = get(dq[l], x);
	while (l < r) {
		mid = (l + r) / 2;
		ll v1 = get(dq[mid], x), v2 = get(dq[mid + 1], x);
		if (mid == dq.size() - 1) v2 = -LINF;
		ans = max({ans, v1, v2});
		if (v1 > v2) r = mid;
		else l = mid + 1;
	}
	return ans; 
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		ss[i] = ss[i - 1] + s[i];
	}
	dq.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		// cout << i << " " << query(s[i]) + i * s[i] - ss[i - 1] << '\n';
		res = max(res, query(s[i]) + i * s[i] - ss[i - 1]);
		while (dq.size() > 1 && slope(dq.back(), {-i, ss[i - 1]}) >= slope(dq[dq.size() - 2], dq.back())) dq.pop_back();
		dq.push_back({-i, ss[i - 1]});
		// cout << i << '\n';
		// for (auto x : dq) cout << x.fi << " " << x.se << " " << get(x, s[5]) + 5 * s[5] - ss[4] << '\n';
	}
	cout << res;
}