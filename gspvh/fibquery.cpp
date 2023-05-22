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

const string NAME = "fibquery";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 19972207;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct matran {
	ll c[2][2];
	matran(){
		c[0][0] = 0;
		c[0][1] = 1;
		c[1][0] = 1;
		c[1][1] = 1;
	}
};

matran nhan(matran a, matran b){
	matran res;
	for(int i = 0; i <= 1; i++) {
		for(int j = 0; j <= 1; j++) {
			res.c[i][j] = 0;
			for(int k = 0; k <= 1; k++) res.c[i][j] = (res.c[i][j] + (a.c[i][k] * b.c[k][j])) % MOD;
		}
	}
	return res;
}

matran po(matran a, ll n){
	if(n == 1) return a;
	matran ha = po(a, n / 2);
	ha = nhan(ha, ha);
	if(n % 2 == 1) ha = nhan(ha, a);
	return ha;
}

pll double_fibo(ll x) {
	matran f, tam = po(f, x);
	return {tam.c[0][0], tam.c[0][1]};
}

int n, q;

ll it[2000003], s[500003], fibo[500003];

pll lazy[2000003];

ll calc (ll l, ll r) {
	return (s[r] - s[l - 1] + MOD) % MOD;
}

void upd_node(ll node, ll l, ll r) {
	if (lazy[node] != make_pair(0ll, 0ll)) {
		if (l == r) {
			it[node] = (it[node] + lazy[node].fi) % MOD;
			lazy[node] = {0, 0};
			return ;
		}
		if (r == l + 1) {
			it[node] = (it[node] + lazy[node].fi + lazy[node].se) % MOD;
			lazy[node * 2].fi += lazy[node].fi;
			lazy[node * 2 + 1].fi += lazy[node].se;
			lazy[node * 2].fi %= MOD;
			lazy[node * 2 + 1].fi %= MOD;
			lazy[node] = {0, 0};
			return ;
		}
		it[node] = (it[node] + (lazy[node].fi * (calc(1, r - l - 1) + 1) % MOD + (lazy[node].se * (calc(2, r - l) + 1)) % MOD)) % MOD;
		//cout << node << " " << l << " " << r << " " << it[node] << " " << lazy[node].fi << " " << lazy[node].se << '\n';
		lazy[node * 2].fi += lazy[node].fi;
		lazy[node * 2].se += lazy[node].se;
		int pos = (l + r) / 2 + 1 - l - 1;
		ll tam1 = fibo[pos];
		ll tam2 = fibo[pos + 1];
		ll tam = tam1 * lazy[node].fi + tam2 * lazy[node].se;
		tam %= MOD;
		lazy[node * 2 + 1].fi += tam;
		tam = tam2 * lazy[node].fi + (tam1 + tam2) * lazy[node].se;
		tam %= MOD;
		lazy[node * 2 + 1].se += tam;
		lazy[node * 2].fi %= MOD;
		lazy[node * 2].se %= MOD;
		lazy[node * 2 + 1].fi %= MOD;
		lazy[node * 2 + 1].se %= MOD;
		lazy[node] = {0, 0};
	}
}

void update(int node, int l, int r, int u, int v, ll val) {
	upd_node(node, l, r);
	if (v < l || r < u) return ; 
	if (u <= l && r <= v) {
		lazy[node] = double_fibo(l - val + 1);
		upd_node(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = (it[node * 2] + it[node * 2 + 1]) % MOD;
}

ll query(int node, int l, int r, int u, int v) {
	//cout << node << " " << l << " " << r << " " << it[node] << '\n';
	upd_node(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return (query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v)) % MOD;
}

int main() {
	//cout << fibo(0) << '\n';
	fast;
	//fre();
	cin >> n >> q;
	fibo[1] = 1;
	s[1] = 1;
	for (int i = 2; i <= n; i++) {
		s[i] = (s[i - 1] + fibo[i - 1] + fibo[i - 2]) % MOD;
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	}
	for (int i = 1; i <= 4 * n; i++) lazy[i] = {0, 0};
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			ll l, r, k;
			cin >> l >> r >> k;
			update(1, 1, n, l, r, l - k);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << ' ';
		}
	}
}