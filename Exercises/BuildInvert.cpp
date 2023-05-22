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

const string NAME = "BuildInvert";
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

ll n, k;

void sol() {
	cin >> n >> k;
	ll s = 0;
	for (int i = 1; i < n; i++) {
		s += n - i;
		if (s < k) continue;
		else {
			//cout << i << '\n';
			s -= n - i;
			for (int j = 1; j <= k - s; j++) cout << i + j << ' ';
			cout << i << " ";
			for (int j = i + k - s + 1; j <= n; j++) cout << j << " ";
			for (int j = i - 1; j >= 1; j--) cout << j << " ";
			cout << '\n';
			return ;
 		}
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
