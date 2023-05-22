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

int n, d, a[300003];

void sol() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int maxpos = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) maxpos = max(maxpos, i + d);
		if(maxpos == i && a[i] == 0) {
			ans ++;
			maxpos = i + d;
		}
	}	
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
