#include <bits/stdc++.h>

#define int ll
#define name "mixpotions"
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
const int NMAX = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 60;

ll n, k, a[NMAX + 3];

vector < pii > seg, newseg;

int get(const pii &x, int bit) {
	for (int j = x.fi; j <= x.se; j++) if (a[j] >> bit & 1) return j;
	return x.se + 1;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	k = n * (n - 1) / 2 - k + 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1); seg.pb({1, n});
	ll res = 0, fibit = -1;
	for (int i = LG; i >= 0; i--) {
		ll dem = 0;
		for (auto x : seg) {
			int pos = get(x, i);
			ll vl = pos - x.fi, vr = x.se + 1 - pos;
			dem += vl * vr;
			if (vl == 0 || vr == 0) continue;
		}
		if (dem < k) k -= dem;
		else fibit = i;
		for (auto x : seg) {
			int pos = get(x, i);
			ll vl = pos - x.fi, vr = x.se + 1 - pos;
			if (fibit != -1 && (vl == 0 || vr == 0)) continue;
			if (x.fi < pos) newseg.pb({x.fi, pos - 1});
			if (pos <= x.se) newseg.pb({pos, x.se});
		}
		seg = newseg; newseg.clear();
		if (fibit != -1) break;
	}
	if (fibit == -1) {
		cout << 0 << '\n';
		return 0;
	}
	res = (1ll << fibit);
 	for (int bit = fibit - 1; bit >= 0; bit--) {
		assert(SZE(seg) % 2 == 0);
		ll dem = 0;
		for (int i = 0; i < SZE(seg); i+=2) {
			pii &l = seg[i], &r = seg[i + 1];
			int posl = get(l, bit), posr = get(r, bit);
			if (posl > l.fi && posr <= r.se) 
				newseg.pb({l.fi, posl - 1}), newseg.pb({posr, r.se});
			if (posl <= l.se && posr > r.fi)
				newseg.pb({posl, l.se}), newseg.pb({r.fi, posr - 1});
		}
		for (int i = 0; i < SZE(newseg); i+=2) {
			pii &l = newseg[i], &r = newseg[i + 1];
			dem += (l.se - l.fi + 1) * (r.se - r.fi + 1);
		}
		if (dem >= k) res ^= (1ll << bit);
		else {
			k -= dem;
			vector < pii >().swap(newseg);
			for (int i = 0; i < SZE(seg); i+=2) {
				pii &l = seg[i], &r = seg[i + 1];
				int posl = get(l, bit), posr = get(r, bit);
				if (posl > l.fi && posr > r.fi) 
					newseg.pb({l.fi, posl - 1}), newseg.pb({r.fi, posr - 1});
				if (posl <= l.se && posr <= r.se)
					newseg.pb({posl, l.se}), newseg.pb({posr, r.se});
			}
		}
		seg = newseg; vector < pii >().swap(newseg);
	}
	cout << res;
}