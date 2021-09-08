//link:https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2
#include <bits/stdc++.h>

using namespace std;

int t, connect[35][35];

vector < int > adj[35];

void bfs(int pos) {
	queue < int > q;
	connect[pos][pos] = 0;
	q.push(pos);
	while (q.size()) {
		int tam = q.front();
		q.pop();
		for (auto v : adj[tam]) {
			if (connect[pos][v] == -1) {
				connect[pos][v] = connect[pos][tam] + 1;
				q.push(v);
			}
		}
	}
}

int sol() {
	string s;
	int k;
	memset(connect, 255, sizeof(connect));
	for (int i = 0; i <= 30; i++) adj[i].clear();
	cin >> s >> k;
	for (int i = 1; i <= k; i++) {
		string x;
		cin >> x;
		adj[x[0] - 'A'].push_back(x[1] - 'A');
	}	
	int ans = 1e9 + 7;
	for (int i = 0; i <= 30; i++) bfs(i);
	for (int i = 0; i < 30; i++) {
		if (i + 'A' > 'Z') break;
		int sum = 0;
		for (int j = 0; j < s.size(); j++) {
			if (connect[s[j] - 'A'][i] == -1) {
				sum = 1e9 + 7;
				break;
			}
			sum += connect[s[j] - 'A'][i];
		}
		ans = min(ans, sum);
	}
	if (ans == 1e9 + 7) return -1;
	else return ans;
}

int main() {
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int tam = sol();
		cout << "Case #" << test << ": " << tam << '\n';
	}
}