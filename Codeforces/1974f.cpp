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

int a, b, n, m, ans[2];

set < pii > ms1, ms2;

void sol() {
	cin >> a >> b >> n >> m;
	ms1.clear(), ms2.clear();
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		ms1.insert({x, y}); ms2.insert({y, x});
	}
	ans[0] = ans[1] = 0;
	int u = 1, d = a, l = 1, r = b, turn = 0;
	for (int i = 1; i <= m; i++) {
		char ope; int x;
		cin >> ope >> x;
		int res = 0;
		if (ope == 'U') {
			int newu = u + x;
			while (ms1.size()) {
				pii v = *ms1.begin();
				if (v.fi >= newu) break;
				res ++;
				ms1.erase(v); ms2.erase({v.se, v.fi});
			}
			u = newu;
		}
		if (ope == 'D') {
			int newd = d - x;
			while (ms1.size()) {
				pii v = *ms1.rbegin();
				if (v.fi <= newd) break;
				res ++;
				ms1.erase(v); ms2.erase({v.se, v.fi});
			}
			d = newd;
		}
		if (ope == 'R') {
			int newr = r - x;
			while (ms2.size()) {
				pii v = *ms2.rbegin();
				if (v.fi <= newr) break;
				res ++;
				ms1.erase({v.se, v.fi}); ms2.erase(v);
			}
			r = newr;
		}
		if (ope == 'L') {
			int newl = l + x;
			while (ms2.size()) {
				pii v = *ms2.begin();
				if (v.fi >= newl) break;
				res ++;
				ms1.erase({v.se, v.fi}); ms2.erase(v);
			}
			l = newl;
		}
		ans[turn] += res;
		turn ^= 1;
	}
	cout << ans[0] << " " << ans[1] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}