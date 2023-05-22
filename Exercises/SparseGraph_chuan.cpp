#include<iostream>
#include<ctime>
#include<cstring>
#include<queue>
#include<set>
#include<tuple>
#define int long long
#define task "sparsegraph"
using namespace std;
using ii=pair<int,int>;

const int mn=1e5+11,inf=0x3f3f3f3f;

template<typename t>
bool ckmin(t& target,const t& source){
    return target>source ? target=source,1 : 0;
}
template<typename t>
bool ckmax(t& target,const t& source){
    return target<source ? target=source,1 : 0;
}

int getc(){
	static char buf[1<<16];
	static size_t bufsize=1<<16,bufat=0,bufend=0;
	if(bufat==bufend){
		bufend=fread(buf,sizeof(char),bufsize,stdin);
		bufat=0;
	}
	return bufend ? buf[bufat++] : EOF;
}
template<typename _t>
	_t getd(){
		int sgn=1,c;
		while(!isdigit(c=getc()) && c!='-');
		if(c=='-')sgn=-1,c=getc();

		_t res=0;
		for(;isdigit(c);c=getc())
            res*=10,res+=c-'0';
		return res*sgn;
	}
inline void scan(){}
template<typename _t,typename... _ts>
    void scan(_t& n,_ts&... args){
        n=getd<_t>();
        scan(args...);
    }

struct dsu{
    int p[mn];
    dsu(){memset(p,-1,sizeof(p));}

    int find(int i){
        return p[i]<0 ? i : p[i]=find(p[i]);
    }

    bool merge(int u,int v){
        if((u=find(u))==(v=find(v)))
            return false;
        if(p[u]>p[v])swap(u,v);
        return p[u]+=p[v],p[v]=u,true;
    }
}st;

int p[mn][17],h[mn],e[mn];
vector<ii>tree[mn];

void dfs(int u,int pre){
    for(const ii& k:tree[u]){
        int v=k.first,w=k.second;
        if(v==pre)continue;
        h[v]=h[u]+1,e[v]=e[u]+w;
        p[v][0]=u;dfs(v,u);
    }
}
int lca(int u,int v){
    if(h[u]>h[v])swap(u,v);
    for(int i=16;i>=0;i--)if(h[v]-(1<<i)>=h[u])
        v=p[v][i];
    if(u==v)return u;

    for(int i=16;i>=0;i--)if(p[u][i]!=p[v][i])
        u=p[u][i],v=p[v][i];
    return p[u][0];
}

int n,m;

vector<ii>adj[mn];

int d[43][mn];
bool vs[mn];
void dijkstra(int* d,int s){
    memset(vs,0,sizeof(vs));
    d[s]=0;vs[s]=1;
    deque<int>q;
    q.push_back(s);

    while(q.size()){
        int u=q.front();
        q.pop_front();vs[u]=0;
        for(const auto& k:adj[u]){
            int v=k.first,uv=k.second;
            if(ckmin(d[v],d[u]+uv))
                if(!vs[v])vs[v]=1,q.push_back(v);
        }
    }
}


int32_t main()
{
	cin.tie(0)->sync_with_stdio(0);
	#ifdef _TPR_
		freopen("t.inp","r",stdin);
		freopen("t.out","w",stdout);
    #else
        freopen(task".inp","r",stdin);
		freopen(task".out","w",stdout);
	#endif
    set<int>out_vertexes;

    scan(n,m);
    for(int i=1,u,v,w;i<=m;i++){
        scan(u,v,w);
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);

        if(st.merge(u,v)){
            tree[u].emplace_back(v,w);
            tree[v].emplace_back(u,w);
        }
        else{
            out_vertexes.emplace(u);
            out_vertexes.emplace(v);
        }
    }
    memset(d,0x3f,sizeof(d));
    //cerr<<clock()<<'\n';
    int cnt=0;
    for(int u:out_vertexes)
        dijkstra(d[++cnt],u);
    //cerr<<clock()<<'\n';
    
    dfs(1,-1);

    for(int j=1;j<=16;j++)
        for(int i=1;i<=n;i++)
            p[i][j]=p[p[i][j-1]][j-1];
    // cerr<<clock()<<'\n';
    int q;scan(q);
    while(q--){
        int u,v;scan(u,v);
        int s=lca(u,v);
        
        s=e[u]+e[v]-2*e[s];
        for(int i=1;i<=cnt;i++)
            ckmin(s,d[i][u]+d[i][v]);
        cout<<s<<'\n';
    }
    // cerr<<clock()<<'\n';
}