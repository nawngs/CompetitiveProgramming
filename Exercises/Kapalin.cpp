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

const string NAME = "kapalin";
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

int n, a[100003];

vector < int > b;

bool check(int x) {
	b.clear();
	for (int i = 1; i <= n; i++) if (a[i] != x) b.push_back(a[i]);
	for (int i = 0; i < b.size() - 1; i++) if (b[i] != b[b.size() - i - 1]) return false;
	return 1;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n / 2 + 1; i++) {
		if (i > n - i + 1) break;
		if (a[i] != a[n - i + 1]) {
			if (check(a[i])) {
				cout << "YES" << '\n';
				return ;
			}
			if (check(a[n - i + 1])) {
				cout << "YES" << '\n';
				return ;
			}
			cout << "NO" << '\n';
			return ;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
