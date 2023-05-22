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

int l, r;

string sa, sb;

vector < pair < char, ll > > a, b, c, d;

vector < pair < char, ll > > change(const string &s) {
	vector < pair < char, ll > > res;
	char c;
	ll cur = 0;
	for (auto x : s) {
		if ('0' <= x && x <= '9') cur = cur * 10 + x - '0';
		else {
			if (cur != 0) res.push_back({c, cur});
			cur = 0;
			c = x;
		}
	}
	res.push_back({c, cur});
	return res;
}

void merge (vector < pair < char, ll > > &x, const vector < pair < char, ll > > &y) {
	for (auto v : y) {
		if (x.back().fi == v.fi) x.back().se += v.se;
		else x.push_back(v);
	}
}

int main() {
	//fast;
	//fre();
	string type;
	while (cin >> type) {
		if (type[1] == '1') {
			cin >> sa >> sb;
			a.clear(); b.clear();
			a = change(sa); b = change(sb);
			merge(a, b);
			cout << "@1: ";
			for (auto x : a) if (x.se != 0) cout << x.fi << x.se;
			cout << '\n';
		}
		if (type[1] == '2') {
			cin >> sa >> l >> r;
			r = l + r - 1;
			l --;
			a.clear(); a = change(sa);
			ll cur = 0;
			b.clear(); c.clear();
			for (auto x : a) {
				if (cur + x.se >= l) {
					b.push_back({x.fi, l - cur});
					break;
				}
				else b.push_back(x);
				cur += x.se;
			}
			cur = r;
			for (auto x : a) {
				if (cur >= x.se) cur -= x.se;
				else {
					c.push_back({x.fi, x.se - cur});
					cur = 0;
				}
			}
			merge(b, c);
			cout << "@2: ";
			for (auto x : b) if (x.se != 0) cout << x.fi << x.se;
			cout << '\n';
		}
		if (type[1] == '3') {
			cin >> sa >> l >> r;
			l --;
			a.clear(); a = change(sa);
			b.clear();
			ll cur = l;
			for (auto x : a) {
				if (cur > x.se) cur -= x.se;
				else {
					b.push_back({x.fi, x.se - cur});
					cur = 0;
				}
			}
			cout << "@3: ";
			cur = 0;
			for (auto x : b) {
				if (cur + x.se >= r) {
					if (r - cur != 0) cout << x.fi << r - cur;
					break;
				}
				else if (x.se != 0) cout << x.fi << x.se;
				cur += x.se;
			}
			cout << '\n';
		}
		if (type[1] == '4') {
			cin >> sa >> sb >> l;
			l --;
			r = l;
			a.clear(); a = change(sa);
			b.clear(); b = change(sb);
			c.clear(); d.clear();
			ll cur = 0;
			for (auto x : a) {
				if (cur + x.se >= l) {
					c.push_back({x.fi, l - cur});
					break;
				}
				else c.push_back(x);
				cur += x.se;
			}
			cur = r;
			for (auto x : a) {
				if (cur >= x.se) cur -= x.se;
				else {
					d.push_back({x.fi, x.se - cur});
					cur = 0;
				}
			}
			merge(c, b); merge(c, d);
			cout << "@4: ";
			for (auto x : c) if (x.se != 0) cout << x.fi << x.se;
			cout << '\n';
		}
	}
}
