#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

int n, m, low[1003], num[1003], timer = 0, id[1003], ID = 0, deg[1003];

bool deleted[1003];

vector < pii > edges;

vector < int > adj[1003];

stack < int > st;

void dfs(int u) {
    num[u] = low[u] = ++ timer;
    st.push(u);
    for (auto v : adj[u]) {
        if (deleted[v]) continue;
        if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (num[u] == low[u]) {
        ID ++;
        while (st.top() != u) {
            id[st.top()] = ID;
            deleted[st.top()] = 1;
            st.pop();
        }
        id[u] = ID, deleted[u] = 1;
        st.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u, v});
    }
    for (int i = 1; i <= n; i++)
        if (num[i] == 0) dfs(i);
    for (auto e : edges)
        if (id[e.fi] != id[e.se]) deg[id[e.se]] ++;
    int res = 0;
    for (int i = 1; i <= ID; i++)
        if (!deg[i]) res ++;
    cout << res;
}
