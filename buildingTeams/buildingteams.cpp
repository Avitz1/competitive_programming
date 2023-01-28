#include <bits/stdc++.h>
using namespace std;
#define fori(n, i) for(int i=0; i<n; i++)
#define loop(i,s,n) for(auto i = s; i != n; ++i)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
int t = 1;
constexpr size_t maxn = 2e5;

int in_time[maxn] = {0};
int out_time[maxn] = {0};
int group[maxn] = {0};

vector<int> g[maxn];
int flag = 0;

void dfs(int s) {
    if(in_time[s]) return;
    in_time[s] = t++;
    for(auto &v : g[s]){
        int otherGroup = (group[s] == 1 ? 2 : 1);
        if(group[v] == group[s])
            flag = 1;
        else if(!group[v])
            group[v] = otherGroup;
    }
    for(auto &v : g[s]) dfs(v);
    out_time[s] = t++;
}

 

int main(){
    int n, m, a, b;
    cin >> n >> m;
    fori(m, i){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        if(!in_time[i]){
            group[i] = 1;
            dfs(i);
        }
    }
    if(flag)
        cout << "IMPOSSIBLE";
    else
        {for(int i=1; i<=n; i++){
            cout << group[i] << ' ';
        }}

    return 0;
}