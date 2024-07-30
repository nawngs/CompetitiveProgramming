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
const int NMAX = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const ll BIT = (1 << 7) - 1;

ll n, k, a[NMAX + 3], dp[2][BIT + 1][BIT + 1];

void sub(ll &x, ll y) {
	x -= y;
	if (x < 0) x += MOD;
	if (x >= MOD) x -= MOD;
}

void add(ll &x, ll y) {
	x += y;
	if (x < 0) x += MOD;
	if (x >= MOD) x -= MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int t = 0; t < k; t++) {
		int x; cin >> x;
		while (x--) {
			int i; cin >> i;
			a[i] |= (1 << t);
		}
	}
	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		ll val = cur + (i == 1);
		ll A = a[i] & BIT, B = (a[i] >> 7) & BIT;
		for (int msk = 0; msk <= BIT; msk++) {
			sub(val, dp[1][A][msk]);
			if (msk & B) sub(val, dp[0][A][msk]);
		}
		add(cur, val);
		for (int msk = 0; msk <= BIT; msk++) {
			if (msk & A) add(dp[1][msk][B], val);
			else add(dp[0][msk][B], val);
		}
		if (i == n) cout << val << '\n';
	}
}