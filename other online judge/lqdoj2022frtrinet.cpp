#include <bits/stdc++.h>

#define name "trinet"
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

ll n, a[2003][2003], b[2003][2003], f[2003][2003];

ll calc(int i, int j) {
	if (f[i][j] != -1) return f[i][j];
	pll pos = {-1, -1};
	int len = max(n - i, b[i][j] - 1);
	for (int y = j; y <= min(i + len, j + len); y++) {
		int x = i + len;
		if (pos == mp(-1ll, -1ll) || a[pos.fi][pos.se] < a[x][y]) pos = {x, y};
	}
	f[i][j] = a[i][j];
	if (pos != make_pair(-1ll, -1ll)) f[i][j] += calc(pos.fi, pos.se);
	return f[i][j];
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ll x; cin >> x;
			a[i][j] = x / 5000;
			b[i][j] = x % 5000;
		}
	}x
	memset(f, 255, sizeof(f));
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		ll total = 0;
		for (ll j = 1; j <= i; j++) {
			total += (calc(i, j) ^ j);
		}
		res = (res + (total ^ i));
	}
	cout << res;
}