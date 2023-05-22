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

const string NAME = "Split3";
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

ll n, a[100003], s[100003], dp[100003][5], cnt[100003][5];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		cnt[i][0] = 1;
	}
	cnt[0][0] = 1;
	if (s[n] % 3 != 0) {
		cout << 0 << '\n';
		return ;
	}
	ll tam = s[n] / 3;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= min(i, 3); j++) {
			if (s[i] == tam * j) dp[i][j] = cnt[i - 1][j - 1];
			cnt[i][j] = cnt[i - 1][j] + dp[i][j];
		}
	}
	cout << dp[n][3];
}

int main() {
	fast;
		fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
