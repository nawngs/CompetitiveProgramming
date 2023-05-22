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
const ll ESP = 1e-9;
const ll INF = 20000;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

short n, nxt[10003][13], k, a[13], dp[(1 << 13)];

bool IsPalin[10003][10003];

string s;

int main() {
	fast;
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (short len = 1; len <= n; ++len) {
		for (short i = 1; i <= n - len + 1; ++i) {
			if (len == 1) IsPalin[i][i] = 1;
			if (len == 2) IsPalin[i][i + 1] = (s[i] == s[i + 1]);
			if (len > 2) IsPalin[i][i + len - 1] = (IsPalin[i + 1][i + len - 2] && (s[i] == s[i + len - 1]));
		}
	}
	int T;
	cin >> T;
	while (T--) {
		cin >> k;
		for (short i = 0; i < k; ++i) cin >> a[i];
		for (short i = 1; i <= n; ++i)
			for (short j = 0; j < k; ++j) nxt[i][j] = 0;
		for (short i = 0; i < k; ++i) {
			for (short j = n - a[i] + 1; j >= 1; j--) {
				if (IsPalin[j][j + a[i] - 1]) nxt[j][i] = j;
				else nxt[j][i] = nxt[j + 1][i];
			}
		}
		dp[0] = 0;
		for (short bit = 1; bit < (1 << k); ++bit) {
			dp[bit] = INF;
			for (short i = 0; i < k; ++i) {
				if (bit & (1 << i)) {
					if (dp[bit ^ (1 << i)] != INF && nxt[dp[bit ^ (1 << i)] + 1][i] != 0) 
						dp[bit] = min((int)dp[bit], nxt[dp[bit ^ (1 << i)] + 1][i] + a[i] - 1);
				}
			}
		}
		cout << (dp[(1 << k) - 1] == INF ? "NO" : "YES") << '\n';
	}
}
