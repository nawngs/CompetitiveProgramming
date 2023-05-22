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

ll n, a[100003], it[400003], sub;

pll s[100003];

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	it[node] ++;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

bool check(ll x) {
	s[0] = {0, 0};
	for (int i = 1; i <= n; i++) {
		s[i].fi = s[i - 1].fi + (a[i] <= x);
		s[i].se = i;
	}
	for (int i = 0; i <= n; i++) 
		s[i].fi = 2 * s[i].fi - i;
	sort(s, s + n + 1, [&](pll &x, pll &y) {
		if (x.fi != y.fi) return x.fi < y.fi;
		return x.se > y.se;
	});
	memset(it, 0, sizeof(it));
	ll res = 0;
	for (int i = 0; i <= n; i++) {
		res += query(1, 0, n, 0, s[i].se);
		update(1, 0, n, s[i].se);
	}
	return res > (sub / 2);
}

int main() {
	fast;
	//fre();
	cin >> n;
	sub = n * (n + 1) / 2;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	//check(8);
	ll l = 1, r = INF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}
