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

const string NAME = "etrue";
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

int n;

string s, tam;

bool th[203];

vector < pii > pos_arr;

vector < string > res;

map < string, int > f;

void back_track(int pos) {
	if (pos == pos_arr.size()) {
		string new_s = "";
		int dem = 0;
		for (int i = 1; i <= n; ++i) {
			if (th[i] == false) {
				new_s += s[i];
				if (s[i] == '(') dem ++;
				if (s[i] == ')') dem --;
				if (dem < 0) return ;
			}
		}
		if (dem == 0 && f[new_s] == 0) res.push_back(new_s);
		f[new_s] ++;
		return ;
	}
	for (int i = 0; i <= 1; ++i) {
		th[pos_arr[pos].fi] = i;
		th[pos_arr[pos].se] = i;
		back_track(pos + 1);
		th[pos_arr[pos].fi] = 0;
		th[pos_arr[pos].se] = 0;

	}
}

void sol() {
	cin >> s;
	f[s] ++;
	n = s.size();
	s = ' ' + s;
	stack < int > open;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') open.push(i);
		if (s[i] == ')') {
			pos_arr.push_back({open.top(), i});
			open.pop();
		}
	}
	back_track(0);
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
