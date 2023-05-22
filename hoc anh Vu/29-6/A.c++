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
const ll BLOCK_SIZE = 450;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Query {
	int l, r, index;
} d[200003];

int n, q;

ll a[200003], cnt[1000003], ans, res[200003];

void add(int pos) {
	ans -= cnt[a[pos]] * cnt[a[pos]] * a[pos];
	cnt[a[pos]] ++;
	ans += cnt[a[pos]] * cnt[a[pos]] * a[pos];
}

void cut(int pos) {
	ans -= cnt[a[pos]] * cnt[a[pos]] * a[pos];
	cnt[a[pos]] --;
	ans += cnt[a[pos]] * cnt[a[pos]] * a[pos];	
}

int main() {
	fast;
	//fre();
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++) {
		cin >> d[i].l >> d[i].r;
		d[i].index = i;
	}
	sort(d + 1, d + q + 1, [&](Query &x, Query &y) {
		if (x.l / BLOCK_SIZE == y.l / BLOCK_SIZE) return x.r < y.r;
		return x.l < y.l;
	});
	int curl = 0, curr = 0;
	ans = a[0];
	cnt[a[0]] ++;
	for (int i = 1; i <= q; i++) {
		int l = d[i].l - 1, r = d[i].r - 1;
		while (curr < r) add(++curr);
		while (curr > r) cut(curr--);
		while (curl < l) cut(curl++);
		while (curl > l) add(--curl);
		res[d[i].index] = ans;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}
