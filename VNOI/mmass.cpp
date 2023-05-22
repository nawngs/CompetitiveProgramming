#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string s;

ll change(int pos) {
	if (pos >= s.size()) return 1;
	int tam = s[pos] - '0';
	return (2 <= tam && tam <= 9 ? tam : 1); 
}

ll calc(int pos) {
	char c = s[pos];
	ll tam = change(pos + 1);
	if (c == 'C') return 12 * tam;
	if (c == 'H') return 1 * tam;
	if (c == 'O') return 16 * tam;
}

void sol() {
	cin >> s;
	int n = s.size();
	stack < ll > st;
	int i = 0;
	while (i < n) {
		if ('2' <= s[i] && s[i] <= '9') {
			i ++;
			continue;
		}
		if (s[i] == '(') st.push(-1);
		else {
			if (s[i] == ')') {
				ll tam = 0;
				while (st.top() != -1) {
					tam += st.top();
					st.pop();
				}
				st.pop();
				tam *= change(i + 1);
				st.push(tam);
			}
			else st.push(calc(i));
		}
		i ++;
	}
	ll ans = 0;
	while (st.size()) {
		//cout << st.top() << '\n';
		ans += st.top();
		st.pop();
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
