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

	vector < int > a, b, tmp;

	vector < vector < int > > res, rev_res;

	int get_min(vector < int > x) {
		int res = LINF;
		for (auto i : x) res = min(res, i);
		return res;
	} 

	int get_max(vector < int > x) {
		int res = -LINF;
		for (auto i : x) res = max(res, i);
		return res;
	}

	signed main() {
		//fast;
		a.resize(3);
		b.resize(3);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;
		while (1) {
			tmp.clear();
			for (auto x : a) tmp.push_back(x);
			sort(tmp.begin(), tmp.end());
			if (tmp[1] - tmp[0] == tmp[2] - tmp[1]) break;
			int new_val = tmp[1] - (tmp[2] - tmp[1]);
			if (abs(new_val) <= 1e18) {
				for (auto &x : a) {
					if (x == tmp[2]) {
						x = new_val;
						break;
					}
				}
			}
			else {
				new_val = tmp[1] + (tmp[1] - tmp[0]);
				for (auto &x : a) {
					if (x == tmp[0]) {
						x = new_val;
						break;
					}
				}
			}
			res.push_back(a);
		}
		rev_res.push_back(b);
		while (1) {
			tmp.clear();
			for (auto x : b) tmp.push_back(x);
			sort(tmp.begin(), tmp.end());
			if (tmp[1] - tmp[0] == tmp[2] - tmp[1]) break;
			int new_val = tmp[1] - (tmp[2] - tmp[1]);
			if (abs(new_val) <= 1e18) {
				for (auto &x : b) {
					if (x == tmp[2]) {
						x = new_val;
						break;
					}
				}
			}
			else {
				new_val = tmp[1] + (tmp[1] - tmp[0]);
				for (auto &x : b) {
					if (x == tmp[0]) {
						x = new_val;
						break;
					}
				}
			}
			rev_res.push_back(b);
		}
		if (((get_min(b) - get_min(a)) % (get_max(a) - get_min(a)) != 0) || (get_max(a) - get_min(a) != get_max(b) - get_min(b))) {
			cout << -1 << '\n';
			return 0;
		}
		while (get_min(a) != get_min(b)) {
			tmp.clear();
			for (auto x : a) tmp.push_back(x);
			sort(tmp.begin(), tmp.end());
			if (get_min(b) > get_min(a)) {
				int new_val1 = tmp[2] + (tmp[2] - tmp[0]);
				int new_val2 = tmp[2] + (tmp[2] - tmp[1]);
				for (auto &x : a) if (x == tmp[0]) x = new_val1;
				res.push_back(a);
				for (auto &x : a) if (x == tmp[1]) x = new_val2;
				res.push_back(a);
			}
			else {
				int new_val1 = tmp[0] - (tmp[1] - tmp[0]);
				int new_val2 = tmp[0] - (tmp[2] - tmp[0]);
				for (auto &x : a) if (x == tmp[1]) x = new_val1;
				res.push_back(a);
				for (auto &x : a) if (x == tmp[2]) x = new_val2;
				res.push_back(a);
			}
		}
		rev_res.pop_back();
		if (!res.size()) {
			res.push_back(rev_res.back());
			rev_res.pop_back();
		}
		while(rev_res.size()) {
			vector < int > x = res.back(), y = rev_res.back();
			int valx, valy;
			for (auto curx : x) {
				bool th = false;
				for (auto cury : y) if (curx == cury) th = 1;
				if (!th) valx = curx;
			}
			for (auto cury : y) {
				bool th = false;
				for (auto curx : x) if (cury == curx) th = 1;
				if (!th) valy = cury;
			}
			for (auto &curx : x) if (curx == valx) {curx = valy; break;}
			res.push_back(x);
			rev_res.pop_back();
		}
		cout << res.size() << '\n';
		for (auto x : res) {
			for (auto i : x) cout << i << ' ';
			cout << '\n';
		}
	}
