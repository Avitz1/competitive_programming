#include <bits/stdc++.h>
using namespace std;
#define fori(n, i) for(int i=0; i<n; i++)
#define loop(i,s,n) for(auto i = s; i != n; ++i)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;


struct seg {
    vi t;
    int sz;
    seg(vi& a) {
        int n = a.size(), op = 1;
        for(sz=1; n>sz; sz*=2);
        t.assign(2*sz,0);
        loop(i,0,n) t[i+sz] = a[i];
        for(int i = sz-1; i > 0; --i) {
            int x = (int) log2(i+1);
            if(abs(x-log2(i+1))<1e-50){
                if(!op)
                    op++;
                else
                    op--;
            }

            if(!op){
                t[i] = t[2*i]|t[2*i+1];
            }
            else
            {
                t[i] = t[2*i]^t[2*i+1];
            }
        }
    }
    void update(int i, int x) {
        int op = 0;
        i += sz;
        t[i] = x;
        for(i/=2; i > 0; i/=2) {
            if(!op){
                t[i] = t[2*i]|t[2*i+1];
                op++;
            }
            else{
                t[i] = t[2*i]^t[2*i+1];
                op--;
            }
        }
    }
    int query() {
        return t[1];
    }
};

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, size;
    cin >> n >> m;
    size = pow(2, n);
    vi vec(size);

    fori(size, i){
        cin >> vec[i];
    }
    seg tree(vec);
    queue<int> prints;
    fori(m, i){
        int p, b;
        cin >> p >> b;
        tree.update(p-1, b);
        prints.push(tree.query());
    }
    while(!prints.empty()){
        cout << prints.front() << endl;
        prints.pop();
    }
    return 0;
}
