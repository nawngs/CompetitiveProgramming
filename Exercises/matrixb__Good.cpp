#include<bits/stdc++.h>
using namespace std;
const int N = 3e2 + 5;
const int oo = 1e9;

int m, n;
int a[N][N], col[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        if ( !a[i][j] ) a[i][j] = -1;
        col[i][j] = col[i-1][j] + a[i][j];
    }

    int ans = -oo;
    for (int len = 1; len <= m; len ++){
        for (int i = 1; i <= m-len+1; i ++){
            if ( len > 1 )
                ans = max(ans, col[i+len-1][1] - col[i-1][1]);
            int s = a[i][1] + a[i+len-1][1];
            int mx = col[i+len-1][1] - col[i-1][1] - s;

            for (int j = 2; j <= n; j ++){
                if ( len > 1 ) ans = max(ans, col[i+len-1][j] - col[i-1][j]);
                ans = max(ans, col[i+len-1][j] - col[i-1][j] + s + mx);
                s += a[i][j] + a[i+len-1][j];
                mx = max(mx, col[i+len-1][j] - col[i-1][j] - s);
            }
        }
    }

    cout << ans;

    return 0;
}