#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

void sol() {
	string s;
	cin >> s;
	ll dem1, dem2, dem3;
	dem1 = dem2 = dem3 = 0;
	for (int i = 0; i < s.size(); i++) {
		dem1 += (s[i] == 'A');
		dem2 += (s[i] == 'B');
		dem3 += (s[i] == 'C');
	}
	if (dem2 == dem1 + dem3) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --) sol();
}
