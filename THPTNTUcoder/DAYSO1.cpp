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

int a[53];

void create() {
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i <= 40; i++) {
		a[i] = 2 * a[i - 1] - a[i - 2] + 1;
		a[i] = (a[i] + 10) % 10;
		//cout << i << " " << a[i] << '\n';
	}
	//for (int i = 20; i < 40; i++) if (a[i] != a[i % 20]) cout << i << '\n';
}

void sol() {
	ll x;
	cin >> x;
	ll tam = a[(x + 1) % 20] - a[x % 20];
	cout << (tam * tam) % 10 << '\n';
}

int main() {
	fast;
	//fre();
	create();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
