#include <bits/stdc++.h>
using namespace std;
#define fori(n, i) for(int i=0; i<n; i++)
#define loop(i,s,n) for(auto i = s; i != n; ++i)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

int t = 1;
int t1 = 1;
constexpr size_t maxn = 2e5;

int in_time[maxn] = {0};
int out_time[maxn] = {0};

vector<int> g[maxn];

map<int, int> positions;

void dfs(int s) {
    if(in_time[s]) return;
    positions[t1++] = s;
    in_time[s] = t++;
    for(auto &v : g[s]) dfs(v);
    out_time[s] = t++;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q, tmp;
    cin >> n >> q;
    for(int i=2; i<=n; i++){
        cin >> tmp;
        g[tmp].push_back(i);
    }

    fori(n, i){
        sort(g[i].begin(), g[i].end());
    }

    dfs(1);

    vi sol(n);
    int u, k;
    fori(q, i){
        cin >> u >> k;
        if(positions.find(in_time[u] + k) != positions.end() && in_time[positions[in_time[u] + k]] < out_time[u])
            cout << positions[in_time[u] + k] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}