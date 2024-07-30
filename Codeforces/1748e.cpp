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
const ll LG = 18;

ll n, m, a[N + 3], mx[N + 3][LG + 3];

vector < vector < ll > > dp, s;

int find(int l, int r) {
	int k = __lg(r - l + 1);
	int i = mx[l][k], j = mx[r - (1 << k) + 1][k];
	if (a[j] > a[i]) return j;
	return i;
}

int calc(int l, int r) {
	if (l > r) return -1;
	int p = find(l, r);
	int lp = calc(l, p - 1), rp = calc(p + 1, r);
	for (int i = 1; i <= m; i++) {
		if (lp != -1 && i == 1) dp[p][i] = 0;
		else dp[p][i] = ((lp != -1 ? s[lp][i - 1] : 1ll) * (rp != -1 ? s[rp][i] : 1ll)) % MOD;
		s[p][i] = (s[p][i - 1] + dp[p][i]) % MOD;
	}
	return p;
}

void sol() {
	cin >> n >> m;
	dp.resize(n + 2); s.resize(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx[i][0] = i;
		dp[i].resize(m + 2), s[i].resize(m + 2);
		for (int j = 0; j <= m; j++) dp[i][j] = s[i][j] = 0;
	}
	for (int j = 1; j <= LG; j++) 
	for (int i = 1; i + (1 << j) - 1 <= n; i++) {
		mx[i][j] = mx[i][j - 1];
		if (a[mx[i + (1 << (j - 1))][j - 1]] > a[mx[i][j - 1]]) mx[i][j] = mx[i + (1 << (j - 1))][j - 1];
	}
	calc(1, n);
	cout << s[find(1, n)][m] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}