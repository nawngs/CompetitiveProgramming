#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii > 
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "shortest";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[230][230], d[230][230];

vector < piii > tem, res;

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			d[i][j] = INF;
			if (i == j) d[i][j] = 0;
		}
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++) tem.push_back({a[i][j], {i, j}});
	sort(tem.begin(), tem.end());
	for (auto x : tem) {
		int pos = -1;
		for (int i = 1; i <= n; i++) 
			if (x.fi == d[x.se.fi][i] + d[x.se.se][i]) {
				pos = i;
				break;
			}
		if (pos == -1) res.push_back(x);
		d[x.se.fi][x.se.se] = d[x.se.se][x.se.fi] = x.fi;
		for (int i = 1; i <= n; i++) {
			d[x.se.fi][i] = min(d[x.se.fi][i], x.fi + d[x.se.se][i]);
			d[x.se.se][i] = min(d[x.se.se][i], x.fi + d[x.se.fi][i]);
			d[i][x.se.fi] = d[x.se.fi][i];
			d[i][x.se.se] = d[x.se.se][i];
		}
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x.se.fi << " " << x.se.se << " " << x.fi << '\n';
}
