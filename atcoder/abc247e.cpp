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
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

int n, a[200003], x, y;

pii it[1200003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node].fi = it[node].se = a[l];
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node].fi = max(it[node * 2].fi, it[node * 2 + 1].fi);
	it[node].se = min(it[node * 2].se, it[node * 2 + 1].se);
}

pii query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return {-INF, INF};
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	pii lnode = query(node * 2, l, mid, u, v), rnode = query(node * 2 + 1, mid + 1, r, u, v);
	return {max(lnode.fi, rnode.fi), min(lnode.se, rnode.se)};
}

int bs1(int pos) {
	int l = 1, r = pos, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		pii tam = query(1, 1, n, mid, pos);
		//if (pos == 3) cout << mid << " " << pos << " " <<  tam.fi << " " << tam.se << '\n';
		if ((tam.fi < x && tam.se < y) || (tam.fi > x && tam.se > y)) return -1;
		if (tam.fi == x && tam.se == y) {
			ans = mid;
			r = mid - 1;
		}
		else {
			if (tam.fi != x) {
				if (tam.fi > x) {
					l = mid + 1;
				}
				else r = mid - 1;
			}
			else {
				if (tam.se > y) r = mid - 1;
				else l = mid + 1;
			}
		}
	}
	return ans;
}

int bs2(int pos) {
	int l = 1, r = pos, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		pii tam = query(1, 1, n, mid, pos);
		if ((tam.fi < x && tam.se < y) || (tam.fi > x && tam.se > y)) return -1;
		if (tam.fi == x && tam.se == y) {
			ans = mid;
			l = mid + 1;
		}
		else {
			if (tam.fi != x) {
				if (tam.fi > x) l = mid + 1;
				else r = mid - 1;
			}
			else {
				if (tam.se > y) r = mid - 1;
				else l = mid + 1;
			}
		}
	}
	return ans;
}

void sol() {
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	ll ans = 0;
	//cout << query(1, 1, n, 13, 13).fi << " " << query(1, 1, n, 13, 13).se << '\n';
	for (int i = 1; i <= n; i++) {
		int tam1 = bs1(i);
		int tam2 = bs2(i);
		//cout << tam1 << " " << tam2 << '\n';
		if (tam1 == -1 || tam2 == -1) continue;
		//cout << tam1 << " " << tam2 << '\n';
		ans += 1ll * (tam2 - tam1 + 1);
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
