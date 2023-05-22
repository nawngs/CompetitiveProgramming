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
const ll LINF = 2e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, num[10][13];

string s;

ll dp[20][55][38][20][20][2], mu[10][60];

void mul(ll &x, ll y) {
	if (LINF / x < y) {
		x = LINF;
		return ;
	}
	x *= y;
}

ll calc(ll x) {
	if (x < 10) return x;
	ll v = 1;
	while (x > 1) {
		v *= (x % 10);
		x /= 10;
	}
	return calc(v);
}

int main() {
	fast;
	//fre();
	cin >> s;
	n = s.size();
	s = ' ' + s;
	dp[0][0][0][0][0][0] = 1;
	for (int i = 1; i <= 9; i++) {
		int x = i;
		for (int j = 2; j <= i; j++) {
			while (x % j == 0) {
				num[j][i] ++;
				x /= j;
			}
		}
		mu[i][0] = 1;
		for (int j = 1; j <= 58; j++) {
			mu[i][j] = mu[i][j - 1];
			mul(mu[i][j], i);
		}
	}
	for (int i = 0; i < n; i++) {
	for (int pow2 = 0; pow2 < 55; pow2++) 
	for (int pow3 = 0; pow3 < 37; pow3++)
	for (int pow5 = 0; pow5 < 19; pow5++)
	for (int pow7 = 0; pow7 < 19; pow7++)
	for (int less = 0; less < 2; less++) {
		if (dp[i][pow2][pow3][pow5][pow7][less] == 0) continue;
		for (int dg = 1; dg <= 9; dg++)
			if ((less || dg <= s[i + 1] - '0')) {
				int newl = (less || dg < s[i + 1] - '0');
				dp[i + 1][pow2 + num[2][dg]][pow3 + num[3][dg]][pow5 + num[5][dg]][pow7 + num[7][dg]][newl] += dp[i][pow2][pow3][pow5][pow7][less];
			}	
		}
	}
	ll res = 0;
	for (int pow2 = 0; pow2 < 55; pow2++) 
	for (int pow3 = 0; pow3 < 37; pow3++)
	for (int pow5 = 0; pow5 < 19; pow5++)
	for (int pow7 = 0; pow7 < 19; pow7++) {
		ll val = 1;
		mul(val, mu[2][pow2]);
		mul(val, mu[3][pow3]);
		mul(val, mu[5][pow5]);
		mul(val, mu[7][pow7]);
		if (val == LINF) continue;
		res += (dp[n][pow2][pow3][pow5][pow7][0] + dp[n][pow2][pow3][pow5][pow7][1]) * calc(val);
	}	
	//##############################################################################
	n --;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int pow2 = 0; pow2 < 55; pow2++) 
		for (int pow3 = 0; pow3 < 37; pow3++)
		for (int pow5 = 0; pow5 < 19; pow5++)
		for (int pow7 = 0; pow7 < 19; pow7++)
		for (int has1 = 0; has1 < 2; has1++) {
			if (dp[i][pow2][pow3][pow5][pow7][has1] == 0) continue;
			for (int dg = 0; dg <= 9; dg++) {
				if (has1 && dg == 0) continue;
				int newhas1 = (has1 || dg != 0);
				dp[i + 1][pow2 + num[2][dg]][pow3 + num[3][dg]][pow5 + num[5][dg]][pow7 + num[7][dg]][newhas1] += dp[i][pow2][pow3][pow5][pow7][has1];	
			}
		}
	}
	for (int pow2 = 0; pow2 < 55; pow2++) 
	for (int pow3 = 0; pow3 < 37; pow3++)
	for (int pow5 = 0; pow5 < 19; pow5++)
	for (int pow7 = 0; pow7 < 19; pow7++) {
		ll val = 1;
		mul(val, mu[2][pow2]);
		mul(val, mu[3][pow3]);
		mul(val, mu[5][pow5]);
		mul(val, mu[7][pow7]);
		if (val == LINF) continue;
		res += dp[n][pow2][pow3][pow5][pow7][1] * calc(val);
	}	
	cout << res;
}
