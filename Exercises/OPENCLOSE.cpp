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

const string NAME = "OPENCLOSE";
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

ll a[500005], n;

void sol() {
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	stack < int > st;
	s = ' ' + s;
	ll ans = -INF;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') st.push(i);
		else {
			ans = max(ans, a[st.top()] + a[i]);
			st.pop();
		}
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
