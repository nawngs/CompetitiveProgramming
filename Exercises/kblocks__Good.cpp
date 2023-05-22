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

int n, k, a[100003], dp[103][100003], st[100003][23];

int get(int l, int r) {
	int k = log2(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
	fast;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= n; j++) 
		for (int i = 1; i + (1 << j) - 1 <= n; i++) 
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	for (int i = 2; i <= k; i++)
		for (int j = 1; j <= n; j++) dp[i][j] = INF;
	for (int i = 1; i <= n; i++) dp[1][i] = get(1, i);
	for (int i = 2; i <= k; i++) 
		for (int j = i; j <= n; j++)
			for (int p = j - 1; p >= i - 1; p--) {
				dp[i][j] = min(dp[i][j], dp[i - 1][p] + get(p + 1, j));
			}
	cout << dp[k][n];
}
