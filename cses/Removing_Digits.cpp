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
const ll INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dp[1000011];

bool check(int digit, int val) {
	while (val > 0) {
		if (digit == val % 10) return true;
		val /= 10;
	}
	return false;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) dp[i] = INF;
	dp[0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			if (check(j, i + j)) dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	cout << dp[n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
