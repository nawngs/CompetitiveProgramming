#pragma GCC optimize ("O3")
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

const string NAME = "DivideGroupN";
const ll INF = 1e18;
const int nmax = 250500;
const ll MOD = 1000000007;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dp[505][nmax + 5];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

void sol() {
	cin >> n;
	if (((n + 1) / 2) % 2 == 1) {
		cout << 0 << '\n';
		return ;
	}
	dp[0][0] = 1;
	int tam = n * (n + 1) / 2;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= tam; j++) {
			dp[i + 1][j + i + 1] = (dp[i + 1][j + i + 1] + dp[i][j]) % MOD;
			dp[i + 1][abs(j - i - 1)] = (dp[i + 1][abs(j - i - 1)] + dp[i][j]) % MOD;
		}
	}
	cout << (1ll * dp[n][0] / 2) % MOD << '\n';
}	

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
	