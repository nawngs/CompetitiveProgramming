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
const ll MOD = 1e6 + 3;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[1005][1005], cnt[1005][1005];

string str, s[1005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	cin >> str;
	str = ' ' + str;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i][j] == str[i - 1 + j]) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	cnt[1][1] = a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0 || (i == 1 && j == 1)) {
				continue;
			}	
			if (a[i - 1][j] == 1) cnt[i][j] = (cnt[i][j] + cnt[i - 1][j]) % MOD;
			if (a[i][j - 1] == 1) cnt[i][j] = (cnt[i][j] + cnt[i][j - 1]) % MOD;
		}
	}
	cout << cnt[n][n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
