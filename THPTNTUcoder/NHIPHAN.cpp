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

ll n, x, f[93][2];

string s;

void sol() {
	cin >> n >> s >> x;
	s = ' ' + s;
	f[1][0] = 1;
	f[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i][0] = f[i - 1][0] + f[i - 1][1];
		f[i][1] = f[i - 1][0];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) if (s[i] == '1') ans += f[n - i + 1][0];
	cout << ans + 1 << '\n';
	string res = "";
	for (int i = 1; i <= n; i++) {
		if (f[n - i + 1][0] < x) {
			x -= f[n - i + 1][0];
			res += '1';
		}
		else res += '0';
		
	}
	cout << res << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
