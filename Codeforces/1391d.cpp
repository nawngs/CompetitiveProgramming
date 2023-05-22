#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[1000003][5], dp[1000003][(1 << 3)];

int calc(int row, int mask) {
	int res = 0;
	for (int i = 0; i < m; i++) {
		int tmp = (mask >> i) & 1;
		res += (a[row][i] != tmp);
	}
	return res;
}

bool check(int mask1, int mask2) {
	for (int i = 1; i < m; i++) {
		if ((((mask1 >> (i - 1)) & 1) + ((mask1 >> i) & 1) + ((mask2 >> (i - 1)) & 1) + ((mask2 >> i) & 1)) % 2 == 0) return false;
	}
	return true;
}

int main() {
	fast;
	cin >> n >> m;
	if (n * m < 2) {
		cout << 0 << '\n';
		return 0;
	}
	if (min(n, m) > 3) {
		cout << -1 << '\n';
		return  0;
	}
	int b[n + 3][m + 3];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			char x;
			cin >> x;
			b[i][j] = (x - '0');
		}
	if (n <= 3) {
		for (int j = 1; j <= m; j++) 
			for (int i = 0; i < n; i++) a[j][i] = b[i + 1][j];
		swap(n, m);
	}
	else {
		for (int i = 1; i <= n; i++) 
			for (int j = 0; j < m; j++) a[i][j] = b[i][j + 1];
	}
	for (int i = 0; i < (1 << m); i++) dp[1][i] = calc(1, i);
	int res = INF;
	for (int i = 2; i <= n; i++) {
		for (int mask = 0; mask < (1 << m); mask++) {
			int tmp = calc(i, mask);
			dp[i][mask] = INF;
			for (int pre = 0; pre < (1 << m); pre++) 
				if (check(pre, mask)) dp[i][mask] = min(dp[i][mask], dp[i - 1][pre] + tmp);
			cerr << i << " " << mask << " " << dp[i][mask] << '\n';
			if (i == n) res = min(res, dp[i][mask]);	
		}
	}
	cout << res;
}
