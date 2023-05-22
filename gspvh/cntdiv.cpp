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

const string NAME = "cntdiv";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

unordered_map < int, ll > dp[19];

bool checkpr(int x) {
	for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
	return true;
}

void sol() {
	cin >> n;
	vector < int > prime;
	for (int i = 2; i <= 100; i++) {
		if (prime.size() == 16) break;
		if (checkpr(i)) prime.push_back(i);
	}
	dp[0][1] = 1;
	for (int i = 1; i <= 16; i++) {
		for (auto val : dp[i - 1]) {
			ll tam = 1;
			dp[i][val.fi] = (dp[i][val.fi] == 0 ? val.se : min(dp[i][val.fi], val.se));
			for (int k = 1; k <= 60; k++) {
				if (INF / tam < prime[i - 1]) break;
				tam *= prime[i - 1];
				if (INF / tam < val.se) continue;
				dp[i][val.fi * (k + 1)] = (dp[i][val.fi * (k + 1)] == 0 ? val.se * tam : min(dp[i][val.fi * (k + 1)], val.se * tam));
			}
		}
	}
	ll res = INF;
	for (int i = 1; i <= 16; i++) if (dp[i][n] != 0) res = min(res, dp[i][n]);
	cout << (res == INF ? -1 : res);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
