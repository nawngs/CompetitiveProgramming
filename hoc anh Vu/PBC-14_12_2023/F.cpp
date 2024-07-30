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
const ll BASE = 2309;

ll n, x, y, a[N + 3], MOD, s[2 * N + 3];

vector < ll > compress;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> x >> y;
	ll l1, r1, l2, r2;
	l1 = l2 = 1; r1 = r2 = x + y;
	MOD = x + y;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= (x + y);
		ll r = (a[i] + MOD) % MOD, l = (a[i] - x + 1 + MOD) % MOD;
		// cerr << l << " " << r << '\n';
		if (l == 0) l += MOD;
		if (r == 0) r += MOD;
		compress.pb(l); compress.pb(r);
	}
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	// for (auto x : compress) cerr << x << " ";
	for (int i = 1; i <= n; i++) {
		ll r = (a[i] + MOD) % MOD, l = (a[i] - x + 1 + MOD) % MOD;
		if (l == 0) l += MOD;
		if (r == 0) r += MOD;
		l = lower_bound(compress.begin(), compress.end(), l) - compress.begin();
		r = lower_bound(compress.begin(), compress.end(), r) - compress.begin();
		if (l <= r) s[l] ++, s[r + 1] --;
		else s[0] ++, s[r + 1] --, s[l] ++;
	}
	for (int i = 1; i < compress.size(); i++) s[i] += s[i - 1];
	for (int i = 0; i < compress.size(); i++) {
		if (s[i] == n) {
			cout << compress[i] << '\n';
			return 0;
		}
	}
	cout << -1;
}