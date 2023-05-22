/*
┏━━━━━━━━━━━━━━━━━━━━┓
*   By Trung113395   *
┗━━━━━━━━━━━━━━━━━━━━┛
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second
const ll nmax = 1e6;
const ll nx = 1e6+9;
const ll bx = 1e9+6;
const ll mod = 1e9+7;
vector <int> nt[nx], tmp;
bool checknt[nx];
int t, n, a[nx], ans = 0, dem = 1;
int main(int argc, char const *argv[]){
    //freopen("RobotGift.Inp", "r", stdin);
   // freopen("RobotGift.Out", "w", stdout);
   // ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    memset(checknt, true, sizeof(checknt));
    checknt[0] = checknt[1] = false;
    for (int i = 2; i * i <= nmax; i++){
        if (checknt[i]){
            for (int j = i * i; j <= nmax; j+=i) checknt[j] = false;
        }
    }
    for (int i = 2; i <= nmax; i++){
        if (checknt[i]){
            for (int j = i; j <= nmax; j+=i) nt[j].push_back(i);
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < nt[a[i]].size(); j++) tmp.push_back(nt[a[i]][j]);
        }
        sort(tmp.begin(), tmp.end());
        ans = dem = (tmp.size() != 0);
        for (int i = 1; i < tmp.size(); i++){
            if (tmp[i] == tmp[i-1]) dem++;
            else dem = 1;
            ans = max(ans, dem);
        }
        tmp.clear();
        cout << ans << "\n";
    }
}