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
const int INF = 1e6 + 7;
const ll LINF = 1E18;
const int N = 500;
const ll MOD = 1e9 + 7;
const ll BASE = 1e5;

int n, a[N + 3], dp[N + 3][BASE + 3], s = 0;

void minimize(int &x, int y) {
	if (x > y) x = y;
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
		cin >> a[i];
		s += a[i];
	}
	
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= BASE; j++) dp[i][j] = INF;
	
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j <= BASE; j++) if (dp[i][j] != INF) {
		minimize(dp[i + 1][j], dp[i][j] + a[i + 1]);
		minimize(dp[i + 1][j + a[i + 1]], dp[i][j]);
		minimize(dp[i + 1][abs(j - a[i + 1])], dp[i][j]);
	}
	
	cout << (s + dp[n][0]) / 2;
}