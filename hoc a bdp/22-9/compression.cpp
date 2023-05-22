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

int m, n, a[3003][3003];

int main() {
	fast;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	int width_a = 0, height_a = 0;
	for (int i = 1; i <= m; i++) {
		int dem = 1;
		for (int j = 2; j <= n; j++) {
			if (a[i][j] == a[i][j - 1]) dem ++;
			else {
				width_a = __gcd(width_a, dem);
				dem = 1;
			}
		}
		width_a = __gcd(width_a, dem);
	}
	for (int j = 1; j <= n; j++) {
		int dem = 1;
		for (int i = 2; i <= m; i++) {
			if (a[i][j] == a[i - 1][j]) dem ++;
			else {
				height_a = __gcd(height_a, dem);
				dem = 1;
			}
		}
		height_a = __gcd(height_a, dem);
	}
	cout << m / height_a << " " << n / width_a << '\n';
	for (int i = 1; i <= m / height_a; i++) {
		for (int j = 1; j <= n / width_a; j++) cout << a[i * height_a][j * width_a];
		cout << '\n';
	}
}
