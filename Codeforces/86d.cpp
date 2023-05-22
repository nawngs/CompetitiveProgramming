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
const int SZE = 450;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Query {
	int l, r, id;
} Q[200003];

ll n, k, t, a[200003], cnt[1000003], res = 0, ans[200003];

void add(int x) {
	res += 2 * cnt[x] * x + x;
	cnt[x] ++;
}

void remove(int x) {
	res -= 2 * cnt[x] * x - x;
	cnt[x] --;
}


int main() {
	fast;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= t; i++) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].id = i;
	}
	sort(Q + 1, Q + t + 1, [&](Query &x, Query &y) {
		if (x.l / SZE == y.l / SZE) return x.r < y.r;
		else return x.l < y.l;
	});
	for (int i = Q[1].l; i <= Q[1].r; i++)
		add(a[i]);
	ans[Q[1].id] = res;
	int l = Q[1].l, r = Q[1].r;
	for (int i = 2; i <= t; i++) {
		while (l < Q[i].l) {
			remove(a[l]);
			l ++;
		}
		while (l > Q[i].l) {
			l --;
			add(a[l]);
		}
		while (r < Q[i].r) {
			r ++;
			add(a[r]);
		}
		while (r > Q[i].r) {
			remove(a[r]);
			r --;
		}
		ans[Q[i].id] = res;
	}
	for (int i = 1; i <= t; i++)
		cout << ans[i] << '\n';
}
