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
using bigint = __int128;
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
constexpr size_t maxn = 1e5;

vector<ii> w_graph[maxn];
int n;
vi dijkstra(int source) {
    set<ii> s;
    vi distances(n, 1e14); // equiv. use double
    // or any other big number
    distances[source] = 0;
    s.insert({0, source});
    while(!s.empty()) {
        auto u = *s.begin();
        s.erase(u);
        if(u.x > distances[u.y])
            continue;
        for(auto& [v, w] : w_graph[u.y]) {
            if(distances[v] > distances[u.y] + w) {
                distances[v] = distances[u.y] + w;
                s.insert({distances[v], v}); 
            }
        }
    }
return distances;
}


int32_t main() {
    if (dbg) {
        freopen("input.txt", "r", stdin);
        cout << "using " << sizeof(int) * 8 << "-bit integers." << endl;
    } else cin.tie(0)->sync_with_stdio(0);
    int m, a, b, c;
    cin >> n >> m;

    fori(m, i){
        ii edge;
        cin >> a >> edge;
        --a,--edge.x;
        w_graph[a].pb(edge);
    }

    vi sol = dijkstra(0);

    cout << sol << endl;

    return 0;
}

