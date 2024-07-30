#include <bits/stdc++.h>

#define int ll
#define name "Inversion"
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
const int NMAX = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, q, cnt[NMAX + 3][26], f[NMAX + 3][26], g[NMAX + 3][26], total[NMAX + 3];

string s;

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s >> q;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) cnt[i][j] = cnt[i - 1][j], f[i][j] = f[i - 1][j];
		cnt[i][s[i] - 'a'] ++;
		for (int j = s[i] - 'a' - 1; j >= 0; j--) f[i][j] ++;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 26; j++) g[i][j] = g[i + 1][j];
		for (int j = s[i] - 'a' + 1; j < 26; j++) g[i][j] ++;
	}
	for (int i = 1; i <= n; i++) 
		total[i] = total[i - 1] + f[i][s[i] - 'a'] + g[i][s[i] - 'a'];
	while (q--) {
		int l, r; cin >> l >> r;
		ll res = total[r] - total[l - 1];
		for (int j = 0; j < 26; j++) {
			ll dem = cnt[r][j] - cnt[l - 1][j];
			res = res - dem * f[l - 1][j] - dem * g[r + 1][j];
		}
		cout << res / 2 << '\n';
	}
}