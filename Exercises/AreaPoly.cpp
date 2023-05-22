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

const string NAME = "AreaPoly";
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

struct Point {
	ld x, y;
} p[100003];

int n;

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
	p[n + 1] = p[1];
	ld ans = 0;
	for (int i = 1; i <= n; i++) ans += (p[i].x * p[i + 1].y - p[i + 1].x * p[i].y);
	cout << fixed << setprecision(1) << ans / 2;
}
