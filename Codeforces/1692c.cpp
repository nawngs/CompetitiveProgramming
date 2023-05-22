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

char a[10][10];

void sol() {
	for (int i = 1; i <= 8; i++) 
		for (int j = 1; j <= 8; j++) cin >> a[i][j];
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) {
			if (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j + 1] && a[i][j] == a[i + 1][j - 1] && a[i][j] == a[i + 1][j + 1] && a[i][j] == '#') {
				cout << i << " " << j << '\n';
				return ;
			}
		}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
