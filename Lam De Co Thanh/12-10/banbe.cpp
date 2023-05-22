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

const string NAME = "banbe";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[500003];

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	int res1, res2;
	res1 = a[1];
	res2 = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] != 0) 
			res1 ++;
		if (a[i] == i - 1)
			res2 ++;
		res1 = max(res1, a[i]);
		res2 = min(res2, a[i]);
	}
	cout << res1 << " " << res2;
}
