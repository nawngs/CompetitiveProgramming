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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, pos[100003], a[100003], it1[600003], it2[600003];

void update1(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it1[node] ++;
		return ;
	}
	update1(node * 2, l, (l + r) / 2, pos);
	update1(node * 2 + 1, (l + r) / 2 + 1, r, pos);
	it1[node] = it1[node * 2] + it1[node * 2 + 1];
}

void update2(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it2[node] --;
		return ;
	}
	update2(node * 2, l, (l + r) / 2, pos);
	update2(node * 2 + 1, (l + r) / 2 + 1, r, pos);
	it2[node] = it2[node * 2] + it2[node * 2 + 1];
}

int query1(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it1[node];
	return query1(node * 2, l, (l + r) / 2, u, v) + query1(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

int query2(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it2[node];
	return query2(node * 2, l, (l + r) / 2, u, v) + query2(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	int i1 = 1;
	int i2 = n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			int tam = pos[i1];
			tam += query1(1, 1, n, pos[i1] + 1, n);
			tam += query2(1, 1, n, 1, pos[i1] - 1);
			//if (i1 == 2) cout << pos[i1] <<query1(1, 1, n, pos[i1] + 1, n) << " " << query2(1, 1, n, 1, pos[i1] - 1) << '\n'; 
			cout << abs(tam - i1) << ' ';
			update1(1, 1, n, pos[i1]);
			i1 ++;
		}
		else {
			int tam = pos[i2];
			tam += query1(1, 1, n, pos[i2] + 1, n);
			tam += query2(1, 1, n, 1, pos[i2] - 1);
			cout << abs(tam - i2) << ' ';
			update2(1, 1, n, pos[i2]);
			i2 --;
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
