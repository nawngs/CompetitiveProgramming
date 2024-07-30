#include <bits/stdc++.h>

#define name "check"
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

int n, x, y;

unordered_map <int, vector < pair < int, char > > > row, col, hieu, tong;

bool check(int bs, char c, vector < pair < int, char > > &x) {
	sort(x.begin(), x.end());
	auto it = lower_bound(x.begin(), x.end(), mp(bs, 'A'));
	if (it != x.end() && it->se != c) return true;
	if (it != x.begin()) {
		it --;
		if (it->se != c) return true;
	}
	return false;
}

void sol() {
	cin >> x >> y;
	row.clear(); col.clear(); hieu.clear(); tong.clear();
	for (int a, b, i = 1; i <= n; i++) {
		char c; cin >> c >> a >> b;
		row[a].pb({b, c}); col[b].pb({a, c});
		hieu[a - b].pb({a, c}); tong[a + b].pb({a, c});
	}
	if (check(y, 'B', row[x]) || check(x, 'B', col[y]) || check(x, 'R', hieu[x - y]) || check(x, 'R', tong[x + y])) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	while (cin >> n && n != -1) sol();
}