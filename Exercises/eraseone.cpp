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

const string NAME = "eraseone";
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

int n, a[200003], cnt_end[200003], cnt_start[200003], max_end[200003], max_start[200003];

int calc(vector < int > c) {
	int dem = 1, res = 1;
	for (int i = 1; i < c.size(); i++) {
		if (c[i] >= c[i - 1]) dem ++;
		else {
			res = max(res, dem);
			dem = 1;
		}
	}
	res = max(res, dem);
	return res;
}

void sol1() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		vector < int > temp;
		temp.clear();
		for (int j = 1; j < i; j++) temp.push_back(a[j]);
		for (int j = i + 1; j <= n; j++) temp.push_back(a[j]);
		ans = max(ans, calc(temp));
	}
	cout << ans << '\n';
}

void sol2() {
	cnt_end[1] = 1;
	max_end[1] = 1;
	for (int i = 2; i <= n; i++) {
		cnt_end[i] = 1 + (a[i] >= a[i - 1]) * cnt_end[i - 1];
		max_end[i] = max(max_end[i - 1], cnt_end[i]);
	} 
	cnt_start[n] = 1;
	max_start[n] = 1;
	for (int i = n - 1; i >= 1; i--) {
		cnt_start[i] = 1 + (a[i] <= a[i + 1]) * cnt_start[i + 1];
		max_start[i] = max(max_start[i + 1], cnt_start[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, max(max_end[i - 1], max_start[i + 1]));
		if (a[i + 1] >= a[i - 1]) ans = max(ans, cnt_end[i - 1] + cnt_start[i + 1]);
	} 
	cout << ans << '\n';	
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 1000) sol1();
	else sol2();
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
