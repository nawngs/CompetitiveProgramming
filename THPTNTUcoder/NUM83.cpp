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

int n, f[5000003];

void create() {
	int tam1 = 1, tam2 = 1;
	for (int i = 1; i <= 5000000; i++) {
		f[i] = min(3 * tam1, 8 * tam2);
		if (f[i] == 3 * tam1) tam1 ++;
		if (f[i] == 8 * tam2) tam2 ++;
	}
}

void sol() {
	int n;
	cin >> n;
	cout << f[n] << '\n';
}

int main() {
	fast;
	create();
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
