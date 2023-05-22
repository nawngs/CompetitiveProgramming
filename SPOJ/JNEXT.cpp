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

int n, a[1000003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	stack < int > st1, st2;
	for (int i = n; i >= 1; i--) {
		while (st1.size() && st1.top() > a[i]) {
			st2.push(st1.top());
			st1.pop();
		}
		if (!st2.size()) {
			st1.push(a[i]);
			continue;
		}
		for (int j = 1; j < i; j++) cout << a[j];
		cout << st2.top();
		st2.pop();
		st2.push(a[i]);
		while (st1.size()) {
			st2.push(st1.top());
			st1.pop();
		}
		while (st2.size()) {
			cout << st2.top();
			st2.pop();
		}
		cout << '\n';
		return ;
	}
	cout << -1 << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
