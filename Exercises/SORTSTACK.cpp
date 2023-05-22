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

const string NAME = "SORTSTACK";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
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

int mindigit[100003];

void sol() {
	int n = s.size();
	s = ' ' + s;
	mindigit[n + 1] = INF;
	for (int i = n; i >= 1; i--) mindigit[i] = min(mindigit[i + 1], (int) s[i]);
	string ans = "";
	stack < char > st;
	for (int i = 1; i <= n; i++) {
		while (st.size() && st.top() <= mindigit[i]) {
			ans += st.top();
			st.pop();
		}	
		st.push(s[i]);
	}
	while (st.size()) {
		ans += st.top();
		st.pop();
	}
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (cin >> s) sol();
}
