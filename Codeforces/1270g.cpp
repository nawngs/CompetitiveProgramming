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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[1000003];

bool vs[1000003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vs[i] = false;
		a[i] = i - a[i];
	}
	int cur = 1;
	while (!vs[cur]) {
		vs[cur] = 1;
		cur = a[cur];
	}
	int temp = cur;
	vector < int > res;
	res.push_back(cur);
	cur = a[cur];
	while (cur != temp) {
		res.push_back(cur);
		cur = a[cur];
	}
	cout << res.size() << '\n';
	for (auto x : res) 
		cout << x << " ";
	cout << '\n';
}	

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
