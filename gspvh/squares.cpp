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

const string NAME = "squares";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e5;
const ll MOD = 1e5;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

vector < int > a;

bool check(int x) {
	bool used[12];
	memset(used, false, sizeof(used));
	while (x > 0) {
		if (used[x % 10]) return false;
		used[x % 10] = 1;
		x /= 10;
	}
	return true;
}

main() {
	fast;
	fre();
	ll k;
	cin >> k;
	for (int i = 1; i <= nmax; i++) 
		if (check(i * i)) a.push_back(i * i);
	k --;
	if (k < a.size()) cout << a[k];
	else cout << -1;
}
