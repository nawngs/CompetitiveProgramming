#include <bits/stdc++.h>

using namespace std;

struct Node {
	bool end;
	int a[26];
};


int n;

string s;

vector < Node > trie;

vector < int > f;

void add_node() {
	//cout << 131 << '\n';
	Node tam;
	tam.end = false;
	for (int i = 0; i < 26; i++) {
		tam.a[i] = -1;
	}
	//cout << 123 << '\n';
	trie.push_back(tam);
	f.push_back(0);
}

void add_string(string s) {
	int pre = 0, maxa = 0;
	for (int i = 0; i < s.size(); i++) {
		//cout << s[i] << '\n';
		maxa = max(maxa, f[pre]);
		if (trie[pre].a[s[i] - 'a'] == -1) {
			add_node();
			trie[pre].a[s[i] - 'a'] = trie.size() - 1;

		} 
		pre = trie[pre].a[s[i] - 'a'];

	}
	f[pre] = maxa + 1;
	trie[pre].end = true;
} 

int main() {
	cin >> n;
	add_node();
	for (int i = 1; i <= n; i++) {
		cin >> s;
		add_string(s);
	}
	int ans = 0;
	for (int i = 0; i < f.size(); i++) ans = max(ans, f[i]);
	cout << ans;
}