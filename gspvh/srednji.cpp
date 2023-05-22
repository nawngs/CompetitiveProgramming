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

const string NAME = "srednji";
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

ll n, a[300004], k, it[1200003];

vector < pii > s;

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	it[node] ++;
	if (l == r) return ;
	update(node * 2, l, (l + r) / 2, pos);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(node * 2, l, (l + r) / 2, u, v) + query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

ll solve(int x) {
	s.clear();
	s.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		pii tam;
		tam.fi = s.back().fi + (a[i] >= x) - (a[i] < x);
		tam.se = i;
		s.push_back(tam);
	}
	memset(it, 0, sizeof(it));
	sort(s.begin(), s.end(), [](pii &x, pii &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);
	});
	ll res = 0;
	for (int i = 0; i < s.size(); i++) {
		//cout << s[i].fi << " " << s[i].se << '\n';
		res += 1ll * query(1, 0, n, 0, s[i].se);
		update(1, 0, n, s[i].se);
	}
	return res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << solve(k) - solve(k + 1);
}
