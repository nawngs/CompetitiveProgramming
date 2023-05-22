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

const string NAME = "PS";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, s[1000003], it[6000003];

void roi_rac() {
	vector < pll > temp;
	for (int i = 0; i <= n; i++) temp.push_back({s[i], i});
	sort(temp.begin(), temp.end());
	int dem = 1;
	for (int i = 0; i < temp.size(); i++) {
		if (i != 0) dem += (temp[i].fi != temp[i - 1].fi);
		s[temp[i].se] = dem;
	}
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	return min(query(node * 2, l, (l + r) / 2, u, v), query(node * 2 + 1, (l + r) / 2 + 1, r, u, v));
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	roi_rac();
	for (int i = 1; i <= 6 * n; i++) it[i] = INF;
	for (int i = 0; i <= n; i++) update(1, 1, n + 1, s[i], i);
	int ans = 0;
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 1) continue;
		int tam = query(1, 1, n + 1, 1, s[i] - 1);
		if (ans < i - tam) {
			ans = i - tam;
			pos = tam;
		}
	}
	cout << pos + 1 << " " << pos + ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
