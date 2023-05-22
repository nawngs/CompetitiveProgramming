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

const string NAME = "";
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

ll n, m;

void sol() {
	cin >> n >> m;
	if (n % 2 == 1) {
		cout << "IMPOSSIBLE" << '\n';
		return ;
	}
	ll tam = m - n;
	if (tam % 2 == 1 || tam < 0) {
		cout << "IMPOSSIBLE" << '\n';
		return ;
	}
	if (n / 2 - tam / 2 < 0) {
		cout << "IMPOSSIBLE" << '\n';
		return ;
	}
	cout << tam / 2 << " " << n / 2 - tam / 2 << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
