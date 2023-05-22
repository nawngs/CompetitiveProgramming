#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "TriSeq";
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

ll n, dem = 0, tt;
ull s;
vector < ll > ques, res, f;

bool check (ll x, ll y, ll z) {
	if (x + y <= z) return false;
	if (y + z <= x) return false;
	if (x + z <= y) return false;
	return true;
}

bool check(vector < ll > a) {
	for (int i = 0; i < a.size(); i++)
		for (int j = i + 1; j < a.size(); j++)
			for (int k = j + 1; k < a.size(); k++) if (!check(a[i], a[j], a[k])) return false;
	return true;
}

void back_track(int pos) {
	if (pos == n + 1) {
		if (check(f)) {
			for (auto x : f) cout << x << " ";
			cout << '\n';
			dem ++;
			if (dem == (ll)s) res = f;
			if (f == ques) tt = dem;
		}
		return ;
	}
	for (int i = 1; i <= n; i++) {
		f.push_back(i);
		back_track(pos + 1);
		f.pop_back();
	}
}

void solve1() {
	back_track(1);
	cout << dem << '\n';
	for (auto x : res) cout << x << ' ';
	cout << '\n';
	cout << tt << '\n';
}

ull dp[20], res2[20];

void solve2() {
	ull res = 1;
	for (int i = 1; i <= n; i++) res *= n;
	cout << res << '\n';
	dp[0] = 1;
	for (int i = 1; i < n; i++) dp[i] = dp[i - 1] * n;
	ull tam = 1;
	for (int i = 1; i <= n; i++) {
		ull pos;
		for (int j = 1; j <= n; j++) {
			if (tam + j * dp[n - i] >  s) {
				pos = j;
				break;
			}
		}
		tam += (ull) (pos - 1) * dp[n - i];
		res2[i] = pos;
	}	
	for (int i = 1; i <= n; i++) cout << res2[i] << ' ';
	cout << '\n';
	ull cnt = 0;
	for (int i = 0; i < ques.size(); i++) cnt += (ull)(ques[i] - 1) * dp[n - i - 1];
	cout << cnt + 1 << '\n';
 }

void sol() {
	cin  >> n >> s;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		ques.push_back(x);
	}
	if (n <= 8) solve1();
	else solve2();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
