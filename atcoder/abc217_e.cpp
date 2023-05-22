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

int q;

void sol() {
	cin >> q;
	queue < int > q1;
	priority_queue < int, vector < int > , greater < int > > q2;
	while (q --) {
		int type;
		cin >> type;
		if (type == 1) {
			int val;
			cin >> val;
			q1.push(val);
		}
		if (type == 2) {
			if (q2.empty()) {
				cout << q1.front() << '\n';
				q1.pop();
			}
			else {
				cout << q2.top() << "\n";
				q2.pop();
			}
		}
		if (type == 3) {
			while (q1.size()) {
				q2.push(q1.front());
				q1.pop();
			}
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
