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

const string NAME = "EXPRESSION";
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

string s;

void sol() {
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	stack < pair < char, ll > > st;
	ll val = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			if (s[i - 1] == 'M') st.push({'T', -1});
			if (s[i - 1] == 'F') st.push({'T', -2});
			if (s[i - 1] == 'X') st.push({'T', -3});
			if (s[i - 1] == 'N') st.push({'T', -4});
			if (s[i - 1] == 'D') st.push({'T', -5});
		}
		if ('0' <= s[i] && s[i] <= '9') val = val * 10 + 1ll * (s[i] - '0');
		if (s[i] == ',') {
			st.push({'V', val});
			val = 0;
		}
		if (s[i] == ')') {
			if ('0' <= s[i - 1] && s[i - 1] <= '9') {
				st.push({'V', val});
				val = 0;
			}
			ll val1 = -INF, val2 = -INF, type = 0;
			while (st.size()) {
				if (st.top().fi == 'T') type = st.top().se;
				if (st.top().fi == 'V') {
					if (val1 == -INF) val1 = st.top().se;
					else val2 = st.top().se;
				}
				st.pop();
				if (type != 0) break;
			}
			if (type == -1) st.push({'V', val1 + val2});
			if (type == -2) st.push({'V', val2 - val1});
			if (type == -3) st.push({'V', max(val1, val2)});
			if (type == -4) st.push({'V', min(val1, val2)});
			if (type == -5) st.push({'V', abs(__gcd(val1, val2))});
		}
	}
	cout << st.top().se << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
