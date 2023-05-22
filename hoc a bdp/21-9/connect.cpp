// #pragma GCC optimize ("O2")
// #include <bits/stdc++.h>

// #define ll long long
// #define ld long double
// #define fi first 
// #define se second
// #define pll pair < ll, ll >
// #define pii pair < int, int >
// #define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// using namespace std;

// const string NAME = "";
// const string NAME2 = "TEST";
// const ld ESP = 1e-9;
// const ll INF = 1e9 + 7;
// const ll LINF = 1E18;
// const ll nmax = 2e5;
// const ll MOD = 1e9 + 7;
// const ll base = 2309;
// const int dx[4] = {-1, 0, 0, 1};
// const int dy[4] = {0, -1, 1, 0};

// void fre() {
// 	string finp = NAME + ".inp";
// 	string fout = NAME + ".out";
// 	freopen(finp.c_str(), "r", stdin);
// 	freopen(fout.c_str(), "w", stdout);
// }

// struct Data {
// 	int i, j;
// 	bool moved_left, moved_right;
// 	Data (int _i, int _j, bool _left, bool _right) : i(_i), j(_j), moved_left(_left), moved_right(_right) {};
// };

// int n, m, a[503][503], f1[503][503], fm[503][503], f[503][503], d[503][503][2][2];

// queue < pii > que[9005];

// queue < Data > q[9005];

// void dijkstra_lr(int id, int dg) {
// 	for (int i = 0; i <= 9000; i++) 
// 		while (que[i].size()) que[i].pop();
// 	for (int i = 1; i <= n; i++)
// 		for (int j = 1; j <= m; j++) f[i][j] = INF;
// 	for (int i = 1; i <= n; i++) {
// 		f[i][id] = abs(a[i][id] - dg);
// 		que[f[i][id]].push({i, id});
// 	}
// 	for (int i = 0; i <= 9000; i++) {
// 		while (que[i].size()) {
// 			int x = que[i].front().fi;
// 			int y = que[i].front().se;
// 			que[i].pop();
// 			for (int chg = 0; chg < 4; chg++) {
// 				int newx = x + dx[chg];
// 				int newy = y + dy[chg];
// 				if (newx < 1 || newy < 1 || newx > n || newy > m || f[newx][newy] < i + abs(a[newx][newy] - dg)) continue;
// 				f[newx][newy] = i + abs(a[newx][newy] - dg);
// 				que[f[newx][newy]].push({newx, newy});
// 			}
// 		}
// 	}
// 	for (int i = 1; i <= n; i++)
// 		for (int j = 1; j <= m; j++) {
// 			if (id == 1) f1[i][j] = f[i][j];
// 			else fm[i][j] = f[i][j];
// 		}
// }

// void dijkstra(int dg) {
// 	for (int i = 0; i <= 9000; i++) 
// 		while (q[i].size()) q[i].pop();
// 	for (int i = 1; i <= n; i++)
// 		for (int j = 1; j <= m; j++) 
// 			for (int movel = 0; movel < 2; movel++)
// 				for (int mover = 0; mover < 2; mover++) d[i][j][movel][mover] = INF;
// 	for (int j = 1; j <= m; j++) {
// 		d[1][j][0][0] = abs(dg - a[1][j]);
// 		q[d[1][j][0][0]].push({1, j, 0, 0});
// 	}
// 	for (int i = 0; i <= 9000; i++) {
// 		while (q[i].size()) {
// 			int x = q[i].front().i;
// 			int y = q[i].front().j;
// 			bool moved_left = q[i].front().moved_left;
// 			bool moved_right = q[i].front().moved_right;
// 			q[i].pop();
// 			if (!moved_left) {
// 				if (d[x][y][1][moved_right] > i + f1[x][y]) {
// 					d[x][y][1][moved_right] = i + f1[x][y];
// 					q[d[x][y][1][moved_right]].push({x, y, 1, moved_right});
// 				}
// 			}
// 			if (!moved_right) {
// 				if (d[x][y][moved_left][1] > i + fm[x][y]) {
// 					d[x][y][moved_left][1] = i + fm[x][y];
// 					q[d[x][y][moved_left][1]].push({x, y, moved_left, 1});
// 				}
// 			}
// 			if (!moved_left && !moved_right) {
// 				if (d[x][y][1][1] > i + f1[x][y] + fm[x][y] - abs(dg - a[x][y])) {
// 					d[x][y][1][1] = i + f1[x][y] + fm[x][y] - abs(dg - a[x][y]);
// 					q[d[x][y][1][1]].push({x, y, 1, 1});
// 				}
// 			}
// 			for (int chg = 0; chg < 4; chg++) {
// 				int newx = x + dx[chg];
// 				int newy = y + dy[chg];
// 				if (newx < 1 || newy < 1 || newx > n || newy > m) continue;
// 				if (d[newx][newy][moved_left][moved_right] > i + abs(dg - a[newx][newy])) {
// 					d[newx][newy][moved_left][moved_right] = i + abs(dg - a[newx][newy]);
// 					q[d[newx][newy][moved_left][moved_right]].push({newx, newy, moved_left, moved_right});
// 				}
				
