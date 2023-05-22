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

int n, f[1 << 20], g[1 << 20];

pii s[(1 << 20)];

vector < int > aa, bb, a, b;

int main() {
	//fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	aa.resize(n); bb.resize(n);
	for (auto &x : aa) cin >> x;
	for (auto &y : bb) cin >> y;
	ll res1 = 0, res2 = 0;
	for (int i = 0; i < n; i++) {
		if (!aa[i] || !bb[i]) {
			res1 += aa[i];
			res2 += bb[i];
		}
		else {
			a.push_back(aa[i]);
			b.push_back(bb[i]);
		}
	}
	n = a.size();
	s[0].fi = 0;
	f[0] = 0;
	g[0] = INF;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) 
			if ((i >> j) & 1) {
				s[i].fi = s[i ^ (1 << j)].fi + a[j];
				f[i] = f[i ^ (1 << j)] + b[j];
				g[i] = min(g[i ^ (1 << j)], b[j]);
				break;
			}
	}
	g[0] = 0;
	for (int i = 0; i < (1 << n); i++) {
		s[i].se = f[(1 << n) - 1 - i] - g[(1 << n) - 1 - i];
	}
	sort(s, s + (1 << n));
	int res = INF, v1, v2, maxb = -INF;
	for (int i = (1 << n) - 1; i >= 0; i--) {
		maxb = max(maxb, s[i].se + 1);
		if (res > s[i].fi + 1 + maxb) {
			res = s[i].fi + 1 + maxb;
			v1 = s[i].fi + 1; v2 = maxb;
		}
	}
	cout << res1 + v1 << '\n' << res2 + v2 << '\n';
}