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

const string NAME = "test";
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

int n, a[100003], b[100003], l[100003], r[100003], f[100003], it[400003], dp[5003][5003];

map < int, int > pos;

void sub2() {
	for (int i = 1; i <= n; i++) {
		f[i] = max(f[i], f[i - 1]);
		if (a[i] == b[1]) f[r[i]] = max(f[r[i]], f[l[i] - 1] + (r[i] - l[i] + 1));
	}
	cout << f[n] << '\n';
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] = max(it[node], val);
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

void sub4() {
	for (int i = 1; i <= n; i++) pos[a[i]] = i;
	for (int i = 1; i <= n; i++) {
		if (pos.find(b[i]) != pos.end() && l[pos[b[i]]] <= i && i <= r[pos[b[i]]]) b[i] = pos[b[i]];
		else b[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] != INF) {
			f[i] = query(1, 0, n, 0, b[i]) + 1;
			update(1, 0, n, b[i], f[i]);
		}
		f[i] = max(f[i], f[i - 1]);
	}
	cout << f[n] << '\n';
}

void sub6() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i] == b[j] && l[i] <= j && j <= r[i]) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
		}
	}
	cout << dp[n][n] << '\n';
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	bool th = 1;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		th &= (b[i] == b[1]);
	}
	a[0] = a[n + 1] = INF;
	for (int i = 1; i <= n; i++) {
		l[i] = i - 1;
		while (a[i] >= a[l[i]]) l[i] = l[l[i]];
	}
	for (int i = n; i >= 1; i--) {
		r[i] = i + 1;
		while (a[i] >= a[r[i]]) r[i] = r[r[i]];
	}
	for (int i = 1; i <= n; i++) {
		l[i] ++;
		r[i] --;
	}
	if (n > 5000) {
		if (th) sub2();
		else sub4();
	}
	else sub6 ();
}
