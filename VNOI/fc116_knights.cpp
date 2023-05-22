#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll q, n;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x);
	if (b % 2 == 1) x = (x * a);
	return x;
}

int main() {
	fastflow;
	cin >> q >> n;
	while (q --) {
		ll a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		ll tam = mu(2, n - 1);
		cout << (a <= tam && b > tam ? "yes\n" : "no\n");
	}
}
