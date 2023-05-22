#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, it[30][3000005];

string s;

void update(int node, int l, int r, int pos, int val, int lev) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[lev][node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val, lev);
	update(node * 2 + 1, mid + 1, r, pos, val, lev);
	it[lev][node] = it[lev][node * 2] + it[lev][node * 2 + 1];
}

int query(int node, int l, int r, int u, int v, int lev) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[lev][node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v, lev) + query(node * 2 + 1, mid + 1, r, u, v, lev);
}

void sol() {
	cin >> n >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) update(1, 1, n, i, 1, s[i] - 'a');
	int q;
	cin >> q;
	while (q --) {
		int x;
		cin >> x;
		if (x == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			update(1, 1, n, pos, 0, s[pos] - 'a');
			update(1, 1, n, pos, 1, c - 'a');
			s[pos] = c;
		}
		else {
			int l, r;
			cin >> l >> r;
			int cnt = 0;
			for (int i = 'a' - 'a'; i <= 'z' - 'a'; i ++) cnt += (query(1, 1, n, l, r, i) != 0);
			cout << cnt << '\n';
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
