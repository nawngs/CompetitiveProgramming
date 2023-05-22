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

string a, b;

ll mu[1000003];

pll dp[1000003][10][2][2];



pll f(int pos, int digit, bool isfi, bool less, bool isa) {
	//cout << pos << " " << digit << " " << isfi << " " << less << " " << dp[pos][digit][isfi][less].fi << '\n';
	if (pos == (isa ? a.size() - 1 : b.size() - 1)) return {(isfi ? digit : 0), 1};
	if (dp[pos][digit][isfi][less] != make_pair(-1ll, -1ll)) return dp[pos][digit][isfi][less];
	pll res = {0, 0};
	for (int i = 0; i < 10; i++) {
		if (less || i <= (isa ? a[pos + 1] -'0' : b[pos + 1] - '0')) {
			pll tam = f(pos + 1, i, (i != digit), (less || i < (isa ? a[pos + 1] - '0' : b[pos + 1] - '0')), isa);
			res.fi += tam.fi;
			res.se += tam.se;
			res.fi %= MOD;
			res.se %= MOD;
		}
	}
	if (isfi) res.fi += (((1ll * digit * mu[(isa ? a.size() - 1 : b.size() - 1) - pos]) % MOD) * res.se) % MOD;

	dp[pos][digit][isfi][less] = res;
	return res;
}

ll calc(string x) {
	for (int i = 0; i < x.size(); i++) 
		for (int digit = 0; digit <= 9; digit++)
			for (int isfi = 0; isfi < 2; isfi++) 
				for (int less = 0; less < 2; less++) dp[i][digit][isfi][less] = {-1, -1};
	return f(0, 0, 0, 0, (x == a)).fi;
	// for (int i = 0; i < x.size(); i++) 
	// 	for (int digit = 0; digit <= 9; digit++)
	// 		for (int isfi = 0; isfi < 2; isfi++) 
	// 			for (int less = 0; less < 2; less++) if (dp[i][digit][isfi][less] == make_pair(1ll * 45, 1ll * 10)) cout << i << " " << digit << " " << isfi << " " << less << '\n';
}

ll tinh(string x) {
	ll total = 0;
	for (int i = 1; i < x.size(); i++) if (x[i] != x[i - 1]) total = (total + 1ll * (x[i] - '0') * mu[x.size() - 1 - i]) % MOD;
	return total;
}

int main() {
	//fast;
	//fre();
	int t = 1;
	cin >> t;
	mu[0] = 1;
	for (int i = 1; i <= 1e6; i++) mu[i] = (mu[i - 1] * 10) % MOD;;
	while (t--) {
		cin >> a >> b;
		a = ' ' + a;
		b = ' ' + b;
		cout << (calc(b) - calc(a) + tinh(a) + MOD) % MOD << '\n';
	}
}
