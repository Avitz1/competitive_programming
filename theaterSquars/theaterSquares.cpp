#include <iostream>
    //#include <bits/stdc++.h>
    #include <queue>
    #include <map>

    using namespace std;
    #define fori(n, i) for( int i=0; i<n; i++)
    #define forj(n, j) for( int j=0; j<n; j++)
    #define forp(n, p) for( int p=0; p<n; p++)


    int main(){

        int t, n, m, x, y, prev, singles, doubles;
        char tmp;

        cin >> t;

        vector<int> arr(t);

        fori(t, i){
            
            cin >> n >> m >> x >> y;
            singles = doubles = prev = 0;

            forj(n, j){

                forp(m, p){
                    cin >> tmp;
                    if(tmp == '.'){
                        if(prev){
                            doubles++;
                            prev = 0;
                        }
                        else
                            prev = 1;
                    }
                    else if (prev)
                    {
                        singles++;
                        prev = 0;
                    }
                     arr[i] = p;
                }
                if(prev){
                    singles++;
                    prev = 0;
                }
                arr[i] = j;
            }
            if(y > 2*x)
                arr[i] = x*(singles + 2*doubles);
            else
                arr[i] = x*singles + y*doubles;
        }
    
    fori(t, i){
        cout << arr[i] << endl;
    }
    return 0;
    }