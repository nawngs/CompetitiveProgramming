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

int n;

char a[N + 3], res[N + 3];

string s;

vector < int > u, l, r, d;

bool check[2];

void divide(vector < int > &x, int d) {
	while (!x.empty()) {
		int p = x.back(); x.pop_back();
		res[p] = (d & 1 ? 'R' : 'H');
		check[d] = 1;
		d ^= 1;
	}
}

void sol() {
	cin >> n;
	u.clear(), d.clear(), l.clear(), r.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 'N') u.pb(i);
		if (a[i] == 'S') d.pb(i);
		if (a[i] == 'E') r.pb(i);
		if (a[i] == 'W') l.pb(i);
	}
	if (((SZE(u) + SZE(d)) & 1) || ((SZE(l) + SZE(r)) & 1)) {
		cout << "NO" << '\n';
		return ;
	}
	check[1] = check[0] = false;
	divide(u, 0), divide(d, 0), divide(l, 1); divide(r, 1);
	if (!check[1] || !check[0]) {
		cout << "NO" << '\n';
		return; 
	}
	for (int i = 1; i <= n; i++) cout << res[i];
	cout << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}