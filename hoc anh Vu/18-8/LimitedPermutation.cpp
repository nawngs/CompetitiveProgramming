	#pragma GCC optimize ("O2")
	#include <bits/stdc++.h>

	#define int ll
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
	const ld ESP = 1e-9;
	const ll INF = 1e9 + 7;
	const ll LINF = 1E18;
	const ll nmax = 2e5;
	const ll MOD = 1e9 + 7;
	const ll base = 2309;

	void fre() {
		string finp = NAME + ".inp";
		string fout = NAME + ".out";
		freopen(finp.c_str(), "r", stdin);
		freopen(fout.c_str(), "w", stdout);
	}

	int n, l[1000003], r[1000003], frac[1000003], casemiro;

	map < pii, int > g;

	int mu(int a, int b) {
		if (b == 0) return 1;
		int x = mu(a, b / 2);
		x = (x * x) % MOD;
		if (b % 2 == 1) x = (x * a) % MOD;
		return x;
	}

	int Ckn(int k, int n) {	
		return (frac[n] * mu((frac[n - k] * frac[k]) % MOD, MOD - 2)) % MOD;
	}

	int calc (int l, int r) {
		if (l == r) {
			if (g.find({l, r}) != g.end()) return 1;
			else return 0;
		}
		if (g.find({l, r}) != g.end()) {
			int pos = g[{l, r}];
			int res = 1;
			if (pos != l && pos != r) res = Ckn(pos - l, r - l);
			if (pos > l) {
				int tam = calc(l, pos - 1);
				if (tam == 0) return 0;
				else if (pos == r) res = tam;
			}
			if (pos < r) {
				int tam = calc(pos + 1, r);
				if (tam == 0) return 0;
				else if (pos == l) res = tam;
			}
			return res;
		}
		else return 0;
	}

	void sol() {
		casemiro++;
		cout << "Case #" << casemiro << ": ";
		g.clear();
		for (int i = 1; i <= n; i++) cin >> l[i];
		for (int i = 1; i <= n; i++) {
			cin >> r[i];
			g[{l[i], r[i]}] = i;
		}
		cout << calc(1, n) << '\n';
	}
	 
	 main() {
		fast;
		//fre();
		frac[0] = 1;
		for (int i = 1; i <= 1000000; i++) frac[i] = (frac[i - 1] * i) % MOD;
		int t = 1;
		while (cin >> n) sol();
	}
