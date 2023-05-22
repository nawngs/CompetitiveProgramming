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

int n, m;

int main() {
	fast;
	cin >> n >> m;
	int vall = 0, posl = 0, valr = m + 1, posr = 0;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		if (l > vall) {
			vall = l;
			posl = i;
		}
		if (r < valr) {
			valr = r;
			posr = i;
		}
	}
	if (vall > valr) {
		cout << "YES" << '\n';
		cout << posr << " " << posl << '\n';
	}
	else cout << "NO" << '\n';
}
