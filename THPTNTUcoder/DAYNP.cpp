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

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = x * x;
	if (b % 2 == 1) x = x * a;
	return x;
}

ll n, k, dem;

ll find(ll pos) {
	if (pos == 1) return 1;
	ll tam = 0;
	for (int i = n; i >= 0; i--) {
		if (pos > mu(2, i)) {
			tam = i;
			break;
		}
	}
	return !find(pos - mu(2, tam));
}

void sol() {
	cin >> n >> k;
	cout << find(k);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
