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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct line {
	ll a, b;
	ll get(const ll &x) {
		return a * x + b;
	}
};


ll n, a[100003], b[100003];

line it[400003];

void update(int node, int l, int r, int u, int v, line val) {
	if (l > r || v < l || r < u) return ;
	if (u <= l && r <= v) {
		if (it[node].get(a[l]) <= val.get(a[l]) && it[node].get(a[r]) <= val.get(a[r])) return ;
		if (it[node].get(a[l]) >= val.get(a[l]) && it[node].get(a[r]) >= val.get(a[r])) {
			it[node] = val;
			return ;
		}
		ll mid = (l + r) / 2;
		if (it[node].get(a[l]) <= val.get(a[l]) && it[node].get(a[mid]) <= val.get(a[mid])) {
			update(node * 2 + 1, mid + 1, r, u, v, val);
			return ;
		}
		if (it[node].get(a[l]) >= val.get(a[l]) && it[node].get(a[mid]) >= val.get(a[mid])) {
			update(node * 2 + 1, mid + 1, r, u, v, val);
			it[node] = val;
			return ;
		}
		if (it[node].get(mid + 1) <= val.get(mid + 1) && it[node].get(a[r]) <= val.get(a[r])) {
			update(node * 2, l, mid, u, v, val);
			return ;
		}
		if (it[node].get(mid + 1) >= val.get(mid + 1) && it[node].get(a[r]) >= val.get(a[r])) {
			update(node * 2, l, mid, u, v, val);
			it[node] = val;
			return ;
		}
	}
	update(node * 2, l, (l + r) / 2, u, v, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, u, v, val);
}

ll query(ll node, ll l, ll r, ll pos) {
	if (pos < l || pos > r) return LINF;
	ll res = it[node].get(a[pos]);
	if (l == r) return res;
	return min(res, min(query(node * 2, l, (l + r) / 2, pos), query(node * 2 + 1, (l + r) / 2 + 1, r, pos)));
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= 4 * n; i++) {
		it[i].a = it[i].b = INF;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	line tam;
	tam.a = b[1];
	tam.b = 0;
	update(1, 1, n, 2, n, tam);
	for (int i = 2; i < n; i++) {
		ll temp = query(1, 1, n, i);
		line tam;
		tam.a = b[i];
		tam.b = temp;
		//cout << temp << '\n';
		update(1, 1, n, i + 1, n, tam);
	}
	cout << query(1, 1, n, n);
}
 