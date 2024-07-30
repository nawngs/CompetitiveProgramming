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
const int NMAX = 100;
const int N = 700000;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[NMAX + 3];

bitset < N + 2 > dp;

bitset < 2 * N + 2 > f;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int mx = 0, pos = 0;
	for (int i = 1; i <= n; i++) {
		dp = 0; dp[0] = 1;
		for (int j = 1; j <= n; j++) if (j != i) dp |= (dp << a[j]);
		if (mx < dp.count()) {
			mx = dp.count();
			pos = i;
		}
	}
	cout << a[pos] << " ";
	f[N] = 1;
	for (int j = 1; j <= n; j++) if (j != pos) {
		f |= (f << a[j]);
		f |= (f >> a[j]);
	}
	for (int j = N; j < 2 * N + 2; j++) if (!f[j]) {
		cout << j - N << '\n';
		return 0;
	}
}