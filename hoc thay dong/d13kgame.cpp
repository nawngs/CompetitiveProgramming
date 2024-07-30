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
const int N = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 1000;

int n, k, dp[N + 3][103], f[BASE + 3];

int solve(int i, int j) {
	if (i == 0 || (i == 1 && j == 1)) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	for (int t = 1; t <= min(i, k); t++) if (t != j) {
		if (!solve(i - t, t)) return dp[i][j] = 1;
	}
	return dp[i][j] = 0;
}

bool check(int l, int r) {
	for (int i = 1; i <= r - l + 1; i++) if (f[l + i - 1] != solve(r + i, 0)) return false;
	return true;
}

vector < int > vec;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	memset(dp, 255, sizeof(dp));
	cin >> n >> k;
	// cout << solve(n, 0) << '\n';
	if (k % 2 == 0) {
		cout << (n % (k + 1) != 0) << '\n';
		return 0;
	}
	if (k == 1) {
		cout << 1 << '\n';
		return 0;
	}
	for (int i = 0; i <= BASE; i++) f[i] = solve(i, 0);
	for (int i = 0; i <= BASE; i++) if (f[i] == 0) vec.pb(i);
	reverse(vec.begin(), vec.end());
	int posl = -1, posr = -1;
	for (auto l : vec) {
		for (auto x : vec) if (x > l) {
			int r = x - 1;
			if (check(l, r)) {
				if (r - l + 1 > posr - posl + 1) posr = r, posl = l;
				break;
			}
		}
	}
	if (n < posl) {
		cout << f[n] << '\n';
		return 0;
	}
	else {
		n -= posl;
		n %= (posr - posl + 1);
		cout << f[posl + n] << '\n';
		return 0;
	}
	// cout << 123 << '\n';
	// for (int i = 3; i <= 99; i+=2) {
		// cout << i << " ";
		// k = i;
		// memset(dp, 255, sizeof(dp));
		// for (int j = 1; j <= BASE; j++) f[i] = solve(i, 0);
		// for (int j = BASE - 1; j > 0; j-=2) if (check(j)) {
			// cout << j << '\n';
			// break;
		// }
	// }
	assert(0);
}
