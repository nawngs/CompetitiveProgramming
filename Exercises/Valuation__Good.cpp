#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
struct stu{
    int a,b;
}num[1005];
priority_queue<int>que;
bool cmp(stu u,stu v){
    if(u.a!=v.a)
        return u.a>v.a;
    else
        return u.b>v.b;
}
int main(){
    int t;
    int i,j,k;
    int n;
    scanf("%d",&t);
    long long ans;
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num[i].a);
        }
        for(i=0;i<n;i++){
            scanf("%d",&num[i].b);
        }
        sort(num,num+n,cmp);
        for(i=1;i<n;i++){
            if(i&1){
                que.push(-num[i].b);
            }
            else if(num[i].b>-que.top()){
                que.pop();
                que.push(-num[i].b);
            }
        }
        ans=0;
        while(!que.empty()){
            ans-=que.top();
            que.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}