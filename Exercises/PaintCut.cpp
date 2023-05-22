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

const string NAME = "PaintCut";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

struct Data {
	ll minl, maxl, minr, maxr;
	Data(ll _minl, ll _maxl, ll _minr, ll _maxr) : minl(_minl), maxl(_maxl), minr(_minr), maxr(_maxr){};
};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, a[105][105], maxl[105][105], minl[105][105], maxr[105][105], minr[105][105];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		maxl[i][0] = -INF;
		minl[i][0] = INF;
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			maxl[i][j] = max(maxl[i][j - 1], a[i][j]);
			minl[i][j] = min(minl[i][j - 1], a[i][j]);
		}
		maxr[i][m + 1] = -INF;
		minr[i][m + 1] = INF;
		for (int j = m; j >= 1; j--) {
			maxr[i][j] = max(maxr[i][j + 1], a[i][j]);
			minr[i][j] = min(minr[i][j + 1], a[i][j]);
		}
	}
	for (int i = 1; i < m; i++) {
		vector < Data > temp;
		for (int j = 1; j <= n; j++) {
			temp.push_back({minl[j][i], maxl[j][i], minr[j][i + 1], maxr[j][i + 1]});
		}
		sort(temp.begin(), temp.end(), [](Data &x, Data &y) {
			return x.maxl < y.maxl;
		});
		for (int j = 0; j < n - 1; j++) {
			ll mina = INF;
			for (int k = j + 1; k < n; k ++) mina = min(mina, temp[k].minl);
			if (mina <= temp[j].maxl) continue;
			mina = INF;
			ll maxa = -INF;
			for (int k = 0; k <= j; k ++) mina = min(mina, temp[k].minr);
			for (int k = j + 1; k < n; k++) maxa = max(maxa, temp[k].maxr);
			if (mina > maxa) {
				cout << "YES" << '\n';
				return ;
			}
		}
	}
	cout << "NO" << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
