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

const string NAME = "relativnost";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e4 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, a[100003], b[100003], q, it[600003][22], cnt[600003];

void merge(int node) {
	cnt[node] = (cnt[node * 2] * cnt[node * 2 + 1]) % MOD;
	for (int i = 0; i <= k; i++) it[node][i] = 0;
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k - i; j++) it[node][i + j] += it[node * 2][i] * it[node * 2 + 1][j];
	for (int i = 0; i <= k; i++) it[node][i] %= MOD;
}

void build_tree(int node, int l, int r) {
	if (l == r) {
		cnt[node] = (a[l] + b[l]) % MOD;
		it[node][1] = a[l] % MOD;
		it[node][0] = b[l] % MOD;
		return ; 
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	merge(node);
}

void update(int node, int l, int r, int pos, int val1, int val2) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		cnt[node] = (val1 + val2) % MOD;
		it[node][1] = val1 % MOD;
		it[node][0] = val2 % MOD;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val1, val2);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val1, val2);
	merge(node);
}

int main() {
	fast;
	fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= n; j++) cin >> b[j];
	build_tree(1, 1, n);
	cin >> q;
	while (q--) {
		int i, newa, newb;
		cin >> i >> newa >> newb;
		update(1, 1, n, i, newa, newb);
		int ans = cnt[1];
		//cout << ans << '\n';
		//cout << it[1][0] << " " << it[1][1] << '\n';
		for (int i = 0; i < k; i++) ans = (ans - it[1][i] + MOD) % MOD;
		cout << ans << '\n';
	}
}
