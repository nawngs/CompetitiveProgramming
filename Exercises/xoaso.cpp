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

const string NAME = "xoaso";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int k;

stack < int > st;

string s;

void sol() {
	cin >> k >> s;
	k = s.size() - k;
	for (int i = 0; i < s.size(); i++) {
		int c = s[i] - '0';
		while (st.size() && c > st.top() && s.size() - i > k - st.size()) st.pop();
		if (st.size() < k) st.push(c);
	}	
	vector < int > a;
	a.clear();
	while (st.size()) {
		a.push_back(st.top());
		st.pop();
	}
	for (int i = a.size() - 1; i >= 0; i--) cout << a[i];
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
