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

int n, a[300003], nxt[300003][20], last[20], q;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= 19; i++) 
		nxt[n + 1][i] = last[i] = n + 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= 19; j++) {
			nxt[i][j] = n + 1;
			for (int k = 0; k < 20; k++) {
				if (!(a[i] >> k & 1)) continue;
 				nxt[i][j] = min(nxt[i][j], nxt[last[k]][j]);
			}

		}
		for (int j = 0; j < 20; j++) 
			if (a[i] >> j & 1) last[j] = i, nxt[i][j] = i;
	}
	while (q--) {
		int l, r; cin >> l >> r;
		bool th = false;
		for (int j = 0; j < 20; j++) {
			if (!(a[r] >> j & 1)) continue;
			th |= (nxt[l][j] <= r);
		}
		if (th) cout << "Shi" << '\n';
		else cout << "Fou" << '\n';
	}
}