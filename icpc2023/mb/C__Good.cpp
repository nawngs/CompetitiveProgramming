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

int n, m, res = 0, pre[12], f[12];

vector < int > a;

void back_track(int pos) {
	if (pos == n + 1) {
		for (int i = 1; i <= 8; i++) pre[i] = -INF;
		for (int i = 1; i <= n; i++) {
			if (i - pre[f[i]] < f[i]) return ;
			pre[f[i]] = i;
		}
		res ++;
		return ;
	}
	for (auto x : a) {
		f[pos] = x;
		back_track(pos + 1);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		a.pb(x);
	}
	back_track(1);
	cout << res;
}