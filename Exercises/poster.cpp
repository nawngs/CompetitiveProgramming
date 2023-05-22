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

const string NAME = "poster";
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

int n, w[250003], st[250003][20];

map < int, int > pre;

int get(int l, int r) {
	int k = log2(r - l + 1);
	return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		cin >> w[i];
		st[i][0] = w[i];
	}
	for (int j = 1; (1 << j) <= n; j++) 
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (pre.find(w[i]) == pre.end()) res ++;
		else {
			int pos = pre[w[i]];
			if (get(pos, i) < w[i]) res ++;
		}
		pre[w[i]] = i;
	}
	cout << res;
}
