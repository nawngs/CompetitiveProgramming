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

const string NAME = "Suitable";
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

ll n, m, next_invalid[3003][3003];

string s[3003];

ll calc(ll x) {
	return ((x + 1) * x) / 2;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	for (int i = 1; i <= n; ++i) {
		next_invalid[i][m + 1] = m + 1;
		for (int j = m; j >= 1; --j) next_invalid[i][j] = (s[i][j] == '#' ? j : next_invalid[i][j + 1]);
	}
	ll ans = 0;
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= m; ++j) {
			ll len = m;
			for (ll k = i; k <= n; ++k) {
				if (s[k][j] == '#') break;
				len = min(len, next_invalid[k][j] - 1);
				ans += (k - i + 1) * (calc(len - j + 1));
			}
		}
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
