#include<bits/stdc++.h>
using namespace std;
const int base = 2e3;
const int MX = 4e3;

int n;
int da[MX+5][MX+5], db[MX+5][MX+5], dc[MX+5][MX+5];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        char type;
        int x, y, d;
        cin >> type >> x >> y >> d;

        if ( type == 'A' )
            da[y-d/2+base][x-d/2+base] = max(da[y-d/2+base][x-d/2+base], d);

        if ( type == 'B' ){
            db[y-d/2+base][x+base] = max(db[y-d/2+base][x+base], d/2);
            dc[y+d/2+base][x+base] = max(dc[y+d/2+base][x+base], d/2);
        }
    }

    for (int i = 0; i <= MX; i ++)
    for (int j = 0; j <= MX; j ++){
        if ( i ) da[i][j] = max(da[i][j], da[i-1][j] - 1);
        if ( j ) da[i][j] = max(da[i][j], da[i][j-1] - 1);
        if ( i && j ) da[i][j] = max(da[i][j], da[i-1][j-1] - 1);

        if ( i ){
            if ( j ) db[i][j] = max(db[i][j], db[i-1][j-1] - 1);
            db[i][j] = max(db[i][j], db[i-1][j+1] - 1);
            if ( i >= 2 ) db[i][j] = max(db[i][j], db[i-2][j] - 1);
        }
    }

    for (int i = MX; i >= 0; i --)
    for (int j = MX; j >= 0; j --){
        if ( j ) dc[i][j] = max(dc[i][j], dc[i+1][j-1] - 1);
        dc[i][j] = max(dc[i][j], dc[i+1][j+1] - 1);
        dc[i][j] = max(dc[i][j], dc[i+2][j] - 1);
    }

//    for (int i = 1; i >= -1; i --){
//    for (int j = -1; j <= 2; j ++)
//        cout << '(' << da[i+base][j+base] << ',' << db[i+base][j+base] << ',' << dc[i+base][j+base] << ')' << ' ';
//    cout << '\n';
//    }

    double ans = 0.0;

    for (int i = 1; i <= MX; i ++)
    for (int j = 1; j <= MX; j ++){
        if ( da[i][j] ) { ans += 1; continue; }

        if ( db[i][j] || db[i][j+1] ) ans += 0.25;
        if ( dc[i+1][j] || dc[i+1][j+1] ) ans += 0.25;
        if ( db[i][j] || dc[i+1][j] ) ans += 0.25;
        if ( db[i][j+1] || dc[i+1][j+1] ) ans += 0.25;
    }

    cout << fixed << setprecision(2) << ans;

    return 0;
}