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
const int N = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int m, d, dp[N + 3][N + 3][2][2][2];

string a, b;

void add(int &x, int y) {
	if ((x += y) >= MOD) x -= MOD;
}

int solve(int i, int j, bool oka, bool okb, bool okd) {
	if (i == a.size()) return (j == 0);
	if (dp[i][j][oka][okb][okd] != -1) return dp[i][j][oka][okb][okd];
	int &res = dp[i][j][oka][okb][okd]; res = 0;
	for (int v = 0; v <= 9; v++) {
		if (i & 1 && v != d) continue;
		if (!(i & 1) && v == d) continue;
		if (!oka && v < a[i] - '0') continue;
		if (!okb && v > b[i] - '0') continue;
		add(res, solve(i + 1, (j * 10 + v) % m, (oka | (v > a[i] - '0')), (okb | (v < b[i] - '0')), okd | v == d));
	} 
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> m >> d >> a >> b;
	reverse(a.begin(), a.end());
	while (a.size() < b.size()) a += '0';
	reverse(a.begin(), a.end());
	memset(dp, 255, sizeof(dp));
	cout << solve(0, 0, 0, 0, (d == 0 ? 1 : 0));
}