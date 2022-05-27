#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int a[5025];
vector<int> v;
bool prime[9025];
long long mem[2][8192];
void sieve( )   
{
    memset(prime, true, sizeof(prime));
    prime[1]=false, prime[0]=false; 
    for(int i=4;i<=9000;i+=2)
    prime[i]=false;
    for (int p=3; p*p<=9000;p+=2)
 {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=9000; i += 2*p)
                prime[i] = false;
        }
    }

}
int main() {
//freopen("input2.txt","r",stdin);
//freopen("output2.txt","w",stdout);
clock_t begin, end;
begin = clock();
int t;
sieve();
cin >> t;
while(t--) {
    int n;
    cin >> n;
    v.clear();
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        a[x]+=1;
    }
    for(int i=3500;i<4525;i++)
        if(a[i]>=1)
            v.push_back(i);
    memset(mem,0,sizeof(mem));
    mem[0][0]=1;
    int flag=1;
    int k = v.size();
    for(int i=1;i<=k;i++) {
        for(int j=0;j<8192;j++) {
            mem[flag][j] = (mem[flag^1][j]*(1+(a[v[i-1]])/2))%mod + (mem[flag^1][j^v[i-1]]*((a[v[i-1]]+1)/2))%mod;
            if(mem[flag][j]>=mod)
                mem[flag][j]%=mod;
        }
        flag = flag^1;

    }
    long long ans=0;
    long long res=0;
    for(int i=1;i<8192;i++) {
        if(prime[i]){

            res+= mem[flag^1][i];
            res%=mod;
        }
    }
    cout << res << endl;
}
end = clock();
//cout << ((float) (end) - (float) (begin)) / CLOCKS_PER_SEC << endl;
fclose(stdout);
return 0;

}
