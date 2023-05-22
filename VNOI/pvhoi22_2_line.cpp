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

int n, m, k, vt[12];

string s;

vector < string > res;

bool check[102][102];

vector < int > tam;

void back_track(int pos, int pre) {
	if (pos == n + 1) {
		s =  "";
		for (auto x : tam) s = s + (char) ('0' + x);
		res.push_back(s);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vt[i] != 0 || check[i][pre]) continue;
		vt[i] = pos;
		tam.push_back(i);
		back_track(pos + 1, i);
		tam.pop_back();
		vt[i] = 0;	
	}
}

void sol1() {
	memset(vt, 0, sizeof(vt));
	back_track(1, 0);
	k --;
	k %= res.size();
	sort(res.begin(), res.end());
	for (int i = 0; i < res[k].size(); i++) cout << res[k][i] << " ";
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		check[x][y] = check[y][x] = true;
	}
	if (n <= 10) sol1();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
