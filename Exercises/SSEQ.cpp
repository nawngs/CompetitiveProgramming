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

const string NAME = "sseq";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 1e6;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	int l, r, val;
} a[100003];

int n;

ll s[2 * base + 5], it[12 * base + 5], lazy[12 * base + 5];

void update(ll node, ll l, ll r, ll u, ll v, ll val) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		it[node] += val;
		if (l != r) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r >> a[i].val;
		a[i].l += base;
		a[i].r += base;
	}
	sort(a + 1, a + n + 1, [](Data &x, Data & y) {
		return (x.r < y.r);
	});
	int l = 1;
	ll ans = 0;
	for (int i = 1; i <= 2 * base; i++) {
		while (l <= n && a[l].r <= i) {
			update(1, 1, 2 * base, 1, a[l].l, a[l].val);
			l ++;
		}
		ans = max(ans, it[1]);
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
