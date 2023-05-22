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

const string NAME = "flycam";
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

int n, h[100003], it[2400003], lazy[2400003];

void update_node(int node, int l, int r) {
	if (lazy[node]) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v) {
	update_node(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = 1;
		update_node(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v);
	update(node * 2 + 1, mid + 1, r, u, v);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int main() {
	fast;
	fre();
	cin >> n;
	vector < int > roi_rac;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		h[i] *= 2;
		roi_rac.push_back(h[i]);
		roi_rac.push_back(h[i] + 1);
		roi_rac.push_back(h[i] - 1);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) 
		h[i] = lower_bound(roi_rac.begin(), roi_rac.end(), h[i]) - roi_rac.begin();
	update(1, 0, 3 * n, h[1], h[1]);
	for (int i = 1; i < n; i++) {
		if (h[i] == h[i + 1]) {
			update(1, 0, 3 * n, h[i], h[i]);
			continue;
		}
		int mina = min(h[i], h[i + 1]);
		int maxa = max(h[i], h[i + 1]);
		if (mina == h[i]) mina ++;
		else maxa --;
		update(1, 0, 3 * n, mina, maxa);
	}
	cout << it[1];
}
