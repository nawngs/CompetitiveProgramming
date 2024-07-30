// [+] dinhmanhhungwillwinioi2024
#include <bits/stdc++.h>
using namespace std;

int dp[2003][2003];

char rev[255];

string x, s;

inline char rv(const char &ch) {
	return rev[(int)ch];
}

string minimize(const string &x) {
	string ans;
	for (char c: x) {
		ans += c;
		while ((int)ans.size() >= 2 && rv(ans.back()) == ans.end()[-2])
			ans.pop_back(), ans.pop_back();
	}
	return ans;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	rev['A'] = 'a';
	rev['B'] = 'b';
	rev['a'] = 'A';
	rev['b'] = 'B';
	
	cin >> x >> s;
	string nx = minimize(x);
	string ns = minimize(s);
		
	int p1 = 0, p2 = 0;
	
	for (int i = 0; i < (int)nx.size(); i++) {
		for (int j = 0; j < (int)ns.size(); j++) {
			if (nx[i] != ns[j]) continue;
			dp[i][j] = ((i > 0 && j > 0) ? dp[i - 1][j - 1] : 0) + 1;
			if (dp[p1][p2] < dp[i][j]) 
				p1 = i, p2 = j;
		}
	}
	
	int len = dp[p1][p2];
	
	if (len == 0) {
		cout << nx << s;
		reverse(ns.begin(), ns.end());
		for (char c: ns) cout << rv(c);
		return 0;
	}
	
	cout << nx.substr(0, p1 - len + 1);
	for (int i = p2 - len; i >= 0; i--) cout << rv(ns[i]);
	cout << s;
	for (int i = (int)ns.size() - 1; i > p2; i--) cout << rv(ns[i]);
	cout << nx.substr(p1 + 1);
	
	return 0;
}
