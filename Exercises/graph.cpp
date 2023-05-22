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

const string NAME = "graph";
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

int n, a[2003], b, ans = 0;

void dequy(int pos) {
	if (pos == n + 1) {
		vector < int > tam;
		tam.clear();
		tam.push_back(a[1]);
		for (int i = 2; i <= n; i++) {
			sort(tam.begin(), tam.end(), greater < int >());
			for (int j = 0; j < a[i]; j++) tam[j] ++;
			if (tam[0] > b) return ;
			tam.push_back(a[i]);
		}
		ans ++;
		return ;
	}
	if (a[pos] != -1) dequy(pos + 1);
	else {
		for (int i = 0; i < pos; i++) {
			a[pos] = i;
			dequy(pos + 1);
			a[pos] = -1;
		}
	}
}	

void sol() {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 6) {
		dequy(1);
		cout << ans << '\n';
		return ;
	}
	if (n <= 200) {
		int pos;
		for (int i = 1; i <= n; i++) if (a[i] == -1) pos = i;
		for (int i = 0; i < pos; i++) {
			a[pos] = i;
			vector < int > tam;
			tam.clear();
			tam.push_back(a[1]);
			for (int j = 2; j <= n; j++) {
				sort(tam.begin(), tam.end(), greater < int >());
				for (int k = 0; k < a[j]; k++) tam[k] ++;
				if (tam[0] > b) {
					cout << ans << '\n';
					return ;
				}
				tam.push_back(a[j]);
			}
			ans ++;
		}
		cout << ans;
		return ;
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
