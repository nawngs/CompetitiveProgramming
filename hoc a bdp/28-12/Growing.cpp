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
const ll BLOCK_SIZE = 315;

int n, d;

ll s[BLOCK_SIZE + 3][100003];

ll res[100003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> d;
	while (d --) {
		int l, r, p, k; cin >> l >> r >> p >> k;
		if (p >= BLOCK_SIZE) {
			while (l <= r) {
				res[l] += 1ll * k;
				l += p;
			}
		}
		else {
			s[p][l] += k;
			if (p + r <= n) s[p][r + p] -= k;
		}
	}
	for (int i = 1; i < BLOCK_SIZE; i++) {
		for (int j = 1; j <= n; j++) {
			if (j > i) s[i][j] += s[i][j - i];
			res[j] += s[i][j];
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}