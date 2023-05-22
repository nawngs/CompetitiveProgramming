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
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct line {
	ll a, b;
};

struct pizza {
	ll t, a, b;
} a[100003];

line it[600005];

ll n, B, sa[100003], sb[100003], sbt[100003], dp[100003];

ll get(line d, ll x) {
	return d.a * x + d.b;
}

ll query(ll node, ll l, ll r, ll pos) {
	if (pos < l || pos > r) return -INF;
	ll res = get(it[node], pos);
	if (l == r) return res;
	res = max(res, query(node * 2, l, (l + r) / 2, pos));
	res = max(res, query(node * 2 + 1, (l + r) / 2 + 1, r, pos));
	return res;
}

void update(ll node, ll l, ll r, ll u, ll v, line val) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		if (get(it[node], l) >= get(val, l) && get(it[node], r) >= get(val, r)) return ;
		if (get(it[node], l) <= get(val, l) && get(it[node], r) <= get(val, l)) {
			it[node] = val;
			return ;
		}
		ll mid = (l + r) / 2;
		if (get(it[node], l) <= get(val, l) && get(it[node], mid) <= get(val, mid)) {
			update(node * 2 + 1, mid + 1, r, u, v, it[node]);
			it[node] = val;
			return ;
		}
		if (get(it[node], l) >= get(val, l) && get(it[node], mid) >= get(val, mid)) {
			update(node * 2 + 1, mid + 1, r, u, v, val);
			return ;
		}
		if (get(it[node], r) <= get(val, r) && get(it[node], mid + 1) <= get(val, mid + 1)) {
			update(node * 2, l, mid, u, v, it[node]);
			it[node] = val;
			return ;
		}
		if (get(it[node], r) >= get(val, r) && get(it[node], mid + 1) >= get(val, mid + 1)) {
			update(node * 2, l, mid, u, v, val);
			return ;
		}
	}
	update(node * 2, l, (l + r) / 2, u, v, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, u, v, val);
}
 
void sol() {
	cin >> n >> B;
	for (int i = 1; i <= n; i++) cin >> a[i].t >> a[i].a >> a[i].b;
	sort(a + 1, a + n + 1, [](pizza &x, pizza &y) {
		return x.t < y.t;
	});
	for (int i = 1; i <= n; i++) {
		sa[i] = sa[i - 1] + a[i].a;
		sb[i] = sb[i - 1] + a[i].b;
		sbt[i] = sbt[i - 1] + a[i].b * a[i].t;
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = (sa[i] - sb[i - 1] * a[i].t + sbt[i - 1]) + query(1, 1, nmax, a[i].t) - B;
		line temp;
		temp.a = sb[i];
		temp.b = dp[i] - sa[i] - sbt[i];
		update(1, 1, nmax, 1, nmax, temp);
		//cout << dp[i] << '\n';
	}
	cout << dp[n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
