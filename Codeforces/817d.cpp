#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[N + 3], l[N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	stack < int > st;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		while (st.size() && a[st.top()] >= a[i]) st.pop();
		l[i] = 1;
		if (st.size()) l[i] += st.top();
		st.push(i);
	}
	while (st.size()) st.pop();
	for (int i = n; i >= 1; i--) {
		while (st.size() && a[st.top()] > a[i]) st.pop();
		int r = n;
		if (st.size()) r = st.top() - 1;
		res -= 1ll * a[i] * (r - i + 1) * (i - l[i] + 1);
		st.push(i);
	}
	while (st.size()) st.pop();
	for (int i = 1; i <= n; i++) {
		while (st.size() && a[st.top()] <= a[i]) st.pop();
		l[i] = 1;
		if (st.size()) l[i] += st.top();
		st.push(i);
	}
	while (st.size()) st.pop();
	for (int i = n; i >= 1; i--) {
		while (st.size() && a[st.top()] < a[i]) st.pop();
		int r = n;
		if (st.size()) r = st.top() - 1;
		res += 1ll * a[i] * (r - i + 1) * (i - l[i] + 1);
		st.push(i);
	}
	cout << res;
}