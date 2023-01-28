#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fori(n, i) for (int i = 0; i<n; i++)
 
 
int main() {
    int n;
    long long result = 0, x, tmp, prefixSum = 0;
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> x;
    map<long long, int> m;
    auto t = m.begin();

    fori(n, i) {

        cin >> tmp;
        prefixSum += tmp;

        result += (x == prefixSum);
        
        t = m.find(prefixSum - x);
        if(t != m.end())
            result += t->second; 
       
        m[prefixSum] += 1;

    }
    cout << result;
    return 0;
}