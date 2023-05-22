#include<bits/stdc++.h>
using namespace std;
long long n, a[1000005], ans=0, mot, hai;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Paragraph.INP", "r", stdin);
    freopen("Paragraph.OUT", "w", stdout);
    cin>>n;
    for ( int i = 1; i <= n ; i++ )
        cin >> a[i];
    for ( long long i = 1 ; i <= n ; i++)
    {
        long long j = i;
        mot = a[i];
        while(a[j] == a[i] and j<=n)
            j ++;
        hai = a[j];
        ans = max(ans, j - i + 1 );

        while ((a[j]==hai or a[j]==mot) and j < n )
            j++;
        ans = max(ans, j - i );
    }
    cout<<ans;
}
