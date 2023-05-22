#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[5003];

bool minimize(int &x, int y) {
	if (x > y) {
		x = y;
		return 1;
	}
	return 0;
}

int solve(int l, int r) {
	if (l > r) return 0;
	int val = INF, pos, res = r - l + 1;
	for (int i = l; i <= r; i++) {
		if (minimize(val, a[i])) pos = i;
	}
	for (int i = l; i <= r; i++)
		a[i] -= val;
	minimize(res, solve(l, pos - 1) + solve(pos + 1, r) + val);
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << solve(1, n);
}