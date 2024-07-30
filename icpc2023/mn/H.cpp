#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int A, B, C, D, res = INF;

bool check(int x) {
	if (x % A != 0) return false;
	if (x % B == 0) return false;
	if (D % x == 0) return false;
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> A >> B >> C >> D;
	for (int i = 1; i * i <= C; i++) if (C % i == 0) {
		if (check(i)) res = min(res, i);
		if (check(C / i)) res = min(res, C / i);
	}
	cout << (res >= C ? -1 : res);
}