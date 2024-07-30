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
const int N = 200;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

string a, b;

int dp[N + 3][N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> a >> b;
	int n = a.size(), m = b.size();
	a = ' ' + a; b = ' ' + b;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
		dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a[i] == b[j])});
	int lck = dp[n][m], res = 1;
	while (lck * 2 < m || lck * 2 < n) lck += n, n *= 2, res++;
	cout << res;
}