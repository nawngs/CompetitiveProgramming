#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
const int BLOCK_SIZE = 320;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, q, k, a[100003], cnt[(1 << 21)], ans = 0, res[100003];

struct Query {
	int l, r, id;
} query[100003];

void xoa(int i) {
	cnt[a[i]] --;
	ans -= cnt[k ^ a[i]];
}

void them(int i) {
	ans += cnt[k ^ a[i]];
	cnt[a[i]] ++;
}

main() {
	fast;
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = a[i - 1] ^ x;
	}
	for (int i = 1; i <= q; i++) {
		cin >> query[i].l >> query[i].r;
		query[i].l --;
		query[i].id = i;
	}
	sort(query + 1, query + q + 1, [&](Query &x, Query &y) {
		return (x.l / BLOCK_SIZE == y.l / BLOCK_SIZE ? (x.r < y.r) : x.l < y.l);
	});
	int l = 1, r = 0;
	for (int i = 1; i <= q; i++) {
		while (l < query[i].l) {
			xoa(l);
			l ++;
		}
		while (l > query[i].l) them(--l);
		while (r < query[i].r) them(++r);
		while(r > query[i].r) {
			xoa(r);
			r--;
		}
		res[query[i].id] = ans;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}
