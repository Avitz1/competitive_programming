    #include <iostream>
    using namespace std;
    #define fori(n, i) for( int i=0; i<n; i++)
     
     
    int main(){
        
        int n, m, k, t, x, y;
        cin >> t;
     
        fori(t, i){
     
            cin >> n >> m >> k;
            x = std::min(n/k, m);
            y = (m - x)/(k - 1) + (0|((m - x)%(k - 1)));
            cout << x - y << endl;
     
        }
        
     
        return 0;
    }