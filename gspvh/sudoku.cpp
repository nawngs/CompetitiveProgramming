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

const string NAME = "sudoku";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

char a[12][12];

int cnt_c[12][12], cnt_r[12][12];

int main() {
	fast;
	//fre();
	for (int i = 1; i <= 9; i++) 
		for (int j = 1; j <= 9; j++) {
			cin >> a[i][j];
			a[i][j] -= '0';
			cnt_r[i][a[i][j]] ++;
			cnt_c[j][a[i][j]] ++;
		}
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++) {
			if (cnt_r[i][a[i][j]] > 1 && cnt_c[j][a[i][j]] > 1) {
				cout << i << " " << j << ' ';
				for (int k = 1; k <= 9; k++) if(cnt_r[i][k] == 0) {
					cout << k << '\n';
					return 0;
				}
			}
		}
}
