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

ll n, k, dp[2003][2003], S[2003][2003];

string s;

int main() {
	fast;
	cin >> n >> k >> s;
	s = ' ' + s;
	dp[0][0] = 1;
	S[0][0] = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= k; j++) {
			for (int len = 0; len < i; len++) {
				ll pos = i - len - 1;
				ll total = (len + 1) * (n - i + 1);
				if (total <= j) 
					dp[i][j] = (dp[i][j] + dp[pos][j - total] * ('z' - s[i])) % MOD;
				else break;
			}
			dp[i][j] = (dp[i][j] + S[i - 1][j] * (s[i] - 'a')) % MOD;
			//cout << i << " " << j << " " << dp[i][j] << '\n';
			S[i][j] = (S[i - 1][j] + dp[i][j]) % MOD;
		}
	cout << S[n][k];
}
