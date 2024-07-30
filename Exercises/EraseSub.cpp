#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "EraseSub";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const int INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dp[502][502];

string s;

void sol() {
	cin >> n >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dp[i][j] = INF;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			if (k == 1) dp[i][i] = 1;
			else {
				int j = i + k - 1;
				for (int p = i; p < j; p++) dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j] - (s[p] == s[j]));				
			}
		}
	}
	cout << dp[1][n] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
