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

const string NAME = "fence1";
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

ll n, h[1000004], w[1000003], sw[1000003], l[1000003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i] >> w[i];
		sw[i] = sw[i - 1] + w[i];
	}
	stack < ll > st;
	for (int i = 1; i <= n; i++) {
		while (st.size() && h[st.top()] >= h[i]) st.pop();
		if (!st.size()) l[i] = 0;
		else l[i] = st.top();
		st.push(i);
	}
	stack < ll > st2;
	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		while (st2.size() && h[st2.top()] >= h[i]) st2.pop();
		if (!st2.size()) ans = max(ans, (sw[n] - sw[l[i]]) * h[i]);
		else ans = max(ans, (sw[st2.top() - 1] - sw[l[i]]) * h[i]);
		st2.push(i);
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
