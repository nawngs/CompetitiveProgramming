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
const int N = 1e6;
const int LG = 23;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[N + 3], res;

pii pos[(1 << LG)];

bool check() {
	for (int i = 1; i <= n; i++) if (pos[res ^ (res & a[i])].se > i) return true;
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].se = max(pos[a[i]].se, i);
		if (pos[a[i]].se > pos[a[i]].fi) swap(pos[a[i]].se, pos[a[i]].fi);
	}
	for (int j = 0; j < LG; j++)
	for (int i = (1 << LG) - 1; i >= 0; i--) if (i >> j & 1) {
		int ni = i ^ (1 << j);
		if (pos[i].se > pos[ni].fi) pos[ni] = pos[i];
		else if (pos[i].fi > pos[ni].se) pos[ni].se = pos[i].fi;
		if (pos[ni].se > pos[ni].fi) swap(pos[ni].se, pos[ni].fi);
	}
	for (int i = LG - 1; i >= 0; i--) {
		res ^= (1 << i);
		if (!check()) res ^= (1 << i);
	}
	cout << res;
}