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

int n, m, a[53][53], cnt[53];

vector < pii > pos[53];

vector < pair < pii, pii > > res;

pii find_pos(int row, int first_col, int color) {
	for (int i = row + 1; i <= m; i++) if (a[i][first_col] == color) return {i, first_col};
	for (int i = 1; i <= m; i++) 
		for (int j = first_col + 1; j <= n; j++) if (a[i][j] == color) return {i, j};
} 

void sol() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	res.clear();
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			cnt[a[i][j]] ++;
		}
	
	for (int tam = n - 1; tam >= 1; tam--) {
		//cout << tam << '\n';
		int maxval = -1, minval = INF, maxcolor, mincolor;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == 0) continue;
			if (cnt[i] > maxval) {
				maxval = cnt[i];
				maxcolor = i;
			}
			if (cnt[i] < minval) {
				minval = cnt[i];
				mincolor = i;
			}
		}
		minval = min(minval, m);
		for (int i = 1; i <= minval; i++) {
			cnt[mincolor] --;
			if (a[i][n - tam] == mincolor) continue;
			
			pii tem = find_pos(i, n - tam, mincolor);
			//cout << i << " " << n - tam << '\n';
			res.push_back({{i, n - tam}, tem});
			swap(a[i][n - tam], a[tem.fi][tem.se]);
		}
		for (int i = minval + 1; i <= m; i++) {
			cnt[maxcolor] --;
			if (a[i][n - tam] == maxcolor) continue;
			pii tem = find_pos(i, n - tam, maxcolor);
			//cout << i << " " << n - tam << '\n';
			res.push_back({{i, n - tam}, tem});
			swap(a[i][n - tam], a[tem.fi][tem.se]);
		}
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x.fi.fi << " " << x.fi.se << " " << x.se.fi << " " << x.se.se << '\n';
}

int main() {
	//fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
