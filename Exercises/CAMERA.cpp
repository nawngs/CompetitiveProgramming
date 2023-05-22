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

const string NAME = "camera";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100003], maxl[100003], maxr[100003], res[100003];

string s;

void readINP() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> s;
	s = ' ' + s;
	
}

void init() {
	stack < int > st;
	a[0] = a[n + 1] = INF;
	st.push(0);
	for (int i = 1; i <= n; i++) {
		while (st.size() && a[st.top()] <= a[i]) st.pop();
		if (st.size()) maxr[st.top()] ++;
		st.push(i);
	}
	while (st.size()) st.pop();
	st.push(n + 1);
	for (int i = n; i >= 1; i--) {
		while (st.size() && a[st.top()] <= a[i]) st.pop();
		if (st.size()) {
			//cout << i << " " << st.top() << '\n';
			maxl[st.top()] ++;
		}
		st.push(i);
	}
}

void solve() {
	ll tam = maxr[0];
	for (int i = 1; i <= n; i++) {
		tam += maxr[i] - 1;
		if (s[i] == 'E') res[i] = tam;
	}
	tam = maxl[n + 1];
	for (int i = n; i >= 1; i--) {
		tam += maxl[i] - 1;
		if (s[i] == 'W') res[i] = tam;
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}

int main() {
	fast;
	fre();
	readINP();
	init();
	solve();
}
