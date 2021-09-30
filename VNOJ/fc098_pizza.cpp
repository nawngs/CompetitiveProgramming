#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

struct Node {
	ll end;
	ll cnt;
	ll a[26];
};

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

vector < Node > trie;

void add_node() {
	Node tam;
	tam.cnt = 0;
	tam.end = 0;
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
		trie[pre].cnt ++;
	}
	trie[pre].end ++;
	//cout << pre << " " << trie[pre].end << '\n';

} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	add_node();
	ll q;
	cin >> q;
	while (q --) {
		int x;
		string s;
		cin >> x >> s;
		if (x == 0) add_string(s);
		if (x == 1) {
			ll j = 0, cnt = 0, pre = 0;
			while (j < s.size()) {
				if (trie[pre].a[s[j] - 'a'] == -1) break;
				pre = trie[pre].a[s[j] - 'a'];
				if (trie[pre].end != 0) cnt += trie[pre].end;
				j ++;
			}
			cout << cnt << '\n';
		}
		if (x == 2) {
			ll j = 0, pre = 0;
			while (j < s.size()) {
				if (trie[pre].a[s[j] - 'a'] == -1) {
					pre = -1;
					break;
				}
				pre = trie[pre].a[s[j] - 'a'];
				j ++;
			}
			if (pre == -1) cout << 0 << '\n';
			else cout << trie[pre].cnt << '\n';
		}
	}
}
