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

const string NAME = "KDX";
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

ll a, b, f[20][12][2][12][2][2][2];

vector < int > digit;

ll dp(ll pos, ll pre2, ll pre2_mean, ll pre1, ll pre1_mean, ll less, ll has1) {
	if (pos == digit.size()) return 1;
	if (f[pos][pre2][pre2_mean][pre1][pre1_mean][less][has1] != -1) return f[pos][pre2][pre2_mean][pre1][pre1_mean][less][has1];
	f[pos][pre2][pre2_mean][pre1][pre1_mean][less][has1] = 0;
	for (int i = 0; i <= 9; i++) {
		if ((less || i <= digit[pos]) && (!pre1_mean || i != pre1) && (!pre2_mean || i != pre2)) {
			int newhas1 = (has1 || i > 0);
			f[pos][pre2][pre2_mean][pre1][pre1_mean][less][has1] += dp(pos + 1, pre1, pre1_mean, i, newhas1, (less || i < digit[pos]), newhas1);
		}
	}
	return f[pos][pre2][pre2_mean][pre1][pre1_mean][less][has1];
}	


ll calc(ll x) {
	digit.clear();
	while (x > 0) {
		digit.push_back(x % 10);
		x /= 10;
	}
	reverse(digit.begin(), digit.end());
	memset(f, 255, sizeof(f));
	return dp(0, 0, 0, 0, 0, 0, 0);
}

void sol() {
	cin >> a >> b;
	cout << calc(b) - calc(a - 1);	
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}

