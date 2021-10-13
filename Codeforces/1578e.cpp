#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
//const ll MOD = 1;

ll h, t;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x);
	if (b % 2 == 1) x = (x * a);
	//cout << a << " " << b << " " << x << '\n';
	return x;
}

void sol() {
	cin >> h >> t;
	ll tam = mu(2, h) - 1;
	//cout << tam << '\n';
	ll i = 0;
	ll ans = 0;
	while (mu(2, i) < t && i < h) {
		ans ++;
		tam -= mu(2, i);
		i ++;
	}
	cout << ans + (tam / t) + (tam % t != 0) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t--) sol();
}
