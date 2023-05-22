#include <bits/stdc++.h>

using namespace std;

int n, m, num[10003], low[10003], timer = 0, res = 0;

vector < int > adj[10003];

stack  < int > st;

bool deleted[10003];

void dfs(int u) {
    num[u] = low[u] = ++ timer;
    st.push(u);
    for (auto v : adj[u]) {
        if (deleted[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        res ++;
        while (st.top() != u) {
            deleted[st.top()] = 1;
            st.pop();
        }
        deleted[st.top()] = 1;
        st.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
    cout << res;
}
