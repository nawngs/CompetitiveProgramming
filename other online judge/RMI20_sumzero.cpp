#include <bits/stdc++.h>

#define name "sumzero"
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

ll n, s[400003];

int st[400003][19];

map < ll, int > f;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		s[i] = s[i - 1] + x;
	}
	st[n + 1][0] = st[n + 2][0] = n + 2;
	for (int i = n; i >= 1; i--) {
		st[i][0] = st[i + 1][0];
		f[s[i]] = i;
		if (f.find(s[i - 1]) != f.end()) 
			st[i][0] = min(st[i][0], f[s[i - 1]] + 1);
	}
	for (int j = 1; j <= 18; j++) {
		st[n + 1][j] = n + 2;
		st[n + 2][j] = n + 2;
		for (int i = n; i >= 1; i--) {
			st[i][j] = min(st[i + 1][j], st[st[i][j - 1]][j - 1]);
		}
	}
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		r++;
		int res = 0;
		for (int j = 18; j >= 0; j--) {
			if (st[l][j] <= r) {
				res += (1 << j);
				l = st[l][j];
			}
		}
		cout << res << '\n';
	}
}