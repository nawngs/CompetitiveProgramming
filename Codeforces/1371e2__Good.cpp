// LUOGU_RID: 100106121
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p,tmp;
int a[100005];
int b[200005];
int ans[100005];
signed main()
{
    ios::sync_with_stdio(0);
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[n+1]=a[n]+1;
    for(int i=a[n]-n+1;i<=a[n];i++)
    {
        int q=upper_bound(a+1,a+n+1,i)-a-1;
        b[(i-q+p)%p]++;
    }
    int k=max(0ll,a[n]-n+1);
    for(int i=k;i<=a[n];i++)
    {
        if(!b[i%p]) ans[++tmp]=i;
        b[(i-(upper_bound(a+1,a+n+1,i)-a-1)+p)%p]--;
        b[(i+n-(upper_bound(a+1,a+n+1,i+n)-a-1))%p]++;
    }
    cout<<tmp<<endl;
    for(int i=1;i<=tmp;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

