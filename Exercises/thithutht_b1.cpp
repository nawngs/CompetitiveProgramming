#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

int xa, xb, ya, yb;

ld distance(int xa, int ya, int xb, int yb) {
	return sqrtl((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

void sol() {
	cin >>xa >> ya >> xb >> yb;
	ll res = distance(xa, ya, (xa + xb) / 2, 0) + distance(xb, yb, (xa + xb) / 2, 0);
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --) sol();
}
