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
const int NMAX = 5e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[NMAX + 3], b[NMAX + 3], dp[NMAX + 3][NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= n; j++) cin >> b[j];
	ll res = -LINF;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
		dp[i][j] = a[i] * b[j] + max(0ll, dp[i - 1][j - 1]);
		res = max(res, dp[i][j]);
	}
	cout << res;
	
}