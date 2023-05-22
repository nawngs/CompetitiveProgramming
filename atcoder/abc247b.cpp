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

int n;

pair < string, string > a[103];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	for (int i = 1; i <= n; i++) {
		bool th1 = false, th2 = false;
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			th1 = (th1 || a[i].fi == a[j].fi);
			th1 = (th1 || a[i].fi == a[j].se);
			th2 = (th2 || a[i].se == a[j].fi);
			th2 = (th2 || a[i].se == a[j].se);
		}
		if (th1 && th2) {
			cout << "No" << '\n';
			return ;  
		} 
	}
	cout << "Yes" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
