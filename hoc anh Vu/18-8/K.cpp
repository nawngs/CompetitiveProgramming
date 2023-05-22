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
const ll MOD = 1e9 + 9;
const ll base = 2502;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, dp[53][53][5008];

void add(ll &x, ll y) {
	x = (x + y) % MOD;
}

int main() {
	fast;
	cin >> n;
	dp[0][0][base + 0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int s = 0; s <= 2 * base; s++) {
				if (dp[i][j][s] == 0) continue;
				if (j > 0) add(dp[i + 1][j - 1][s + (i + 1)], j * j * dp[i][j][s]);
				add(dp[i + 1][j][s], (2 * j + 1) * dp[i][j][s]);
				add(dp[i + 1][j + 1][s - (i + 1)], dp[i][j][s]);
			}
		}
	}
	ll res = 0;
	for (int s = base; s <= 2 * base; s++) { 
		res = (res + dp[n][0][s] * (s + 1 - base)) % MOD;
	}
	cout << res;
}
