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

ll n, s, cnt[252][502], a[252];

void create() {
	for (int i = n; i <= 2 * n; i++) cnt[n][i] = 1;
	for (int i = n - 1; i >= 1; i--) {
		cnt[i][2 * i] = cnt[i + 1][2 * i + 1] + cnt[i + 1][2 * i];
		for (int j = 2 * i - 1; j >= i; j--) cnt[i][j] = cnt[i][j + 1] + cnt[i + 1][j + 1];
	}
}

void sol() {
	cin >> n >> s;
	create();
	for (int i = 1; i <= n; i++) {
		ll dem = 0;
		ll pre = 0;
		for (int j = a[i - 1] + 1; j <= 2 * i; j++) {
			dem += cnt[i][j];
			pre = j;
			if (dem >= s) {
				dem -= cnt[i][j];
				break;
			}
		}
		a[i] = pre;
		s -= dem;
	}
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
