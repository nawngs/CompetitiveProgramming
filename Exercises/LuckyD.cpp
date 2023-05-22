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

const string NAME = "LuckyD";
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

int d, x;

bool check[105];

vector < int > a;

void sol() {
	cin >> d >> x;
	if (x > 100) {
		cout << "YES" << '\n';
		return ;
	}
	a.clear();
	memset(check, false, sizeof(check));
	for (int i = 0; i <= 9; i++) a.push_back(i * 10 + d);
	for (int i = 0; i <= 9; i++) a.push_back(d * 10 + i);
	check[0] = true;
	for (int i = 1; i <= 100; i++) {
		for (auto x : a) {
			if (x <= i) check[i] = (check[i] || check[i - x]);
		}
	}
	cout << (check[x] ? "YES" : "NO") << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
