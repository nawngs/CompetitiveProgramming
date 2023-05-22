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


	int dems[100003], demt[100003];

	string s, t;

	int main() {
		fast;
		//fre();
		cin >> s >> t;
		s = ' ' + s;
		t = ' ' + t;
		for (int i = 1; i < s.size(); i++) dems[i] = dems[i - 1] + (s[i] == 'B');
		for (int i = 1; i < t.size(); i++) demt[i] = demt[i - 1] + (t[i] == 'B');	
		int q;
		cin >> q;
		while (q--) {
			int u, v, x, y;
			cin >> u >> v >> x >> y;
			int dem1 = ((dems[v] - dems[u - 1]) + 2 * (v - u + 1 - dems[v] + dems[u - 1])) % 3;
			int dem2 = ((demt[y] - demt[x - 1]) + 2 * (y - x + 1 - demt[y] + demt[x - 1])) % 3;
			cout << (dem1 == dem2 ? "YES" : "NO") << '\n';
		}
	}
