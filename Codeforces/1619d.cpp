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
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m;

void sol() {
	cin >> m >> n;
	int a[m + 3][n + 3], pos[n + 2];
	for (int i = 1; i <= n; i++) pos[i] = -1e9;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			pos[j] = max(pos[j], a[i][j]);
		} 
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int max1, max2, pos1, pos2;
		max1 = max2 = -1e9;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] >= max2) {
				if (a[i][j] > max2) {
					max2 = a[i][j];
					pos2 = j;
				}
				else if (pos[j] < pos[pos2]) pos2 = j;
			}
			if (max1 <= max2) {
				swap(max1, max2);
				swap(pos1, pos2);
			}
		}
		int tam = 1e9;
		for (int j = 1; j <= n; j++) {
			if (j == pos1) tam = min(tam, max1);
			else if (j == pos2) tam = min(tam, max2);
				else tam = min(tam, pos[j]);
		}
		ans = max(ans, tam);
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
