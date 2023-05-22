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

ll n, a[203];

vector < ll > cur;

string s;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> s;
	s = ' ' + s;
	cur.clear();
	cur.push_back(0);
	for (int i = n; i >= 1; i--) {
		if (s[i] == '0') {
			vector < ll > tam = cur;
			for (auto x : tam) cur.push_back((x ^ a[i])); 
		}
		else {
			bool th = false;
			for (auto x : cur) {
				if (x == a[i]) {
					th = 1;
					break;
				}
			}
			if (!th) {
				cout << 1 << '\n';
				return ;
			}
		}
	}
	for (auto x : cur) {
		if (x == 0) {
			cout << 0 << '\n';
			return ;
		}
	}
	cout << 1 << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
