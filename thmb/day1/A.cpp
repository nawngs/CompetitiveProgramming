    #include <bits/stdc++.h>

    #define N 100005

    using namespace std;

    int n, m;
    vector<int> g[N];

    int num;
    int dep[N], pre[N];
    pair<int, int> rev[N][2];
    vector<int> st;

    void dfs(int u, int par, int d) {
        pre[u] = par;
        dep[u] = d;
        rev[u][0] = rev[u][1] = {n + 1, 0};
        for (int v : g[u]) {
            if (v != par) {
                if (dep[v]) {
                    if ((dep[u] - dep[v]) % 2 == 1) {
                        vector<int> path;
                        while (u != v) {
                            path.push_back(u);
                            u = pre[u];
                        }
                        path.push_back(v);
                        cout << "YES\n" << (path.size()) << "\n";
                        for (int x : path) {
                            cout << x << " ";
                        }
                        exit(0);
                    } 
                    else {
                        if (dep[v] < rev[u][0].first) {
                            rev[u][1] = rev[u][0];
                            rev[u][0] = {dep[v], v};
                        } 
                        else if (dep[v] < rev[u][1].first) {
                            rev[u][1] = {dep[v], v};
                        }
                    }
                } 
                else {
                    dfs(v, u, d + 1);
                    if (rev[v][0].first < rev[u][0].first) {
                        rev[u][1] = rev[u][0];
                        rev[u][0] = {rev[v][0].first, v};
                    } 
                    else if (dep[v] < rev[u][1].first) {
                        rev[u][1] = {rev[v][0].first, v};
                    }
                }
            }
        }
        if (rev[u][0].first < dep[u] && rev[u][1].first < dep[u]) {
            vector<int> path1, path2;
            int v1, v2;
            for (v1 = rev[u][0].second; dep[v1] != rev[u][0].first; v1 = rev[v1][0].second) {
                path1.push_back(v1);
            }
            for (v2 = rev[u][1].second; dep[v2] != rev[u][1].first; v2 = rev[v2][0].second) {
                path2.push_back(v2);
            }
            if (v1 != v2) {
                while (v2 != v1) {
                    path2.push_back(v2);
                    v2 = pre[v2];
                }
            }
            path1.push_back(v1);
            cout << "YES\n";
            cout << (1 + path1.size() + path2.size()) << "\n" << u << " ";
            for (int v : path1) {
                cout << v << " ";
            }
            reverse(path2.begin(), path2.end());
            for (int v : path2) {
                cout << v << " ";
            }
            exit(0);
        }
    }

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (dep[i] == 0) {
                dfs(i, 0, 1);
            }
        }
        cout << "NO";
    }