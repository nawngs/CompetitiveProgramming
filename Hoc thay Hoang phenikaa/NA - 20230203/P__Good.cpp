#include <bits/stdc++.h>

#define name ""
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

ll n, val[400003];

pll f[400003];

pll a[100003], Q[100003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].fi >> a[i].se;
	int q; cin >> q;
	while (q--) {
		int res = 0;
		int x, y; cin >> x >> y;
		for (int l = x; l <= y; l++)
			for (int r = l; r <= y; r++) 
				for (int i = 1; i <= n; i++) {
					if (l <= a[i].fi && a[i].se <= r) {
						res ++;
						break;
					}
				}
		cout << res << '\n';
	}
}