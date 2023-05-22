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

const string NAME = "Unique";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int x, cnt[55], trace[55];

void create() {
	for (int i = 1; i <= 50; i++) cnt[i] = INF;
	cnt[0] = 0;
	for (int i = 9; i >= 1; i--) {
		for (int j = 50; j >= i; j--) {
			if (cnt[j] >= cnt[j - i] + 1) {
				cnt[j] = cnt[j - i] + 1;
				trace[j] = i;
			} 

		}
	}
}

void sol() {
	cin >> x;
	if (x > 45) {
		cout << -1 << '\n';
		return ;
	}
	vector < int > res;
	while (x != 0) {
		res.push_back(trace[x]);
		x -= trace[x];
	}
	sort(res.begin(), res.end());
	for (auto x : res) cout << x;
	cout << '\n';
}

int main() {
	fast;
	fre();
	create();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
