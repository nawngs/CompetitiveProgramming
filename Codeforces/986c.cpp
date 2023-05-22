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

int n, a[(1 << 22)], m;

bool exist[(1 << 22)], vs[(1 << 22)][2];

void dfs(int u, bool IsTrue) {
	if (vs[u][IsTrue]) return ;
	if (IsTrue && !exist[u]) return;
	vs[u][IsTrue] = 1;
	if (IsTrue) dfs((1 << n) - 1 - u, 0);
	else {
		for (int i = 0; i < n; i++) 
			if ((u >> i) & 1) 
				dfs(u ^ (1 << i), IsTrue);
		dfs(u, 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		exist[a[i]] = 1;
	}
	int res = 0;
	for (int i = 1; i <= m; i++)
		if (!vs[a[i]][1]) {
			dfs(a[i], 1);
			res ++;
		}
	cout << res;
}
