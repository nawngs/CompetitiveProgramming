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

const string NAME = "resort";
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

int n, m, p, q, B, cnt[2003][2003], cnt_[2003][2003];

int calc(int x, int y, int u, int v) {
	return cnt[u][v] - cnt[u][y - 1] - cnt[x - 1][v] + cnt[x - 1][y - 1];
}

int calc_(int x, int y, int u, int v) {
	return cnt_[u][v] - cnt_[u][y - 1] - cnt_[x - 1][v] + cnt_[x - 1][y - 1];
}

int main() {
	fast;
	fre();
	cin >> n >> m >> p >> q >> B;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1];
			cnt_[i][j] = cnt_[i][j - 1] + cnt_[i - 1][j] - cnt_[i - 1][j - 1];
			if (x < B) cnt[i][j] ++;
			if (x == B) cnt_[i][j] ++;
		}
	int res = 0;	
	for (int i = 1; i + p - 1 <= n; i++)
		for (int j = 1; j + q - 1 <= m; j++) {
			int x = i + p - 1;
			int y = j + q - 1;
			int temp = calc(i, j, x, y);
			int temp_ = calc_(i, j, x, y);
			if (temp < p * q / 2 && temp + temp_ >= p * q / 2) res ++;
		}
	cout << res;
}
