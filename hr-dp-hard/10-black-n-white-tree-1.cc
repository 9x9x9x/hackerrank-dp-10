#include <bits/stdc++.h>
// #include "testlib.h"
using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
const int N=200010;
int w[2];
vector <int> v[N];
int a[N], d[N], p[N], c[N], col[N], sz, ccol[2][N];
bool f[N];
queue<int> q[N];
void dfs(int x,int y){
    f[x]=1;
    w[y]++;
    col[x] = y;
    ccol[y][sz] = x;
    for (int i=0;i<v[x].size();i++)
    if (!f[v[x][i]])
        dfs(v[x][i],(y^1));
    else if( col[v[x][i]] != 1 - y ) 
        assert(0);
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0,x,y;i<m;i++){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int k=0;
    for (int i=1;i<=n;i++) {
        if (!f[i]) {
            w[0] = w[1]=0;
            dfs(i,0);
            c[i] = (w[0] < w[1]);
            k+=abs(w[0]-w[1]);
            a[abs(w[0]-w[1])]++;
            q[abs(w[0]-w[1])].push( i );
        }
    }

    for (int j=1;j<=k;j++) d[j]=N;

    for (int i=1;i<=n;i++)
        if (a[i]) {
            for (int j=0;j+i<=k;j++) {
                if( d[i+j] == N && d[j] != N ) {
                    d[i+j] = d[j] + 1;
                    p[i+j] = j;
                }
            }

            for (int j=1;j<=k;j++) {
                if (d[j]>a[i]) {
                    d[j]=N;
                    p[j]=0;
                } else {
                    d[j]=0;
                }
            }
        }

    int ans=k, v = 0;
    for (int i=0;i<=k;i++) {
        if(d[i]<N) {
            if( ans >= abs(k - 2 * i) ) {
                ans = abs(k - 2 * i);
                v = i;
            }
        }
    }

    memset(f, 0, sizeof f);
    while( v != 0 ) {
        int diff = v - p[v];
        int nd = q[diff].front();
        q[diff].pop();
        sz ++;
        dfs(nd, c[nd]);
        v = p[v];
    }

    for(int i=1; i<=n; i++) {
        if( !f[i] ) {
            sz ++;
            dfs(i, 1 - c[i]);
        }
    }

    int blk, wht, idb, idw;
    blk = wht = idb = idw = -1;
    for(int i=1; i<=sz; i++) {

        if( ccol[0][i] ) {
            blk = ccol[0][i];
            idb = i;
        }

        if( ccol[1][i] ) {
            wht = ccol[1][i];
            idw = i;
        }
    }
    cout << ans << " " << sz - 1 << "\n";
    if( idb != idw ) cout << blk << " " << wht << "\n";
    for(int i=1; i<=sz; i++) {
        if( i != idb && i != idw ) {
            if( ccol[0][i] ) {
                cout << wht << " " << ccol[0][i] << "\n";
            } else {
                cout << blk << " " << ccol[1][i] << "\n";
            }
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N=200002;
int w[2],w2[2];
vector <int> v[N];
vector <pair <int,int> > v2[N];
int a[N],d[N],fr[N];
bool f[N];

void dfs(int x,int y){
    f[x]=1;
    w[y]++;
    w2[y]=x;
    for (int i=0;i<v[x].size();i++)
    if (!f[v[x][i]])
        dfs(v[x][i],(y^1));
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0,x,y;i<m;i++){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int k=0;
    for (int i=1;i<=n;i++)
    if (!f[i]){
        w[0]=w[1]=0;
        dfs(i,0);
        k+=abs(w[0]-w[1]);
        a[abs(w[0]-w[1])]++;
        if (w[0]<w[1]) swap(w2[0],w2[1]);
        v2[abs(w[0]-w[1])].push_back({w2[0],w2[1]});
    }

    for (int j=1;j<=k;j++) d[j]=N,fr[j]=-1;

    for (int i=1;i<=n;i++)
    if (a[i]){
        for (int j=0;j+i<=k;j++)
        if (d[i+j]>d[j]+1)
            d[i+j]=d[j]+1,
            fr[i+j]=j;

        for (int j=1;j<=k;j++)
        if (d[j]>a[i]) 
            d[j]=N;
        else 
            d[j]=0;
    }

    int ans=k;
    int kk=k;
    for (int i=0;i<=k;i++)
    if(d[i]<N) 
        if (ans>abs(k-i*2))
            ans=abs(k-i*2),
            kk=i;

    if (kk==0) kk=k;

    vector <pair <int,int> > ap;

    vector <int> BL,WH;
    int sz=kk;

    while (kk){
        sz=kk-fr[kk];
        kk=fr[kk];
        BL.push_back(v2[sz].back().first);
        v2[sz].pop_back();
    }

    for (int i=0;i<=k;i++)
       while (v2[i].size()){
        WH.push_back(v2[i].back().first);
        v2[i].pop_back();
    }

    if (BL.size() && WH.size()){
        for (int i=0;i<BL.size();i++)
            ap.push_back({BL[i],WH[0]});
        for (int i=0;i<WH.size();i++)
            ap.push_back({BL[0],WH[i]});
    }

    cout<<ans<<" "<<ap.size()<<endl;
    for (int i=0;i<ap.size();i++)
        printf("%d %d\n",ap[i].first,ap[i].second);
    return 0;
}
*/
