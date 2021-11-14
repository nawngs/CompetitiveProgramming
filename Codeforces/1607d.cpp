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

ll n;

ll a[200005];

vector < ll > r, b;

string s;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	r.clear();
	b.clear();
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (a[i] < 1) {
			if (s[i] == 'B') {
				cout << "NO" << '\n';
				return ;
			}
			else a[i] = 1;
		}
		if (a[i] > n) {
			if (s[i] == 'R') {
				cout << "NO" << '\n';
				return ;
			}
			else a[i] = n;
		}
		if (s[i] == 'R') r.push_back(a[i]);
		else b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < b.size(); i++) {
		if (b[i] < i + 1) {
			cout << "NO" << '\n';
			return ;
		}
	}
	sort(r.begin(), r.end(), greater < ll >());
	for (int i = 0; i < r.size(); i++) {
		if (r[i] > n - i) {
			cout << "NO" << '\n';
			return ;
		}
	}
	cout << "YES" << '\n';

}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
