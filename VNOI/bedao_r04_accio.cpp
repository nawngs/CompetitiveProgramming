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

string s, t;

queue < int > pos[30];

void sol() {
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) pos[s[i] - 'A'].push(i);
	queue < int > que;
	int i = 0;
	int ans = 0;
	while (i < s.size()) {
		if (!pos[s[i] - 'A'].size() || pos[s[i] - 'A'].front() != i) {
			i ++;
			continue;
		}
		while (que.size() && que.front() < i) que.pop();
		if (s[i] == t[i + que.size()]) {
			i ++;
			continue;
		}
		if (!pos[t[i + que.size()] - 'A'].size()) {
			cout << -1 << '\n';
			return ;
		}
		int tam = pos[t[i + que.size()] - 'A'].front();
		pos[t[i + que.size()] - 'A'].pop();
		ans += tam - i - que.size();
		que.push(tam);
		pos[s[i] - 'A'].pop();
	}
	cout << ans;
	
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
