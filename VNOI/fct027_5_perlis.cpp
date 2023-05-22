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

int n, a[100003], res[100003];

vector < int > pos[100003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) pos[a[i]].push_back(i);
	int tam = 1;
	for (int i = n; i >= 1; i--) {
		while (pos[tam].size() == 0) tam ++;
		res[pos[tam].back()] = i;
		pos[tam].pop_back();
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
