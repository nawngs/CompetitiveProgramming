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

const string NAME = "abba";
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

string s1, s2;

map < string, bool > mp;

bool check(string s) {
	if (mp.find(s) != mp.end()) return mp[s];
	bool th = false;
	if (s.back() == 'A') {
		string news = s;
		news.erase(news.size() - 1, 1);
		th = check(news);
	}
	if (s[0] == 'B') {
		string news = s;
		reverse(news.begin(), news.end());
		news.erase(news.size() - 1, 1);
		th |= check(news);
	}
	mp[s] = th;
	return th;
}

void sol() {
	mp.clear();
	cin >> s1 >> s2;
	mp[s1] = 1;
	mp[""] = 0;
	bool th = check(s2);
	cout << (th ? "Yes" : "No") << '\n';
}

int main() {
	fast;
	fre();
	int t = 3;
	//cin >> t;
	while (t --) sol();
}
