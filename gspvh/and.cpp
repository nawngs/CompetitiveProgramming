//[UNFINISHED]
#include <bits/stdc++.h>

#define name "and"
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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, a[NMAX + 3], nxt[32], msk[NMAX + 3][32];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j <= 30; j++) msk[i][j] = ((a[i] >> j & 1) ? i : n + 1);
	}
	for (int i = 0; i <= 30; i++) nxt[i] = n + 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= 30; j++) if (a[i] >> j & 1) {
			if (nxt[j] != n + 1) 
				for (int k = 0; k <= 30; k++) msk[i][k] = min(msk[i][k], msk[nxt[j]][k]);
			nxt[j] = i;
		} 
	}
	while(q--) {
		int l, r; cin >> l >> r;
		bool ok = false;
		for (int j = 0; j <= 30; j++) if (msk[l][j] <= r && (a[r] >> j & 1)) {
			ok = true;
			break;
		}
		cout << (ok ? "Yes" : "No") << '\n';
	}
}