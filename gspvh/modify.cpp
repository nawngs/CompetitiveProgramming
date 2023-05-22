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

const string NAME = "modify";
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


int main() {
	fast;
	fre();
	int n;
	cin >> n;
	int diff = 0, sum = 0;;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x >= 10 && x < 90) diff = max(diff, 90 + (x % 10) - x);
		if (x < 10) diff = max(diff, 9 - x);
		if (x >= 90) diff = max(diff, 99 - x);
		sum += x;
	}
	cout << sum + diff;
}
