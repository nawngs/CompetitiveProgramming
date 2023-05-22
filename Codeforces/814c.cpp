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

int n, f[1503][30];

string s;

void sol() {
	cin >> n >> s;	
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 'z' - 'a'; j++) {
			int dem = 0, l =  1;
			for (int k = 1; k <= n; k++) {
				if (s[k] - 'a' == j) f[i][j] = max(f[i][j], k - l + 1);
				else {
					if (dem < i) {
						dem ++;
						f[i][j] = max(f[i][j], k - l + 1);
					}
					else {
						while (s[l] - 'a' == j) l ++;
						l ++;
						f[i][j] = max(f[i][j], k - l + 1);
					}
				}
			}
		}
	}
	int q;
	cin >> q;
	while (q --) {
		int x;
		char c;
		cin >> x >> c;
		cout << f[x][c - 'a'] << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
