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

const string NAME = "";
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

int n, m, cnt[105][105], q;

string s[100005];

void sol1() {
	cin >> q;
	while (q --) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			if (s[y][z] == '1') s[y][z] = '0';
			else s[y][z] = '1';
		}
		else {
			int res = 0;
			for (int i = 1; i <= m; i++) res += s[y][i] != s[z][i];
				cout << res << '\n';
		}
	}
}

void sol2() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) cnt[i][j] += s[i][k] != s[j][k];
		}
	}
	cin >> q;
	while (q --) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			if (s[y][z] == '1') s[y][z] = '0';
			else s[y][z] = '1';
			for (int i = 1; i <= n; i++) {
				if (i == y) continue;
				if (s[i][z] == s[y][z]) {
					cnt[i][y] --;
					cnt[y][i] --;
				}
				else {
					cnt[i][y] ++;
					cnt[y][i] ++;
				}
			}
		}
		else cout << cnt[y][z] << '\n';
	}

}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	if (m <= 1000) sol1();
	else sol2();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
