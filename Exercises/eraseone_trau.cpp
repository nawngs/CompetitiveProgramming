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

const string NAME = "eraseone";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[10003];

ll calc(vector < int > c) {
	ll dem = 1, res = 1;
	for (int i = 1; i < c.size(); i++) {
		if (c[i] >= c[i - 1]) dem ++;
		else {
			res = max(res, dem);
			dem = 1;
		}
	}
	res = max(res, dem);
	return res;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		vector < int > temp;
		temp.clear();
		for (int j = 1; j < i; j++) temp.push_back(a[j]);
		for (int j = i + 1; j <= n; j++) temp.push_back(a[j]);
		ans = max(ans, calc(temp));
		//if (ans == 7) cout << i << '\n';
	}
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
