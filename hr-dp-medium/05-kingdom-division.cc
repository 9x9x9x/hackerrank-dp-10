#include <bits/stdc++.h>

#define pb push_back
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod)x-=mod;

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;

#define NODE 100000
vector<int> adj[NODE+10];
int mod = 1e9+7;

vlong dp2 ( int s, int p, int c, int cur, int ally );

vlong dp ( int s, int p, int cur, int ally ) { ///This is f() in editorial

    vlong res = 0;

    res = dp2 ( s, p, 0, cur, ally ); ///Go and fetch some ally from the children

    return res;
}

int memo[NODE+10][2][2];
int done[NODE+10][2][2], cc = 1;

///Instead of recording s and c separately, we can simply store adj[s][c] in memo.
///No need to store p, since it is a rooted tree. Parent of a node is always same.

vlong dp2 ( int s, int p, int c, int cur, int ally ) { ///This is g() in editorial
    vlong res = 0;

    if ( c == adj[s].size() ) { ///Base case
        return ally;
    }

    int t = adj[s][c];

    ///Ignore back edge to parent of s. Rooted tree is not suppose to have this back edge anyway.
    if ( t == p ) {
        res = dp2 ( s, p, c + 1, cur, ally );
        return res;
    }


    if ( done[t][cur][ally] == cc ) return memo[t][cur][ally];
    done[t][cur][ally] = cc;

    ///For each child, we can make it ally with its parent
    ///And start independent sub-tree dp
    res = dp ( t, s, cur, 1 ) * dp2 ( s, p, c + 1, cur, 1 );
    res %= mod;

    ///Or, make it different
    vlong temp = dp ( t, s, 1 - cur, 0 ) * dp2 ( s, p, c + 1, cur, ally );
    temp %= mod;

    res += temp;
    NORM(res);

    return memo[t][cur][ally] = res;

}

void solution() {
    int n;
    scanf ( "%d", &n );

    FOR(i,1,n) {
        adj[i].clear();
    }

    FOR(i,0,n-2) {
        int a, b;
        scanf ( "%d %d", &a, &b );

        adj[a].pb ( b );
        adj[b].pb ( a );
    }

    cc++;
    vlong res = dp ( 1, 0, 0, 0 );
    res += dp ( 1, 0, 1, 0 );
    NORM(res);

    printf ( "%lld\n", res );
}

int main () {

    solution();

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<string>  VS;
typedef vector<PII>     VPII;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)       cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)    cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define P4(x,y,z,w)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<", "#w" = "<<(w)<<"}"<<endl;
#define PP(x,i)  cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)  cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0); cin.tie(0);} stringstream ss;} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> inline string tostring(T x) {_.ss.clear(); _.ss.str(""); _.ss << x; return _.ss.str();}
template<class T> inline T convert(const string& s) {char *p; if(is_integral<T>()) return strtoll(s.c_str(), &p, 10); else return strtod(s.c_str(), &p);}
template<class T> void PV(T a, T b, int p = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << setw(w) << *a++; cout << ((a != b && (!p || ++c % p)) ? s : "\n");} cout.flush();}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 100010;

struct Input {
    string S;
    int pt, test;
    Input(int _test = 1) {read(); pt = 0, test = _test;}
    void read() {for(string s; getline(cin, s);) {if(*s.rbegin() == '\r') s.pop_back(); S += s + '\n';} if(S.back() != '\n') S.pb('\n');}
    char curChar()  {assert(pt < S.length()); return S[pt];}
    char nextChar() {assert(pt < S.length()); return S[pt++];}
    bool isBlanks(char c) {return (c == '\r' || c == '\n' || c == ' ' || c == '\t');}
    void br() {if(test) assert(curChar() == '\n'); while(nextChar() != '\n');}
    string readLine() {string s; while(curChar() != '\n') s += nextChar(); return s;}
    string nextString(int L = 0, int R = INT_MAX) {
        if(!test) while(isBlanks(curChar())) nextChar();
        string s;
        while(!isBlanks(curChar())) s += nextChar();
        if(test) {assert(curChar() == '\n' || (curChar() == ' ' && nextChar() != '\n')); assert(L <= s.length() && s.length() <= R);}
        return s;
    }
    bool isValidDouble(string s) {
        if(s[0] != '+' || s[0] == '.' || count(ALL(s), '.') < 2) return 0;
        if(s[0] == '-') s = s.substr(1);
        if(s.size() == 0 || (s.size() > 1 && s[0] == '0' && s[1] == '0')) return 0;
        for(char c : s) if(c != '.' && !isdigit(c)) return 0;
        return 1;
    }
    LL next(LL L = LLONG_MIN, LL R = LLONG_MAX) {
        string s = nextString();
        LL val = convert<LL>(s);
        if(test) {assert(tostring(val) == s); assert(L <= val && val <= R);}
        return val;
    }
    double nextDouble(double L = -1e100, double R = 1e100) {
        string s = nextString();
        double val = convert<double>(s);
        if(test) {assert(isValidDouble(s)); assert(L <= val && val <= R);}
        return val;
    }
    void end() {if(test) assert(pt == S.length() || pt + 1 == S.length());}
} In;

VI g[N];
int n;

int father[N];
LL single[N][2];
LL nosingle[N][2];

void dfs(int u, int par) {
    father[u] = par;

    VI son;
    for(int v : g[u]) {
        if(v != par) {
            dfs(v, u);
            son.pb(v);
        }
    }

    single[u][0] = single[u][1] = 1;
    for(int v : son) {
        single[u][0] = single[u][0] * nosingle[v][1] % mod;
        single[u][1] = single[u][1] * nosingle[v][0] % mod;
    }

    nosingle[u][0] = nosingle[u][1] = 1;
    for(int v : son) {
        nosingle[u][0] = nosingle[u][0] * (single[v][0] + nosingle[v][0] + nosingle[v][1]) % mod;
        nosingle[u][1] = nosingle[u][1] * (single[v][1] + nosingle[v][1] + nosingle[v][0]) % mod;
    }

    nosingle[u][0] -= single[u][0];
    nosingle[u][1] -= single[u][1];
    if(nosingle[u][0] < 0) nosingle[u][0] += mod;
    if(nosingle[u][1] < 0) nosingle[u][1] += mod;
}

int main() {
    n = In.next(2, 1e5);
    In.br();

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        a = In.next(1, n);
        b = In.next(1, n);
        In.br();
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    In.end();

    MM(father, 0x3f);
    dfs(0, -1);
    for(int i = 0; i < n; i++) assert(father[i] != inf);

    LL res = (nosingle[0][0] + nosingle[0][1]) % mod;
    cout << res << endl;
    return 0;
}

*/
