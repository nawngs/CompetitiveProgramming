#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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

int n, m, k;

void sol() {
	cin >> n >> m >> k;
	int res = 0;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		res = res ^ (x - 1);
		cin >> x;
		res ^= (x - 1);
	}
	cout << (res == 0 ? "NO" : "YES") << '\n';
}

main() {
	fast;
	//fre();
	int t = 5;
	//cin >> t;
	while (t --) sol();
}
