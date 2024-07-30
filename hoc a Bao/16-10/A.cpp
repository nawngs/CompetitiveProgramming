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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

string s;

int n, pre[NMAX + 3], timer = 1;

void create(int u, int sz) {
	sz --;
	int len = pre[sz];
	while (sz > 0) {
		while (sz < len) len = pre[len - 1];
		timer ++;
		cout << u << " " << timer << '\n';
		create(timer, len);
		sz -= len;
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> s; n = s.size(); s = ' ' + s;
	if (s[n] == '1' || s[1] == '0') {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] != s[n - i]) {
			cout << -1 << '\n';
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') pre[i] = i;
		else pre[i] = pre[i - 1];
	}
	create(1, n);
	
}