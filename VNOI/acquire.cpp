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

using Line = pll;

vector < pll > a;

int n;

pll Rec[50003];

int top = 0;

Line lines[50003];

ll get (ll x, Line a) {
	return a.fi * x + a.se;
}

bool bad(Line a, Line b, Line c) {
	//return (double)(a.se - b.se) / (a.fi - b.fi) <= (double)(a.se - c.se) / (a.fi - c.fi);
	return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi) >= 0;
}

void Insert(Line newline) {
	int l = 1, r = top - 1, k = top, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (bad(lines[mid - 1], lines[mid], newline)) {
			k = mid; r = mid - 1;
		}
		else l = mid + 1;
	}
	top = k + 1; lines[k] = newline;
	//cout << newline.fi << " " << newline.se << " " << k << '\n';
}

ll query(ll x) {
	int l = 0, r = top - 1, mid; ll ans = get(x, lines[l]);
	while (l < r) {
		mid = (l + r) / 2;
		ll v1 = get(x, lines[mid]), v2 = get(x, lines[mid + 1]);
		if (v1 > v2) l = mid + 1;
		else r = mid - 1;
		ans = min(ans, min(v1, v2));
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
	a.resize(n);
	for (auto &x : a) cin >> x.fi >> x.se;
	sort(a.begin(), a.end());
	for (auto x : a) {
		while (n > 0 && Rec[n].se < x.se) n--;
		Rec[++ n] = x;
	}
	ll res = 0;
	Insert({Rec[1].se, 0});
	for (int i = 1; i <= n; i++) {
		res = query(Rec[i].fi);
		Insert({Rec[i + 1].se, res});
	}
	cout << res;
}