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

int n, x, a[200003];

bool used[200003];

void sol() {
	cin >> n >> x;	
	if (n == 1) {
		cout << "Yes" << " " << 1 << '\n';
		return ;
	}
	if (x == 1 || x == 2 * n - 1) {
		cout << "No" << '\n';
		return ;
	}
	a[n] = x;
	a[n - 1] = x - 1;
	a[n + 1] = x + 1;
	used[x] = used[x + 1] = used[x - 1] = 1;
	int tam = 1;
	for (int i = 1; i <= 2 * n - 1; i++) {
		if (!a[i]) {
			while (used[tam]) tam ++;
			a[i] = tam;
			used[tam] = 1;
		}
	}
	cout << "Yes" << '\n';
	for (int i = 1; i <= 2 * n - 1; i++) cout << a[i] << "\n";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
