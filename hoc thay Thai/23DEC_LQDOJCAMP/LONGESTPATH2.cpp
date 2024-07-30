#include <bits/stdc++.h>

using namespace std;
#define task "code"
#define ll long long

const int N = 1e3 + 3;

int n, m, a[N], p[N], ans[N][N], s;
vector<int> vec;
bool vis[N];

void dfs (int u) {
    vis[u] = 1;
    vec.push_back(u);
    if (!vis[p[u]]) dfs(p[u]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> p[i];

    int x = 0;
    for (int z = 1; z <= n; ++ z) {
        if (p[p[z]] == z) return cout << -1, 0;
        if (!vis[z]) {
            vec.clear();
            dfs(z);
            int str = 0;
            s += vec.size() * m;
            x = s;
            for (int j = m; j >= 1; -- j) {
                for (int i = 0; i < vec.size(); ++ i, x --) {
                    ans[vec[str]][j] = x;
                    str = (str + 1) % vec.size();
                }
                str = (str ? str - 1 : vec.size()-1);
            }
        }
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
