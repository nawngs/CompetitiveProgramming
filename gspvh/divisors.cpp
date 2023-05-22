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

const int nmax = 1e6;

int d[nmax + 3], s, t;

vector < int > adj[nmax + 3];

int main() {
	fast;
	// freopen("divisors.inp", "r", stdin);
	// freopen("divisors.out", "w", stdout);
	cin >> s >> t;
	for (int i = s; i <= t; i++)
		d[i] = 100000;
	d[s] = 0;
	for (int i = 2; i <= t; i++) 
		for (int j = 2 * i; j <= t; j+=i) adj[j].push_back(i);
	for (int i = s; i < t; i++) {
		if (d[i] == 100000) continue;
		for (auto x : adj[i]) {
			if (i + x > t) break;
			d[i + x] = min(d[i + x], d[i] + 1);
		}
	}
	
	cout << (d[t] == 100000 ? -1 : d[t]) << '\n';
}