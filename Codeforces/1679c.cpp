#pragma GCC optimize ("O2")
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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, q, it1[600003], it2[600003], cnt1[100003], cnt2[100003];

bool in_it1[100003], in_it2[100003];

void update(int node, int l, int r, int pos, int val, int it[]) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val, it);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val, it);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int u, int v, int it[]) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(node * 2, l, (l + r) / 2, u, v, it) + query(node * 2 + 1, (l + r) / 2 + 1, r, u, v, it);
}

int main() {
	fast;
	//fre();
	cin >> n >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, y;
			cin >> x >> y;
			if (!in_it1[x]) {
				update(1, 1, n, x, 1, it1);
				in_it1[x] = 1;
			}
			else cnt1[x] ++;
			if (!in_it2[y]) {
				update(1, 1, n, y, 1, it2);
				in_it2[y] = 1;
			}
			else cnt2[y] ++;
		}
		if (type == 2) {
			int x, y;
			cin >> x >> y;
			if (cnt1[x] == 0) {
				update(1, 1, n, x, 0, it1);
				in_it1[x] = 0;
			}
			else cnt1[x] --;
			if (cnt2[y] == 0) {
				update(1, 1, n, y, 0, it2);
				in_it2[y] = 0;
			}
			else cnt2[y] --;
		}	
		if (type == 3) {
			int xa, ya, xb, yb;
			cin >> xa >> ya >> xb >> yb;
			if (query(1, 1, n, xa, xb, it1) == xb - xa + 1 || query(1, 1, n, ya, yb, it2) == yb - ya + 1) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
	}
}
