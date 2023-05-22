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

ll n, a[200003], f[200003], ans = 0;

ll calc(ll x) {
	return (x + 1) * x / 2;
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = LINF;
	stack < int > st;
	st.push(0);
	for (int i = 1; i <= n; i++) {
		while (a[st.top()] < a[i]) st.pop();
		f[i] += calc(i - st.top()) + f[st.top()];
		ans += f[i];
		st.push(i);
	}
	cout << ans;
}
