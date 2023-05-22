#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

string ans;

char ask(int l, int r) {
	cout << "? ";
	for (int i = l; i <= r; i++) cout << i << " ";
	cout << '\n';
	cin >> ans;
	return ans[0];
}

char ask(int id, const vector < int > &rem) {
	cout << "? " << id << " ";
	for (auto x : rem) cout << x << " ";
	cout << '\n';
	cin >> ans;
	return ans[0];
}

char ask(int id, const vector < int > &r, const vector < int > &b) {
	cout << "? " << id << " ";
	for (auto x : b) cout << x << " ";
	for (auto x : r) cout << x << " ";
	cout << '\n';
	cin >> ans;
	return ans[0];
}

int n;

char res[103];

int main() {
	//fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	char pre = ask(1, n);
	for (int t = 2; t <= n; t++) {
		char cur = ask(t, t + n - 1);
		if (cur != pre) {
			vector < int > same;
			for (int i = t; i < t + n - 1; i++) same.push_back(i);
			vector < int > red, blue;
			for (int i = 1; i <= 2 * n; i++) {
				if (t <= i && i <= t + n - 2) continue;
				res[i] = ask(i, same);
				if (res[i] == 'R' && sz(red) < n / 2) red.push_back(i);
				if (res[i] == 'B' && sz(blue) < n / 2) blue.push_back(i);
			}
			for (int i = t; i <= t + n - 2; i++) 
				res[i] = ask(i, red, blue);
			cout << "! ";
			for (int i = 1; i <= 2 * n; i++) cout << res[i];
			return 0;
		}
	}
}