#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define fori(n, i) for(int i=0; i<n; i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;



int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vi heights(n);
    vi prevs(n);
    vi costs(n);

    fori(n, i){
        cin >> heights[i];
    }

    costs[0] = 0;
    prevs[0] = -1;

    for(int i = 1; i < n; i++){
        int cost = LLONG_MAX, tmpCost, tmpPrev = 0;
        for(int j = 0; j < i; j++){
            tmpCost = costs[j] + i - j + pow(heights[i] - heights[j], 2);
            if(cost > tmpCost){
                cost = tmpCost;
                tmpPrev = j;
            }
        }
        prevs[i] = tmpPrev;
        costs[i] = cost;
    }

    stack<int> path;

    n--;

    while(n >= 0){
        path.push(n + 1);
        n = prevs[n];
    }

    cout << path.size() << endl;

    while(!path.empty()){
        cout << path.top() << ' ';
        path.pop();
    }

    return 0;
}