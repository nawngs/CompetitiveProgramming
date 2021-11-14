#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, m, x, y, z;


int main() {
	slow;
	cin >> n >> m;
	cin >> x >> y;
	cout << (x - 1) * m + (x % 2 == 1 ? y : m - y + 1) << '\n';
	cin >> z;
	int resx = z / m;
	if (z % m != 0) resx ++;
	int resy;
	if (resx % 2 == 1) resy = z - m * (resx - 1);
	else resy = m - (z - m * (resx - 1)) + 1;
	cout << resx << " " << resy << '\n';

}
