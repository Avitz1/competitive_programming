#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fori(n, i) for (int i = 0; i<n; i++)
#define forj(n, j) for (int j = 0; j<n; j++) 


int main(){
    
    //start with singles and for each, check if it can get united with another

    int n, result = 0;
    cin >> n;
    
    bitset<100> result_utility;
    result_utility.flip();

    int arr[100][2];
    bitset<100> arr1[100];
   
    fori(n, i){
        cin >> arr[i][0] >> arr[i][1];
        arr1[i][i] = 1;
    }

    forj(n, i){
        forj(n, j){
            arr1[i][j] = arr[i][0]==arr[j][0] || arr[i][1]==arr[j][1];
        }   
    }
    for(int k = 0; k < (log(n) + 1); k++)
        forj(n, i){
            forj(n, j){
                if((arr1[i] & arr1[j]) != 0)
                arr1[i] |= arr1[j];
        }   
    }
    
     fori(n, i){
        if((result_utility & arr1[i]) !=0){
            result++;
            result_utility &= arr1[i].flip();
        }
    }

    cout << result - 1;
    return 0;
}