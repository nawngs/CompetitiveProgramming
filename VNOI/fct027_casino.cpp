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
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

int n, pos[5][300003];

map < pii, int > f;

void sol() {
	cin >> n;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			pos[i][x] = j;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int dist1 = (pos[2][i] - pos[1][i] + n) % n;
		int dist2 = (pos[3][i] - pos[1][i] + n) % n;
		f[{dist1, dist2}] ++;
		ans = max(ans, f[{dist1, dist2}]);
 	}
 	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
