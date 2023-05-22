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
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[100003];

void sol() {
	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> a[i];
	if (n == 2) {
		cout << (2 * (nmax - a[1]) + 1) % MOD << '\n';
		return ;
	}
	ll res = 0;
	a[0] = INF;
	a[n] = INF;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i + 1] && a[i] > a[i - 1]) {
			res = (res + 2 * (nmax - a[i]) + 1) % MOD;
		}
	}
	if (res == 0) 
		res = ((nmax - a[n - 1]) * 2 + 1) % MOD;
	cout << res << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
