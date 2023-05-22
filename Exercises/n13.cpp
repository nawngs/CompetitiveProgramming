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

const string NAME = "n13";
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

ll l, r, f[20][12][3];

vector < int >  digit;

ll dp(int pos, int pre, int less) {
	//cout << pos << " " << pre << " " << less << " " << f[pos][pre][less] << '\n';
	if (pos == digit.size() + 1) return 1;
	if (f[pos][pre][less] != -1) return f[pos][pre][less];
	f[pos][pre][less] = 0;
	for (int i = 0; i <= 9; i++) {
		if ((less || i <= digit[pos - 1]) && (pre != 1 || i != 3)) f[pos][pre][less] += dp(pos + 1, i, (less || i < digit[pos - 1]));
	}
	return f[pos][pre][less];
}

ll calc(ll x) {
	if (x == -1) return 0;
	digit.clear();
	while (x > 0) {
		digit.push_back(x % 10);
		x /= 10;
	}
	memset(f, 255, sizeof(f));
	reverse(digit.begin(), digit.end());
	return dp(1, 0, 0);
}

void sol(ll l, ll r) {
	cout << calc(r) - calc(l - 1) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (cin >> l >> r) sol(l, r);
}
