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

const string NAME = "reverse";
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

ll n, e[100003], dp[100003][2];

string s[100003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> e[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = INF;
	dp[1][0] = 0;
	dp[1][1] = e[1];
	for (int i = 2; i <= n; i++) {
		string tam = s[i - 1];
		reverse(tam.begin(), tam.end());
		if (s[i] >= s[i - 1]) dp[i][0] = dp[i - 1][0];
		if (s[i] >= tam) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		string temp = s[i];
		reverse(temp.begin(), temp.end());
		if (temp >= s[i - 1]) dp[i][1] = dp[i - 1][0] + e[i];
		if (temp >= tam) dp[i][1] = min(dp[i][1], dp[i - 1][1] + e[i]);
	}
	ll res = min(dp[n][0], dp[n][1]);
	cout << (res == INF ? -1 : res);
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
