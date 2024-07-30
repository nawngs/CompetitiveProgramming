#include <bits/stdc++.h>

#define name "divsubset"
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
const int NMAX = 1e3;
const int DMAX = 7e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k, a[NMAX + 3];

pll trace[NMAX + 3][DMAX + 3];

pll dp[NMAX + 3][DMAX + 3];

vector < ll > d;

unordered_map < ll, int > f;

bool minimize(pll &x, const pll &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}
int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n >> k;
	for (ll i = 1; i * i <= k; i++) if (k % i == 0) {
		d.pb(i);
		if (i != k / i) d.pb(k / i);
	}
	sort(d.begin(), d.end());
	for (int i = 0; i < SZE(d); i++) f[d[i]] = i;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (k == 1) {
		cout << 1 << '\n';
		int pos = 1;
		for (int i = 1; i <= n; i++) if (a[i] < a[pos]) pos = i;
		cout << pos << '\n';
		return 0;
	}
	for (int i = 0; i <= n; i++)
	for (int j = 0; j < SZE(d); j++) 
		dp[i][j] = {LINF, LINF};
	trace[0][SZE(d) - 1] = {0, 0}; dp[0][SZE(d) - 1] = {0, 0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < SZE(d); j++) if (dp[i][j] != mp(LINF, LINF)) {
			if (minimize(dp[i + 1][j], dp[i][j])) trace[i + 1][j] = trace[i][j];
			int it = f[d[j] / __gcd(d[j], a[i + 1])];
			if (minimize(dp[i + 1][it], {dp[i][j].fi + 1, dp[i][j].se + a[i + 1]})) 
				trace[i + 1][it] = {i + 1, j};
		}
	}
	if (dp[n][0].fi == LINF) {
		cout << -1 << '\n';
		return 0;
	}
	cout << dp[n][0].fi << '\n';
	int pos = n, j = 0;
	while (1) {
		pii temp = trace[pos][j];
		if (temp.fi <= 0) break;
		cout << temp.fi << ' ';
		pos = temp.fi - 1; j = temp.se;
	}
}