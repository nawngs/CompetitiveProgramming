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
 
ll n;
 
pll a[2003];
 
vector < pair < ld, int > > tam;
 
 
void sol() {
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i].fi >> a[i].se;
	for (int i = 1; i <= n; i++) {
		int posx = -1, posy = -1;
		tam.clear();
		for (int j = n + 1; j <= 2 * n; j++) {
			if (a[i].fi == a[j].fi) {
				if (posx == -1) {
					posx = j;
					continue;
				}
				cout << i << " " << posx << " " << j << '\n';
				return ;
			}
			if (a[i].se == a[j].se) {
				if (posy == -1) {
					posy = j;
					continue;
				}
				cout << i << " " << posy << " " << j << '\n';
				return ;
			}
			ld tem1 = a[i].fi - a[j].fi;
			ld tem2 = a[i].se - a[j].se;
			tam.push_back({tem1 / tem2, j});
 		}
 		sort(tam.begin(), tam.end());
 		for (int j = 1; j < tam.size(); j++) {
 			if (tam[j].fi == tam[j - 1].fi) {
 				cout << i << " " << tam[j - 1].se << " " << tam[j].se << '\n';
 				return ;
 			}
 		}
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		int posx = -1, posy = -1;
		tam.clear();
		for (int j = 1; j <= n; j++) {
			if (a[i].fi == a[j].fi) {
				if (posx == -1) {
					posx = j;
					continue;
				}
				cout << i << " " << posx << " " << j << '\n';
				return ;
			}
			if (a[i].se == a[j].se) {
				if (posy == -1) {
					posy = j;
					continue;
				}
				cout << i << " " << posy << " " << j << '\n';
				return ;
			}
			ld tem1 = a[i].fi - a[j].fi;
			ld tem2 = a[i].se - a[j].se;
			tam.push_back({tem1 / tem2, j});
 		}
 		sort(tam.begin(), tam.end());
 		for (int j = 1; j < tam.size(); j++) {
 			if (tam[j].fi == tam[j - 1].fi) {
 				cout << i << " " << tam[j - 1].se << " " << tam[j].se << '\n';
 				return ;
 			}
 		}
	}
	cout << -1 << '\n';
}
 
int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}