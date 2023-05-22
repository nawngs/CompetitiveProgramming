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

int n;

string s;

void sol() {
	cin >> n >> s;
	s = ' ' + s;
	deque < int > dq;
	dq.push_back(n);
	for (int i = n; i >= 1; i--) {
		if (s[i] == 'L') dq.push_back(i - 1);
		else dq.push_front(i - 1);
	}
	while (dq.size()) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
