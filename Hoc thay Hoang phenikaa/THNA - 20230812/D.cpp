//[UNFINISHED]
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, q;

ll s[NMAX + 3];

pii a[NMAX + 3];

vector < pll > cd;

set < tuple < int, int, int > > ms, Insert, Erase;

map < ll, ll > cnt;

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	ms.insert({1, n, 0});
	for (int i = 1; i <= m; i++) {
		cin >> a[i].fi >> a[i].se;
		s[i] = s[i - 1] + a[i].se - a[i].fi + 1;
		auto cur = ms.upper_bound(make_tuple(a[i].fi, -1, -1));
		if (cur != ms.begin()) cur --;
		while (cur != ms.end()) {
			int l1, r1, id, r, l; tie(l1, r1, id) = *cur;
			if (l1 > a[i].se) break;
			if (r1 < a[i].fi) {
				cur ++;
				continue;
			}
			r = min(r1, a[i].se);
			l = max(l1, a[i].fi);
			if (id != 0) cnt[s[i - 1] + 1ll * (l - a[i].fi) - s[id - 1] - 1ll * (l - a[id].fi)] += 1ll * (r - l + 1);
			Erase.insert(*cur);
			if (l1 < l) Insert.insert(make_tuple(l1, l - 1, id));
			if (r1 > r) Insert.insert(make_tuple(r + 1, r1, id));
			cur ++;
		}	
		ms.insert({a[i].fi, a[i].se, i});
		for (auto x : Erase) ms.erase(x);
		for (auto x : Insert) ms.insert(x);
		Erase.clear(); Insert.clear();
	}
	for (auto x : cnt) 
		cd.pb(x);
	cd.pb({LINF, 0});
	for (int i = SZE(cd) - 2; i >= 0; i--) 
		cd[i].se += cd[i + 1].se;
	while (q--) {
		ll x; cin >> x;
		pll temp = mp(x, LINF);
		auto i = upper_bound(cd.begin(), cd.end(), temp) - cd.begin();
		cout << cd[i].se << " ";
	}
}