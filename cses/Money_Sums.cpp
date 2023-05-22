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
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[103];

bool check[103][100003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	check[0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 100000; j++) {
			if (j < a[i]) check[i][j] = check[i - 1][j];
			else check[i][j] = check[i - 1][j] || check[i - 1][j - a[i]];
		}
	}
	int ans = 0;
	vector < int > res;
	res.clear();
	for (int j = 1; j <= 100000; j++) {
		for (int i = 1; i <= n; i++) {
			if (check[i][j]) {
				ans ++;
				res.push_back(j);
				break;
			}
		}
	}
	cout << ans << '\n';
	for (auto x : res) cout << x << ' ';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
