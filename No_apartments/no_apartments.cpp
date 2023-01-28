#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fori(n, i) for (int i = 0; i<n; i++)
 
 
int main() {
   
    cin.tie(0)->sync_with_stdio(0);
    int t, n;
    cin >> t;
    t *= 3;
    vector<int> arr(t);

    for(int i=0; i<t;){
        cin >> n;
        switch (n%10)
        {
        case 0:{
            arr[i++] = 0; arr[i++] = n/5; arr[i++] = 0;
            break;
        }
        case 1:{
            if(n - 11 <= 0){
                arr[i] = -1; i+=3;
                break;
            }
            arr[i++] = 7; arr[i++] = (n-21)/5; arr[i++] = 0;
            break;
        }
        case 2:{
            if(n==2){
                arr[i] = -1; i+=3;
                break;
            }
            arr[i++] = 4; arr[i++] = (n-12)/5; arr[i++] = 0;
            break;
        }
        case 3:{
            arr[i++] = 1; arr[i++] = (n-3)/5; arr[i++] = 0;
            break; 
        }
        case 4:{
            if(n==4){
                arr[i] = -1; i+=3;
                break;
            }
            arr[i++] = 0; arr[i++] = (n-14)/5; arr[i++] = 2;
            break;
        }
        case 5:{
            arr[i++] = 0; arr[i++] = n/5; arr[i++] =  0;
            break;
        }
        case 6:{
            arr[i++] = 2; arr[i++] = (n-6)/5; arr[i++] =  0;
            break;
        }
        case 7:{
            arr[i++] = 0; arr[i++] = (n-7)/5; arr[i++] = 1;
            break;
        }
        case 8:{
            arr[i++] = 1; arr[i++] = (n-3)/5; arr[i++] = 0;
            break;
        }
        case 9:{
            arr[i++] = 3; arr[i++] = (n-9)/5; arr[i++] = 0;
            break;
        }
    }}

    for(int i=0; i<t;){
        if(arr[i] == -1){
            cout << -1 << endl;
            i += 3;
            continue;
        }
        cout << arr[i] << " " << arr[i+1] << " " << arr[i+2] << endl;
        i += 3;
    }
    return 0;
}