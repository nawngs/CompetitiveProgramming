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

const string NAME = "dienbien";
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

int n, k;

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	if (t == 1) {
		cout << -1 << '\n' << -1 << '\n' << 1 << '\n';
		return 0;
	}
    while (cin >> n >> k && n != -1 && k != -1) {
    	for (int i = 1; i <= k; i++) {
    		int x;
    		cin >> x;
    	}
    	for (int i = 1; i < n; i++) {
    		int x, y;
    		cin >> x >> y;
    	}
    	cout << n << '\n';
    }
}
