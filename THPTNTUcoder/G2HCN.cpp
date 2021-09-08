#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int xa, ya, xb, yb, xc, yc, xd, yd;

ll calc(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    ll xl = max(x1, x3);
    ll yl = min(y1, y3);
    ll xr = min(x2, x4);
    ll yr = max(y2, y4);
    if(xl <= xr && yr <= yl) return  abs(xr - xl) *  abs(yr - yl);
    return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 	cin >> xa >> ya;
 	cin >> xb >> yb;
 	cin >> xc >> yc;
 	cin >> xd >> yd;   
    cout << max(calc(xa , ya, xb, yb, xc, yc, xd, yd), calc(xc , yc, xd, yd, xa, ya, xb, yb));
}