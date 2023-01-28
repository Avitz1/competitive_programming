#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;
#define fori(n, i) for( int i=0; i<n; i++)
#define MAX 1e12

int main(){
        cin.tie(0)->sync_with_stdio(0);
        int t, n, j;
        long long cost_to_begin, result, min_cost_to_begin, marginal_cost, first_a, prev_b, b, zero = 0;
        cin >> t;
        vector<long long> arr(t);

        fori(t, i){
            cin >> n >> first_a >> prev_b;
            min_cost_to_begin = MAX;
            result = 0; 
        
            for(j = 1; j < n; j++){
                cin >> cost_to_begin >> b;
                marginal_cost = max(zero, cost_to_begin - prev_b);
                min_cost_to_begin = min(min_cost_to_begin, cost_to_begin-marginal_cost);
                result += marginal_cost;
                prev_b =b;
            }
            marginal_cost = max(zero, first_a- prev_b);
            result += marginal_cost;
            result += min(min_cost_to_begin, first_a-marginal_cost);
            arr[i] = result;
        }
        fori(t, i){
            cout << arr[i] << " ";
        }
        return 0; 
}