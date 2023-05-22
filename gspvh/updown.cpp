#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "updown";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1048576;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[nmax + 3], it[4 * nmax + 3], pos[nmax + 3], val[nmax + 3];

vector < int > roi_rac, Left, Right;

void build_tree(int node, int l, int r) {
	it[node] = r - l + 1;
	if (l == r) return ;
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	it[node] --;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		roi_rac.push_back(a[i]);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) {
		int id = lower_bound(roi_rac.begin(), roi_rac.end(), a[i]) - roi_rac.begin();
		val[id] = a[i];
		a[i] = id;
		pos[a[i]] = i;
	}
	build_tree(1, 1, n);
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int j = pos[i];
		int disl = query(1, 1, n, 1, j - 1);
		int disr = n - i - disl - 1;
		if (disl <= disr) Left.push_back(i);
		else Right.push_back(i);
		res += min(disl, disr);
		update(1, 1, n, j);
	}
	cout << res << '\n';
	for (auto x : Left) cout << val[x] << ' ';
	reverse(Right.begin(), Right.end());
	for (auto x : Right) cout << val[x] << ' ';
}
