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

const string NAME = "BubbleSort";
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

int n, a[100005], it[600005];

vector < pii > p;

void roi_rac() {
	p.clear();
	for (int i = 1; i <= n; i++) p.push_back({a[i], i});
	sort(p.begin(), p.end());
	int dem = 0;
	for (int i = 0; i < p.size(); i++) {
		dem += (i == 0 || p[i].fi != p[i - 1].fi);
		//1cout << p[i].fi << " " << p[i].se << " " << dem << '\n';
		a[p[i].se] = dem;
	}
}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] ++;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	roi_rac();
	int ans = 0;
	memset(it, 0, sizeof(it));
	for (int i = 1; i <= n; i++) {
		int tam = query(1, 1, n, a[i] + 1, n);
		ans = max(ans, tam);
		update(1, 1, n, a[i]);
	}
	cout << ans << '\n';

}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
