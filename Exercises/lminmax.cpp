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

const string NAME = "lminmax";
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

int n, a[1000003], st1[1000003][22], st2[1000003][22], delta;

int get_max(int l, int r) {
	int k = log2(r - l + 1);
	return max(st1[l][k], st1[r - (1 << k) + 1][k]);
}

int get_min(int l, int r) {
	int k = log2(r - l + 1);
	return min(st2[l][k], st2[r - (1 << k) + 1][k]);
}

int main() {
	fast;
	fre();
	cin >> n >> delta;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st1[i][0] = st2[i][0] = a[i];
	}
	for (int j = 1; j <= 21; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			int nxt = i + (1 << (j - 1));
			st1[i][j] = max(st1[i][j - 1], st1[nxt][j - 1]);
			st2[i][j] = min(st2[i][j - 1], st2[nxt][j - 1]);
		} 
	int r = 1, ans = 0;
	for (int l = 1; l <= n; l++) {
		r = max(r, l);
		while (r < n && get_max(l, r + 1) - get_min(l, r + 1) <= delta) r++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}
