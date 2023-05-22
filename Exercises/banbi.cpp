#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define pii pair < int, int >
#define fi first
#define se second
#define ll long long
 
using namespace std;
 
int n, m, ans = 0, type, pos;
 
int s[1003][1003][4];
 
//1 di len
//2 di sang phai
//3 di sang trai
//4 di xuong
 
string a[1003];
 
void readINP() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
}
 
void init() {
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= m; i++) s[1][i][1] = s[n][i][4] = 1;
    for(int i = 1; i <= n; i++) s[i][1][3] = s[i][m][2] = 1;
}
 
int change_direction(int direction, char c) {
    if (c == '0') return direction;
    if (c == '1') {
        if (direction == 1) return 2;
        if (direction == 2) return 4;
        if (direction == 3) return 1;
        if (direction == 4) return 3;
    }
    if (c == '2') {
        if (direction == 1) return 3;
        if (direction == 2) return 1;
        if (direction == 3) return 4;
        if (direction == 4) return 2;
    }
}
 
pii newpos (int i, int j, int direction) {
    if (direction == 1) return {i - 1, j};
    if (direction == 2) return {i, j + 1};
    if (direction == 3) return {i, j - 1};
    if (direction == 4) return {i + 1, j};
}
 
int dequy(int i, int j, int direction) {
    int new_direction = change_direction(direction, a[i][j]);
    //cout << i << " " << j << " " << new_direction << '\n';
    if (s[i][j][new_direction] != 0) return s[i][j][new_direction];
    pii tam = newpos(i, j, new_direction);
    s[i][j][new_direction] = dequy(tam.fi, tam.se, new_direction) + 1;
    return s[i][j][new_direction];
}
 
void calc1() {
    for (int i = 1; i <= n; i++) {
        int tam = dequy(i, 1, 2);
        if (tam > ans) {
            ans = tam;
            type = 1;
            pos = i;
        }
    }
}
 
void calc2() {
    for (int i = 1; i <= n; i++) {
        int tam = dequy(i, m, 3);
        if (tam > ans) {
            ans = tam;
            type = 2;
            pos = i;
        }
    }
}
 
void calc3() {
    for (int i = 1; i <= m; i++) {
        int tam = dequy(1, i, 4);
        if (tam > ans) {
            ans = tam;
            type = 3;
            pos = i;
        }
    }
}
 
void calc4() {
    for (int i = 1; i <= m; i++) {
        int tam = dequy(n, i, 1);
        if (tam > ans) {
            ans = tam;
            type = 4;
            pos = i;
        }
    }
}
 
void solve() {
    calc1();
    calc2();
    calc3();
    calc4();
}
 
void printans() {
    cout << type << " " << pos << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("banbi.inp", "r", stdin);
    freopen("banbi.out", "w", stdout);
    readINP();
    init();
    solve();
    //cout << s[1][28][4] << " " << s[4][44][1] << '\n';
    printans();
}
 
/*
5 4
0020
0000
0000
0000
0000
*/