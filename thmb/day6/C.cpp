#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Node {
	bool end;
	int a[26];
};

const ll MOD = 1e9 + 7;
ll n, dp[100005];

string s;

vector < Node > trie;

void add_node() {
	Node tam;
	tam.end = false;
	for (int i = 0; i < 26; i++) {
		tam.a[i] = -1;
	}
	//cout << 123 << '\n';
	trie.push_back(tam);
}

void add_string(string s) {
	int pre = 0;
	for (int i = 0; i < s.size(); i++) {
		if (trie[pre].a[s[i] - 'a'] == -1) {
			add_node();
			trie[pre].a[s[i] - 'a'] = trie.size() - 1;

		} 
		pre = trie[pre].a[s[i] - 'a'];
	}
	trie[pre].end = true;
} 

int main() {
	cin >> n;
	add_node();
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		add_string(str);
	}
	cin >> s;
	s = ' ' + s;
	dp[0] = 1;
	for (int i = 1; i < s.size(); i++) {
		int pre = 0;
		int j = i;
		while (j < s.size()) {
			if (trie[pre].a[s[j] - 'a'] == -1) break;
			pre = trie[pre].a[s[j] - 'a'];
			if (trie[pre].end) {
				dp[j] += dp[i - 1];
				dp[j] %= MOD;
			} 
			j ++;
		}
	}
	cout << dp[s.size() - 1];
}
