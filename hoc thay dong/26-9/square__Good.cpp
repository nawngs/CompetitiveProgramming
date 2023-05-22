#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 1e3 + 5;

int n;
pi a[N];
map<pi, int> d;
ll ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("square.inp", "r") ){
        freopen("square.inp", "r", stdin);
        freopen("square.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
        d[{a[i].x, a[i].y}] ++;
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++)
    for (int j = i+1; j <= n; j ++){
        if ( a[i].y <= a[j].y ){
            int dx = a[j].x - a[i].x;
            int dy = a[j].y - a[i].y;
            if ( d[{a[i].x-dy, a[i].y+dx}] && d[{a[j].x-dy, a[j].y+dx}] )
                ans ++;
        }
        else{
            int dx = a[j].x - a[i].x;
            int dy = a[i].y - a[j].y;
            if ( d[{a[i].x+dy, a[i].y+dx}] && d[{a[j].x+dy, a[j].y+dx}] )
                ans ++;
        }
    }

    cout << ans;

    return 0;
}