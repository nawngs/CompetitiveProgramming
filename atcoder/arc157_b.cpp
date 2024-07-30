//[FINISHED]
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

int n, k;

string s, a;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> s; s = ' ' + s;
	int cntx = 0, cnty = 0;
	for (int i = 1; i <= n; i++) 
		if (s[i] == 'X') cntx ++;
		else cnty ++;
	if (cntx == n) {
		cout << max(0, k - 1) << '\n';
		return 0;
	}
	if (cnty == n) {
		cout << max(0, n - k - 1) << '\n';
		return 0;
	}
	if (k <= cntx) {
		vector < pii > vec;
		int l = 1, r = 0;
		while (l <= n && s[l] == 'Y') l ++;
		while (l <= n) {
			r = l - 1;
			while (s[r + 1] == 'X') r ++;
			vec.pb({r - l + 1, l});
			l = r + 1;
			while (l <= n && s[l] == 'Y') l ++;
		}
		sort(vec.begin(), vec.end(), [&](pii &x, pii &y) {
			if (y.se == 1) return true;
			if (y.fi + y.se - 1 == n) return true;
			if (x.se == 1) return false;
			if (x.fi + x.se - 1 == n) return false;
			return x.fi < y.fi;
		});
		for (auto x : vec) {
			while (k && x.fi) {
				s[x.se] = 'Y';
				x.se ++;
				x.fi --; k --;
			}
		}
		int ans = 0;
		for (int i = 2; i <= n; i++) if (s[i] == s[i - 1] && s[i] == 'Y') ans ++;
		cout << ans << '\n';
	}
	else {
		a = s;
		for (int i = 1; i <= n; i++) 
			a[i] = 'Y';
		k -= cntx;
		int l = 1, r = n;
		while (k && s[l] == 'Y') {
			k --;
			a[l] = 'X';
			l ++;
		}
		while (k && s[r] == 'Y') {
			k --;
			a[r] = 'X';
			r --;
		}
		l ++;
		while (l <= n && s[l] == 'X') l ++;
		vector < pii > vec;
		while (l <= n) {
			r = l - 1;
			while (s[r + 1] == 'Y') r ++;
			if (r != n) vec.pb({r - l + 1, l});
			l = r + 1;
			while (l <= n && s[l] == 'X') l ++;
		}
		sort(vec.begin(), vec.end(), greater < pii >());
		for (auto x : vec) {
			while (k && x.fi) {
				a[x.se] = 'X';
				x.se ++;
				x.fi --; k --;
			}
		}
		int ans = 0;
		for (int i = 2; i <= n; i++) if (a[i] == a[i - 1] && a[i] == 'Y') ans ++;
		cout << ans << '\n';
	}
}