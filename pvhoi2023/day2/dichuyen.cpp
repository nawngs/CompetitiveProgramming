#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int INF = 1E9 + 7;
const int di[] = {-1, 0, 0, 1, 0};
const int dj[] = {0, -1, 1, 0, 0};

int n, m, sze, d[180][180][305][2];

char a[180][180];

string s;

pii start, finish;

struct Data {
    int val, i, j, sz, del;
    Data (int _val, int _i, int _j, int _sz, int _del) {
        val = _val, i = _i, j = _j, sz = _sz, del = _del;
    }
};

struct Compare {
    bool operator() (const Data &x, const Data &y) {
        return x.val > y.val;
    }
};

bool minimize(int &x, int y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

int direction(char c) {
    if (c == 'U') return 0;
    if (c == 'L') return 1;
    if (c == 'R') return 2;
    if (c == 'D') return 3;
    return 4;
}

void dijkstra() {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    for (int sz = 0; sz <= sze + 1; sz++)
    for (int del = 0; del < 2; del++)
        d[i][j][sz][del] = INF;
    d[start.fi][start.se][1][0] = 0;
    priority_queue < Data, vector < Data >, Compare > heap;
    heap.push(Data(0, start.fi, start.se, 1, 0));
    while (!heap.empty()) {
        auto x = heap.top(); heap.pop();
        int chg = x.val, i = x.i, j = x.j, sz = x.sz, del = x.del;
        if (chg != d[i][j][sz][del]) continue;
        if (sz <= sze && minimize(d[i][j][sz + 1][1], chg + (del == 0)))
            heap.push(Data(d[i][j][sz + 1][1], i, j, sz + 1, 1));
        for (int p = 0; p < 4; p++) {
            int newi = i + di[p], newj = j + dj[p];
            if (newi < 1 || newj < 1 || newi > n || newj > m || a[newi][newj] == '#') continue;
            if (minimize(d[newi][newj][sz][0], chg + 1))
                heap.push(Data(chg + 1, newi, newj, sz, 0));
        }
        if (sz <= sze) {
            int p = direction(s[sz]);
            int newi = i + di[p], newj = j + dj[p];
            if (newi < 1 || newj < 1 || newi > n || newj > m || a[newi][newj] == '#') {
                if (minimize(d[i][j][sz + 1][0], chg))
                    heap.push(Data(chg, i, j, sz + 1, 0));
            }
            else if (minimize(d[newi][newj][sz + 1][0], chg))
                heap.push(Data(chg, newi, newj, sz + 1, 0));
            for (int p = 0; p < 4; p++) {
                int newi = i + di[p], newj = j + dj[p];
                if (newi < 1 || newj < 1 || newi > n || newj > m || a[newi][newj] == '#') {
                    if (minimize(d[i][j][sz + 1][0], chg + 1))
                        heap.push(Data(chg + 1, i, j, sz + 1, 0));
                }
                else if (minimize(d[newi][newj][sz + 1][0], chg + 1))
                    heap.push(Data(chg + 1, newi, newj, sz + 1, 0));
            }
        }
    }
    int res = min(d[finish.fi][finish.se][sze + 1][0], d[finish.fi][finish.se][sze + 1][1]);
    if (res == INF) cout << -1 << '\n';
    else cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("dichuyen.inp", "r", stdin);
    freopen("dichuyen.out", "w", stdout);
    int O; cin >> O;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') start = {i, j};
            if (a[i][j] == 'E') finish = {i, j};
        }
    cin >> s; sze = s.size(); s = ' ' + s;
    dijkstra();
}
