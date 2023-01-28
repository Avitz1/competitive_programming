    #include <iostream>
    //#include <bits/stdc++.h>
    #include <queue>
    #include <map>

    using namespace std;
    #define fori(n, i) for( int i=0; i<n; i++)
    #define fori1(n, i) for( int i=1; i<=n; i++)
     
     
    long long n_minus_k_plus1_factorial(int n, int k){

        long long result = 1;
        for(long long i=n-k+1; i<=n;i++){
            result *= i;
            result = result % 998244353;
        }
            
        if(n < (k+1))
            return 1;
        return result;
    }

    int main(){
        
        int n, k, start = 0, prevEnd = 0, tmp1, tmp2, size, kMinus1_factorial; 
        
        long long result = 1, k_factorial = 1;
        string input;
        cin >> n >> k;
        
        cin >> input;

        for(long long i=1; i<=k;i++){
            k_factorial*=i;
            result = result % 998244353;
        }

        kMinus1_factorial = (k < 3)?1:k_factorial/k;

        std::queue<int> q;
        std::map<int, long long> m;

        if(k==0){
            cout << 1;
            return 0;
        }
        fori(n, i){
            if(input[i] == '1')
                 q.push(i);

            size = q.size();
            if((k == size) && ((i == n -1)||input[i + 1] == '1')){
                tmp1 = i - start + 1; tmp2 = prevEnd - start + 1;
                auto t = m.find(tmp1);
                if(t == m.end()) m[tmp1] = n_minus_k_plus1_factorial(tmp1, k); 

                t = m.find(tmp2);
                if(t == m.end()) m[tmp2] = n_minus_k_plus1_factorial(tmp2, k - 1); 

                result +=  m[tmp1]/k_factorial;
                if(!prevEnd && i==n-1)
                    result--;
                else
                    result -= m[tmp2]/kMinus1_factorial;
               
                start = q.front()+1;
                q.pop();  
                prevEnd = i;
                result = result % 998244353;
            }
        }

        if(!result)
            result = 1;
        
        cout << result;
        
        return 0;
    }