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

string s;

int n, f1[3003][3003], g1[3003][3003], f2[3003][3003], g2[3003][3003], res[3003];


int main() {
	//fast;
	cin >> s;
	n = s.size();
	s = ' ' + s;
	memset(res, 0, sizeof(res));
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = (i + len) - 1;
			if (i == j) f1[i][j] = g1[i][j] = 1;
			else {
				if (s[i] == s[j]) f1[i][j] = (1 + g1[i + 1][j - 1]) % MOD;
				g1[i][j] = ((f1[i][j] + g1[i + 1][j]) % MOD + (g1[i][j - 1] - g1[i + 1][j - 1] + MOD) % MOD) % MOD;
			}

		}
	}
	for (int len = n; len >= 1; len--) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = (i + len) - 1;
			if (s[i] == s[j]) f2[i][j] = (1 + g2[i - 1][j + 1]) % MOD;
			g2[i][j] = ((f2[i][j] + g2[i][j + 1]) % MOD + (g2[i - 1][j] - g2[i - 1][j + 1] + MOD) % MOD) % MOD;
			ll tam = (1ll * f2[i][j] * 1ll * f1[i][j]) % MOD;
			res[i] += tam;
			if (j != i) res[j] += tam;
			res[i] %= MOD;
			res[j] %= MOD;
		}
	}
	ll tam = res[1];
	for (int i = 2; i <= n; i++) tam ^= (1ll * res[i] * 1ll * i) % MOD;
	cout << tam;
}