// 			}
// 		}
// 	}
// }

// int main() {
// 	//fast;
// 	cin >> n >> m;
// 	for (int i = 1; i <= n; i++) 
// 		for (int j = 1; j <= m; j++) {
// 			char c;
// 			cin >> c;
// 			a[i][j] = c - '0';
// 		}
// 	int res = INF;
// 	for (int s = 0; s <= 9; s++) {
// 		dijkstra_lr(1, s);
// 		dijkstra_lr(m, s);
// 		dijkstra(s);
// 		for (int j = 1; j <= m; j++) res = min(res, d[n][j][1][1]);
// 	}
// 	cout << res << '\n';
// }
#include<bits/stdc++.h>
#define simon "connect"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e2 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};
const int oo = 1e9;

int m, n, ans = oo;
int a[N][N], c[N][N], g[2][15][N][N], f[N][N][2][2];
queue<pi> q[10005];
struct cell{
    int d, x, y;
    bool operator > (const cell &a) const{
        return d > a.d;
    }
};

struct node{
    int x, y, tl, tr;
};
queue<node> heap[10005];

void dijkstra(int id, int s){
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        c[i][j] = abs(a[i][j] - s);

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        g[id][s][i][j] = oo;

    if ( !id )
        for (int i = 1; i <= m; i ++)
            g[id][s][i][1] = c[i][1], q[c[i][1]].push({i, 1});
    else
        for (int i = 1; i <= m; i ++)
            g[id][s][i][n] = c[i][n], q[c[i][n]].push({i, n});

    for (int d = 0; d <= 10000; d ++){
        while ( q[d].size() ){
            int x = q[d].front().fi, y = q[d].front().se;
            q[d].pop();
            if ( d != g[id][s][x][y] ) continue;
            for (int i = 0; i <= 3; i ++){
                int nx = x + row[i], ny = y + col[i];
                if ( nx < 1 || ny < 1 || nx > m || ny > n ) continue;
                if ( g[id][s][nx][ny] > d + c[nx][ny] ){
                    g[id][s][nx][ny] = d + c[nx][ny];
                    q[g[id][s][nx][ny]].push({nx, ny});
                }
            }
        }
    }
}

void anal(int s){
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        c[i][j] = abs(a[i][j] - s);

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
    for (int t = 0; t <= 1; t ++)
        f[i][j][t][t] = f[i][j][t][1-t] = oo;

    for (int i = 1; i <= n; i ++){
        f[1][i][0][0] = c[1][i];
        heap[c[1][i]].push({1, i, 0, 0});
    }

    for (int d = 0; d <= 10000; d ++){
        while ( heap[d].size() ){
            int x = heap[d].front().x, y = heap[d].front().y;
            int tl = heap[d].front().tl, tr = heap[d].front().tr;
            heap[d].pop();

            if ( d != f[x][y][tl][tr] ) continue;

            if ( !tl && f[x][y][1][tr] > f[x][y][tl][tr] + g[0][s][x][y] - c[x][y] ){
                f[x][y][1][tr] = f[x][y][tl][tr] + g[0][s][x][y] - c[x][y];
                heap[f[x][y][1][tr]].push({x, y, 1, tr});
            }

            if ( !tr && f[x][y][tl][1] > f[x][y][tl][tr] + g[1][s][x][y] - c[x][y] ){
                f[x][y][tl][1] = f[x][y][tl][tr] + g[1][s][x][y] - c[x][y];
                heap[f[x][y][tl][1]].push({x, y, tl, 1});
            }

            for (int i = 0; i <= 3; i ++){
                int nx = x + row[i], ny = y + col[i];
                if ( nx < 1 || ny < 1 || nx > m || ny > n ) continue;
                if ( f[nx][ny][tl][tr] > f[x][y][tl][tr] + c[nx][ny] ){
                    f[nx][ny][tl][tr] = f[x][y][tl][tr] + c[nx][ny];
                    heap[f[nx][ny][tl][tr]].push({nx, ny, tl, tr});
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++)
        ans = min(ans, f[m][i][1][1]);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        char x; cin >> x;
        a[i][j] = x - '0';
    }

    for (int s = 0; s <= 9; s ++)
        dijkstra(0, s), dijkstra(1, s);

    for (int s = 0; s <= 9; s ++)
        anal(s);

    cout << ans;

    return 0;
}
