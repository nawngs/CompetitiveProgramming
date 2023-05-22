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

const string NAME = "camera";
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

int n, k, r, t, s[300003];

int main() {
	fast;
	//fre();
	cin >> n >> k >> r >> t;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		s[x] ++;
	}
	vector < int > valid, res;
	int tam = 0;
	for (int i = 1; i <= r; i++) {
		if (s[i] == 0) valid.push_back(i);
		tam = s[i] + tam;
	}
	while (tam < t) {
		res.push_back(valid.back());
		s[valid.back()] ++;
		tam ++;
		valid.pop_back();
	}
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1];
		if (i <= r) continue;
		if (s[i] - s[i - r] < t) {
			res.push_back(i);
			s[i] ++;
		}
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x << ' ';
}
