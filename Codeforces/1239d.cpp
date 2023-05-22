#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

int n, m, low[1000003], num[1000003], id_scc[1000003], scc = 0, timeDFS = 0, deg[1000003], cnt[1000003];

vector < int > adj[1000003];

stack < int > st;

void dfs(int u) {
    low[u] = num[u] = ++ timeDFS; st.push(u);
    for (auto v : adj[u]) {
        if (id_scc[v] != 0) continue;
        if (num[v] == -1) {
            dfs(v); low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        scc ++;
        cnt[scc] = 1;
        while (st.top() != u) {
            cnt[scc] ++;
            id_scc[st.top()] = scc;
            st.pop();
        }
        id_scc[st.top()] = scc;
        st.pop();
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        id_scc[i] = 0;
        deg[i] = 0;
        low[i] = num[i] = -1;
    }
    scc = 0;
    vector < pii > edges;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if (u != v) adj[u].push_back(v);
        edges.push_back({u, v});
    }
    timeDFS = 0;
    for (int i = 1; i <= n; i++)
        if (num[i] == -1) dfs(i);
    if (scc == 1) {
        cout << "NO" << '\n';
        return ;
    }
    cout << "YES" << '\n';
    for (auto x : edges)
        if (id_scc[x.fi] != id_scc[x.se]) deg[id_scc[x.fi]] ++;
    for (int i = 1; i <= scc; i++) {
        if (deg[i] == 0) {
            cout << cnt[i] << " " << n - cnt[i] << '\n';
            for (int j = 1; j <= n; j++) if (id_scc[j] == i) cout << j << " ";
            cout << '\n';
            for (int j = 1; j <= n; j++) if (id_scc[j] != i) cout << j << " ";
            cout << '\n';
            return ;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}
