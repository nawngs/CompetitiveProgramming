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

const string NAME = "PHOTO";
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

int n, pos[100005][7], a[100005];

void sol() {
	cin >> n;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			pos[x][i] = j;
		}
	}
	for (int i = 1; i <= n; i++) a[i] = i;
	sort(a + 1, a + n + 1, [](int &x, int &y) {
		int dem = 0;
		for (int i = 1; i <= 5; i++) if (pos[x][i] < pos[y][i]) dem ++;
		return dem >= 3;
	});
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
