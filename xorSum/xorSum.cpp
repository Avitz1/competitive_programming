#include <bits/stdc++.h>
using namespace std;
#define fori(n, i) for(int i=0; i<n; i++)
#define loop(i,s,n) for(auto i = s; i != n; ++i)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

struct tr {
    //[l,r]
    int l, r, m, sum = 0, lazy = 0, lazyXor = 0;
    tr *lp = 0, *rp = 0;

    tr(int l, int r) : l(l), r(r), m((l + r) / 2) {
        if (l != r) lp = new tr(l, m), rp = new tr(m + 1, r);
    }

    void prop(int x) {
        lazy += x;
        sum += (r - l + 1) * x;
    }

    void propXor(int x){
        lazyXor ^= x;
        sum ^= x;
    }

    void fix() {
        if (l != r && lazy != 0) {
            lp->prop(lazy), rp->prop(lazy);
            lazy = 0;
        }
        if (l != r) sum = lp->sum + rp->sum;
    }

    void fixXor(){
        if (l != r && lazyXor != 0) {
            lp->propXor(lazyXor), rp->propXor(lazyXor);
            lazyXor = 0;
        }
        if (l != r) sum = lp->sum + rp->sum;
    }

    void update(int from, int to, int x) {
        if (from <= l && r <= to) {
            prop(x);
            return;
        }
        if(from > r || to < l) return;
        fix();
        lp->update(from,to,x);
        rp->update(from,to,x);
        fix();
    }

    void updateXor(int from, int to, int x) {
        if (from <= l && r <= to) {
            propXor(x);
            return;
        }
        if(from > r || to < l) return;
        fixXor();
        lp->updateXor(from,to,x);
        rp->updateXor(from,to,x);
        fixXor();
    }

    int query(int from, int to) {
        if (from <= l && r <= to) return sum;
        if(from > r || to < l) return 0;
        fixXor();
        return lp->query(from,to)+rp->query(from,to);
    }
};

int32_t main(){

    int n, m, tmp, from, to;
    cin >> n;

    tr tree(1, n);
    fori(n, i){
        cin >> tmp;
        tree.update(i, i, tmp);
    }

    cin  >> m;
    vi vec(m);
    fori(m, i){
        cin >> tmp;
        if(tmp == 1){
            cin >> from >> to;
            cout << tree.query(from, to);
        }
        else{
            cin >> from >> to >> tmp;
            tree.updateXor(from, to, tmp);
        }
    }
    return 0;
}