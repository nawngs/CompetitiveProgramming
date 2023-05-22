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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int k, l;

bool check[nmax + 5];

void create() {
	check[0] = false;
	for (int i = 0; i <= nmax; i++) {
		if (i + 1 <= nmax) check[i + 1] = (check[i + 1] || !check[i]);
		if (i + k <= nmax) check[i + k] = (check[i + k] || !check[i]);
		if (i + l <= nmax) check[i + l] = (check[i + l] || !check[i]);
	}
}

void sol() {
	int x;
	cin >> x;
	if (check[x]) cout << "A";
	else cout << "B";
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> k >> l >> t;
	create();
	while (t --) sol();
}
