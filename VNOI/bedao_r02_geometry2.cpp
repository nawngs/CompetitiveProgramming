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
const ld sin36 = 0.5877852523;
const ld sin72 = 0.9510565163;
const ld pi = 3.14159265359;

ld r, x;

void sol() {
	cin >> r >> x;
	ld d = r * 2;
	ld ab = sin36 * d;
	ld ac = sin72 * d;
	ld sc = r * r * pi;
	ld sn = (sqrt(25 + 10 * sqrt(5)) / 4) * ab * ab;
	ld sub = (sc - sn) / 5;
	ld ah = sin36 * ac;
	ld cah = (ac + x) * ah / 2;
	ld cek = (ab + ac) * ah / 2;
	cout << setprecision(9) << fixed << cek + cah + sub << '\n';
}

int main() {
	slow;
	int t;
	cin >> t;
	while (t --) sol();
}
