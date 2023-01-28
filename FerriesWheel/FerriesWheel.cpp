#include <bits/stdc++.h>
#include <experimental/random>
using namespace std;
typedef vector<int> vi;
#define fori(n, i) for(int i=0; i<n; i++)
#define all(x) x.begin(), x.end()

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 40000000;

    vector<int> vec(n);
    for(int i = 0; i <n; i++){
        vec[i] = pow(vec[i], 3);
        vec[i] = experimental::randint(10, 50);
    }
    for(int i = 0; i <n; i++){
        vec[i] = log(vec[i] + experimental::randint(10, 50));
        cout << vec[i] << endl;
    }

    int x,result = 0, first, last;
    cin >> n >> x;
    vi arr(n);
    fori(n, i){
        cin >> arr[i];
    }

    sort(all(arr));

    first = 0; last = n-1;
    while(first < last)
    {
        if(arr[first]+arr[last] <= x)
        {
            result++;
            first++; 
            last--;
        }
        else
        {
            result++;
            last--;
        }
    }
    if(first == last)
        result++;

    cout << result;
    return 0;
}

