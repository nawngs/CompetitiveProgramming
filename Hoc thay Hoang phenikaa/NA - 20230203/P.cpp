#include <bits/stdc++.h>

#define name ""
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

ll n, val[400003];

pll f[400003];

pll a[100003], Q[100003];

pll operator -(const pll &x, const pll &y) {
	pll res;
	res.fi = x.fi - y.fi;
	res.se = x.se - y.se;
	return res;
}

pll operator +(const pll &x, const pll &y) {
	pll res;
	res.fi = x.fi + y.fi;
	res.se = x.se + y.se;
	return res;
}

int main() {
	//fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	vector < int > compress;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		compress.pb(a[i].fi); 
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> Q[i].fi >> Q[i].se;
		compress.pb(Q[i].fi);
	}
	sort(compress.begin(), compress.end()); 
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	memset(val, 60, sizeof(val));
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(compress.begin(), compress.end(), a[i].fi) - compress.begin();
		val[a[i].fi] = min(val[a[i].fi], a[i].se);
	}
	val[sz(compress)] = INF;
	for (int i = sz(compress) - 1; i >= 0; i--) {
		val[i] = min(val[i], val[i + 1]);
		if (i > 0) f[i].fi = compress[i] - compress[i - 1];
		else f[i].fi = 1;
		f[i].se = (INF - val[i]) * f[i].fi;
	}
	for (int i = 1; i < sz(compress); i++) 
		f[i] = f[i] + f[i - 1];
	for (int i = 1; i <= q; i++) {
		Q[i].fi = lower_bound(compress.begin(), compress.end(), Q[i].fi) - compress.begin();
		if (val[Q[i].fi] > Q[i].se) {
			cout << 0 << '\n';
			continue;
		}
		ll res = Q[i].se - val[Q[i].fi] + 1;
		int l = 0, r = sz(compress) - 1, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (val[mid] <= Q[i].se) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		pll temp = f[ans] - f[Q[i].fi];
		res += temp.se - (INF - Q[i].se - 1) * temp.fi;
		cout << res << '\n';
	}
}