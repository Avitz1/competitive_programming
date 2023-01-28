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



int32_t main() {
    int n, x, result, mod = 1e9 + 7;;
    cin >> n >> x;
    vi coins(n);
    fori(n, i){
        cin >> coins[i];
    }
    vi dp(x+1);
    dp[0] = 1;
    for(int i=1; i<=x; i++){
        result = 0;
        for(int j=0; j<n; j++){
        int prev = i-coins[j];
            if(prev >= 0 && dp[prev]){
                result = (result + dp[prev])%mod;
            }
        }
        dp[i] = result%mod;
    }

    cout << dp[x];
    return 0;
}
