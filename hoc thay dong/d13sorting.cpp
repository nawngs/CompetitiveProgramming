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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, b[N + 3];

pii a[N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) b[a[i].se] = i;
	int res = 0, r = 0, cur = 0;
	for (int i = 1; i <= n; i++) {
		r ++; cur = max(cur, b[i]);
		if (cur == r) res ++;
	}
	cout << res;
}