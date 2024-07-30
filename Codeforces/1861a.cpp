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

bool check(int x) {
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++) 
		if (x % i == 0) return false;
	return true;
}

vector < int > pos[(1 << 9)];

void sol() {
	string s; cin >> s;
	for (int i = 0; i < (1 << 9); i++) {
		int val = 0;
		if (__builtin_popcount(i) <= 1) continue;
		for (auto x : pos[i]) val = (val * 10 + s[x] - '0');
		if (check(val)) {
			cout << val << '\n';
			return ;
		}
	}
	cout << -1 << '\n';
	return ;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	for (int i = 0; i < (1 << 9); i++) 
		for (int j = 0; j < 9; j++) if (i >> j & 1) pos[i].pb(j);
	int t; cin >> t; while (t --) sol();
	
}