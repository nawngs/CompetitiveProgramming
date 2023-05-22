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

ll n, x, res = 1;

map < ll , int > f;

int bfs(ll x) {
	queue < pll > q;
	q.push({x, 0});
	while (q.size()) {
		pll u = q.front();
		q.pop();
		//cout << u.fi << " " << u.se << '\n';
		if (u.fi >= res) return u.se;
		if (f[u.fi]) continue;
		f[u.fi] = u.se;
		ll tam = u.fi;
		while (tam > 0) {
			if (tam % 10 != 1) q.push({u.fi * (tam % 10), u.se + 1});
			tam /= 10;
		}
	}
	return -1;
}

void sol() {
	cin >> n >> x;
	for (int i = 1; i < n; i++) res = res * 10;
	cout << bfs(x);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
