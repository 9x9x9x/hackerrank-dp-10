#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define TRACE
using namespace std;

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define traceVI(a) for(int i=0; i<a.size(); i++)cerr << #a[i] << " "; cerr << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#define traceVI(a)

#endif


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

const LL MOD=1000000007ll;

LL mpow(LL a, LL n){LL ret=1,b=a;while(n){if(n&1)
ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}return ret;}

#define MAXN 1200

int ar[MAXN+10];
int dp[MAXN+10][MAXN+10];
int fac[MAXN+10];
int inv[MAXN+10];

//dp1[i][j] denotes if A[i, j] is increasing or not
bool dp1[MAXN+10][MAXN+10];

void genfac(){
    fac[0]=1;
    inv[0]=1;
    for(int i=1; i<=MAXN; i++){
        fac[i]=((LL)i*(LL)fac[i-1])%MOD;
        inv[i]=mpow(fac[i],MOD-2);
    }
}

int choose(int n, int r){
    return ((LL)fac[n]*(LL)inv[n-r])%MOD;
}

int rec(int i, int j){
    if(j>i+1)return dp[i][j]=0;
    if(j==i+1)return dp1[0][i];
    int &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=0;
    for(int k=j; k<=i-j+1; k++){
        if(dp1[i-j+1][i]){
            ret += ((LL)choose(k,j)*(LL)rec(i-j,k))%MOD;
            if(ret>=MOD)ret-=MOD;
        }
    }
    return ret;
}

int main()
{
    genfac();
    int t,cnt=0;
    sd(t);
    assn(t,1,100);
    while(t--){
        int n;
        sd(n);
        assn(n,1,1000);
        cnt+=n;
        for(int i=0; i<n; i++)
            sd(ar[i]);
        for(int i=0; i<n; i++)for(int j=0; j<n; j++)dp[i][j]=-1,dp1[i][j]=false;
        for(int i=0; i<n; i++){
            bool fl=true;
            for(int j=i; j<n; j++){
                dp1[i][j]=fl;
                if(j<n-1 and ar[j]>ar[j+1])fl=false;
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            ans += rec(n-1,i);
            if(ans>=MOD)ans-=MOD;
        }
        cout << ans << endl;
    }
    assn(cnt,1,2000);
    return 0;
}
