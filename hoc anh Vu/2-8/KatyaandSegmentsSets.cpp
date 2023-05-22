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

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, p[300003], a, b, l, r; 

vector < int > roi_rac;

set < pii > it[400003];

void build(int node, int l, int r) {

}

bool query(int node, int l, int r, int u, int v, int low, int high) {
	if (v < l || r < u) return false;
	if (u <= l && r <= v) {
		auto id = lower_bound(it[node].begin(), it[node].end(), make_pair(low, -1));
		if (id == it[node].end()) return false;
		return ((id->second) <= high);
	}
	int mid = (l + r) / 2;
	return (query(node * 2, l, mid, u, v, low, high) || query(node * 2 + 1, mid + 1, r, u, v, low, high));
}

int main() {
	//fast;
	//fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) 
	build(1, 0, n);
	while (m--) {
		cin >> a >> b >> l >> r;
		cout << (query(1, 0, n, a, b, l, r) ? "yes" : "no") << '\n';
	}
}
