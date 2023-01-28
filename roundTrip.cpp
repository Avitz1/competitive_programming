#include <bits/stdc++.h>
using namespace std;
//@formatter:off
#ifdef lol
const bool dbg = true;
#else
const bool dbg = false;
#endif
#define dout if(dbg) cout
#define int int64_t
#define fori(n, i) for(int i=0; i<n; i++)
#define loop(i, s, n) for (int i = s; i < n; ++i)
#define fin(i, s, n) for (auto i = s; i < n; ++i)
#define fine(i, s, n) for (auto i = s; i <= n; ++i)
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define def(x) int x; cin >> x
#define cases def(t); while (t--)
#define cases1 int t = 1; while(t--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vii = vector<ii>;
using vvii = vector<vector<ii>>;
using vstr = vector<string>;
using ld = long double;
#define tct template<class T>
#define tcab template<class A, class B>
tcab ostream &operator<<(ostream &os, pair<A, B> p) { if(dbg) return os << '{' << p.x << ',' << p.y << '}'; return os << p.x << ' ' << p.y; }
tct ostream &operator<<(ostream &os, vector<T> v) { if(dbg) os << '['; if (!v.empty()) { os << v[0]; fin(i, 1, v.size()) os << (dbg?',':' ') << v[i]; } return dbg?(os << ']'):os; }
tcab istream& operator>>(istream& is, pair<A,B>& p) { return is >> p.x >> p.y; }
template<class A, size_t B> istream& operator>>(istream& is, array<A,B>& v) { for(auto& x : v) is >> x; return is; }
tct istream& operator>>(istream& is, vector<T>& v) { for(auto& x : v) is >> x; return is; }
#define popcnt(x) __builtin_popcount(x)
#define sz(a) int((a).size())
//@formatter:on

int t = 1;
constexpr size_t maxn = 2e5;

int in_time[maxn] = {0};
int out_time[maxn] = {0};

vector<int> g[maxn];
vi path;
int start = 0, done = 0;

void dfs(int s, int prev) {
    if(in_time[s]){
        start = s;
        path.push_back(s);
        return;
    }
    in_time[s] = t++;
    for(auto &v : g[s]){
        if(v != prev) 
            dfs(v, s);
        if(start){
            if(!done){
                path.push_back(s);
                if(s == start)
                    done = 1;
            }
            return;
        }
    }
    out_time[s] = t++;
}
 

int32_t main(){
    if (dbg) {
        freopen("input.txt", "r", stdin);
        // std::ifstream f("input.txt");
        // if (f.is_open())
        //     std::cout << f.rdbuf();
        cout << "using " << sizeof(int) * 8 << "-bit integers." << endl;
    } else cin.tie(0)->sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    fori(m, i){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fori(n, i){
        if(!in_time[i])
            dfs(i, 0);
        if(start)
            break;
    }

    if(!start)
        cout << "IMPOSSIBLE";
    else
        {   
            cout << sz(path) << endl;
            for(int i=0; i<sz(path); i++){
                cout << path[i] << ' ';
            }
        }

    return 0;
}