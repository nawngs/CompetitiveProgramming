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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int BLOCK_SIZE = 320;

int n, a[NMAX + 3], cnt[BLOCK_SIZE + 3][NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[i / BLOCK_SIZE][a[i]] ++;
	}
	int res = 0;
	int q; cin >> q;
	while (q--) {
		int t, l, r; cin >> t >> l >> r;
		l = (l + res - 1) % n + 1;
		r = (r + res - 1) % n + 1;
		if (t == 1) {
			int lblock = l / BLOCK_SIZE;
			int rblock = r / BLOCK_SIZE;
		}
	}
}