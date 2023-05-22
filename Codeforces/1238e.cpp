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

int n, m, cnt[26][26];

ll dp[(1 << 20)];
W12
string s;

int main() {
	fast;
	//fre();
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (i > 1) cnt[s[i] - 'a'][s[i - 1] - 'a'] ++;
		if (i < n) cnt[s[i] - 'a'][s[i + 1] - 'a'] ++;
	}
	for (int msk = 1; msk < (1 << m); msk++) {
		dp[msk] = LINF;
		for (int i = 0; i < m; i++) {
			if (!(msk >> i & 1)) continue;
			ll tam = dp[msk ^ (1 << i)], v = __builtin_popcount(msk);
			for (int j = 0; j < 26; j++) {
				if (i == j) continue;
				if (msk >> j & 1) tam += cnt[i][j] * v;
				else tam -= cnt[i][j] * v;
			}
			dp[msk] = min(dp[msk], tam);
		}
	}
	cout << dp[(1 << m) - 1];
}
