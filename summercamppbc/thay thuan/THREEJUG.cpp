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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int A, B, C, a, b, c, d, T;

bool check(int x, int y, int z, int a, int b, int e, int f) {
	if (x >= z && (y - z) % d == 0) {
		if (z > y) {
			y += (a / d) * d;
			y +=  (b / d) * d;
			if (y >= z) return true;
		}
		else {
			y -= (e - a) / d * d;
			y -= (f - b) / d * d;
			if (y <= z) return true;
		}
	}
	return false;
}

void sol() {
	cin >> A >> B >> C >> a >> b >> c >> d >> T;
	int res = INF;
	if (check(A, a, T, b, c, B, C)) res = min(res, abs(T - a) / d);
	if (check(B, b, T, a, c, A, C)) res = min(res, abs(T - b) / d);
	if (check(C, c, T, a, b, A, B)) res = min(res, abs(T - c) / d);
	cout << (res == INF ? -1 : res);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
 