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

string s, s1, s2;

ll calc(ll x, ll y, char c) {
	if (c == '+') return (x + y) % 2;
	if (c == '-') return ((x - y) % 2 + 2);
	if (c == '*') return (x * y) % 2;
}

void sol() {
	cin >> s >> s1 >> s2;
	stack < char > st;
	stack < int > st2;
	int i = 0;
	while (i < s.size()) {
		if (s[i] =='+' || s[i] == '*' || s[i] == '-') {
			if (st.size() && st.top() == '*') {
				ll tam1 = st2.top();
				st2.pop();
				ll tam2 = st2.top();
				st2.pop();
				st2.push(tam1 * tam2);
				st.pop();
			}
			st.push(s[i]);
			i ++;
		}
		else {
			if (s[i] == 'x') {
				if (s1 == "Odd") st2.push(1);
				else st2.push(2);
				i ++;
			}
			else {
				if (s[i] == 'y') {
					if (s2 == "Odd") st2.push(1);
					else st2.push(2);
					i ++;
				}
				else {
					ll val = 0;
					while ('0' <= s[i] && s[i] <= '9') {
						val = (s[i] - '0') % 2;
						i ++;
					}
					st2.push(val);
				}
			}
		}
	}
	while (st.size()) {
		ll tam1 = st2.top();
		st2.pop();
		ll tam2 = st2.top();
		st2.pop();
		char c = st.top();
		st.pop();
		st2.push(calc(tam1, tam2, c));
	}
	cout << (st2.top()% 2 == 0 ? "Even" : "Odd");
}

int main() {
	///fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
