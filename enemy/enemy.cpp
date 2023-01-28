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
        int n = a.size();
        for(sz=1; n>sz; sz*=2);
        t.assign(2*sz,0);
        loop(i,0,n) t[i+sz] = a[i];
        for(int i = sz-1; i > 0; --i) {
            t[i] = t[2*i]+t[2*i+1];
        }
    }
    void update(int i, int x) {
        i += sz;
        t[i] = x;
        for(i/=2; i > 0; i/=2) {
            t[i] = t[2*i]+t[2*i+1];
        }
    }
    int query(int l, int r) {
        int ans = 0;
        for(l+=sz,r+=sz; l<=r; l/=2,r/=2) {
            if(l%2) ans += t[l++];
            if(!(r%2)) ans += t[r--];
            if(l>r) break;
        }
        return ans;
    }
};

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, tmp, index;
    cin >> n;

    vi vec(n);
    fill(vec.begin(), vec.end(), 0);
    seg countersTree(vec);
    seg secondCountersTree(vec);
    vector<long long> greater(n);
    vector<long long> smaller(n);

    fori(n, i){
        cin >> vec[i];
    }
    vi sorted = vec;
    sort(sorted.begin(), sorted.end());
    
    auto begin = sorted.begin();
    fori(n, i){
        auto t = lower_bound(sorted.begin(), sorted.end(), vec[i]);
        index = t - begin;
        greater[i] = countersTree.query(index, n-1);
        countersTree.update(index, 1);
    }

    for(int i = n-1; i >= 0; i--){
        auto t = lower_bound(sorted.begin(), sorted.end(), vec[i]);
        index = t - begin;
        smaller[i] = secondCountersTree.query(0, index);
        secondCountersTree.update(index, 1);
    }

    long long result = 0;
    fori(n, i){
        result += greater[i]*smaller[i];
    }

    cout << result;

    return 0;

}