//link:https://oj.vnoi.info/problem/kcollect
#include <bits/stdc++.h>

using namespace std;

int n, m, a[10005], num[10005], low[10005], scc = 0, timeDFS = 0, num_scc[10005], dp[10005], sum_scc[10005], ans = 0;

string s[105];

vector < int > adj[10005], adj2[10005];

stack < int > st;

int getid(int i, int j){
	return (i - 1) * n + j;
}

void dfs(int u) {
	//cout << u << '\n';
	num[u] = low[u] = ++ timeDFS;
	st.push(u);
	for (auto v : adj[u]){
		//cout << u << " " << v << '\n';
		if (num_scc[v] != -1) continue;
		if(!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	//cout << u << " " << low[u] << " " << num[u] << '\n';
	if (low[u] == num[u]) {
		scc ++;
		int sum = 0;
		while(1) {
			num_scc[st.top()] = scc;
			sum += a[st.top()];
			if (st.top() == u) {
				st.pop();
				break ;
			}
			st.pop();
		}
		sum_scc[scc] = sum;
	}
}

void dfs2(int u) {
	if(dp[u] > -1) return ;
	dp[u] = sum_scc[u];
	for (auto v : adj2[u]) {
		dfs2(v);
		dp[u] = max(dp[u], dp[v] + sum_scc[u]);
	}
}

bool valid(int i, int j) {
	return (i >= 1 && i <= m && j >= 1 && j <= n && s[i][j] != '#');
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(s[i][j] == '#') continue ;
			int id = getid(i, j);
			if ('0' <= s[i][j] && s[i][j] <= '9') a[id] = s[i][j] - '0';
			else a[id] = 0;
 			if (valid(i + 1, j)){
 				adj[id].push_back(getid(i + 1, j));
 				//cout << id << " " << getid(i + 1, j) << '\n';
 			}
			if (valid(i, j + 1)) adj[id].push_back(getid(i, j + 1));
			if (s[i][j] == 'W' && valid(i, j - 1)) adj[id].push_back(getid(i, j - 1));
			if (s[i][j] == 'N' && valid(i - 1, j)) adj[id].push_back(getid(i - 1, j));
		}
	}
	//cout << 123123 << '\n';
	memset(num_scc, 255, sizeof(num_scc));
	for (int i = 1; i <= m * n; i++) if (!num[i]) dfs(i); 
	//out << scc << '\n';
	for (int i = 1; i <= n * m; i++) {
		//cout << i << " " << num_scc[i] << '\n';
		for (auto v : adj[i]) {
			if (num_scc[i] != num_scc[v]) adj2[num_scc[i]].push_back(num_scc[v]);
		}
	}
	memset(dp, 255, sizeof(dp));
	dfs2(num_scc[1]);
	cout << dp[num_scc[1]];
}