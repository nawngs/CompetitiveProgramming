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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getrand(const int& mi, const int& ma) {
    return rng() % (ma - mi + 1) + mi;
}

bool used[15];

int main() {
	//fast;
	int n = getrand(5, 10);
	int c = getrand(1, n - 1);
	int r = getrand(0, n - 1);
	cout << n << " " << c << " " << r << '\n';
	used[r] = 1;
	for (int i = 1; i <= n - 1; i++) {
		while (1) {
			int tam = getrand(0, n - 1);
			if (used[tam]) continue;
			cout << tam << '\n';
			used[tam] = 1;
			break;
		}
	}
	int mx_sze = n - 1;
	for (int i = 1; i <= c; i++) {
		int sze = getrand(1, mx_sze - (c - i));
		int l = getrand(0, mx_sze - sze);
		cout << l << " " << l + sze << '\n';
		mx_sze -= sze;
	}
}
