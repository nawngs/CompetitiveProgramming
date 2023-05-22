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

const string NAME = "sortvans";
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

int n, a[1003], b[1003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	a[n + 1] = -1;
	sort(b + 1, b + n + 1);
	stack < int > st;
	int pos = 1;
	int i = 1;
	while (pos <= n) {
		if (a[i] == b[pos]) {
			i ++;
			pos ++;
			continue;
		}
		if (st.size() && st.top() == b[pos]) {
			st.pop();
			pos ++;
			continue;
		}
		if (i == n + 1) {
			cout << "No" << '\n';
			return ;
		}
		st.push(a[i]);
		i ++;
	}
	cout << "Yes" << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
