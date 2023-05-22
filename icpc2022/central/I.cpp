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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, cnt[100003][4][5], a[100003];

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cnt[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		cnt[i][0][0] = 1;
		for (int j = 1; j <= 3; j++) {
			for (int k = 0; k < 5; k++) {
				cnt[i][j][k] = cnt[i - 1][j][k];
				int temp = ((k - a[i]) % 5 + 25) % 5;
				cnt[i][j][k] += cnt[i - 1][j - 1][temp];
			}
		}
	}
	cout << cnt[n][3][0];
}
