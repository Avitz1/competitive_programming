#include <bits/stdc++.h>
using namespace std;
constexpr size_t maxn = 2e5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, t;
    cin >> n >> t;

    vector<long> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long low = 0, high =  1e18, mid = (high+low)/2, result;

    while(high != low){
        result = 0;
        for(int i=0; i<n; i++){
            result += (mid/arr[i]);
            if(result>=t)
                break;
        }  
        if(result < t)
            low = mid + 1;
        else
            high = mid;
        mid = (high + low)/2;
    }

    cout << low;
    return 0;
}