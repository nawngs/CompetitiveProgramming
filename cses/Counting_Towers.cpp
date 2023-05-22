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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, dp[1000003][2];

void create() {
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][0]) % MOD;
	}
}	

void sol() {
	cin >> n;
	cout << (dp[n][1] + dp[n][0]) % MOD << '\n';
}

int main() {
	//fast;
	//fre();
	create();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
