#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fori(n, i) for (int i = 0; i<n; i++)
#define forj(n, j) for (long unsigned int j = 0; j<n; j++) 


int main(){
    
    // //if we have k>=25 the string will be aaa...
    // //in any other case, we notice, we will start with the changes appleid on the heigher letters and then follow downwords.
    // //we can be greedy! we want the first letter to be the smallest possible
    // //so we will take it as "low" as we can and then continue along the string

    // int t, n, k, p;
    // string str;
    // cin >> t;

    // vector<string> arr(t);
    
    // char replace[26];
    // char tmp, new_tmp;

    // fori(t, i){
    //     cin >> n >> k >> str;
    //     if(k >= 25){
    //         fill(str.begin(), str.end(), 'a');
    //         arr[i]=str;
    //         continue;
    //     }
    //     forj(26, j){
    //         replace[j] = 'a' + j;
    //     }
    //     forj(str.size(), j){
    //         tmp = str[j];
    //         new_tmp = tmp;
    //         while(replace[new_tmp-'a']==new_tmp && k && new_tmp!='a'){
    //             new_tmp--; k--;
    //         }

    //         if(k)
    //             new_tmp = 'a';
        
    //         for(p=new_tmp-'a'; p<tmp-'a'; p++){
    //             replace[p] = new_tmp;
    //         }
    //         for(p=tmp-'a'; p<26; p++){
    //             if(replace[p] <= tmp)
    //                 replace[p]=new_tmp;
    //         }

    //         if(!k)
    //             break;        
    //     }
        
    //     forj(str.size(), j){
    //         str[j] = replace[str[j]-'a'];
    //     }

    //     arr[i] = str;
    // }
    
    int t, k, n,p;
    string str;

    cin >> t;

    vector<string> arr(t);

    char max_to_become_a, max_to_change, max_to_change_value;

    fori(t, i){
        cin >> n >> k >> str;
        if(k >= 25){
            fill(str.begin(), str.end(), 'a');
            arr[i]=str;
            continue;
        }
        
        max_to_become_a = 'a';
        p=0;

        if((str[p]-k) == 'a'){
            max_to_become_a = str[p];
            max_to_change = 0;
            max_to_change_value = 0;
        }
        else if((str[p]-k) > 'a'){
            max_to_become_a = 0;
            max_to_change = str[p];
            max_to_change_value = str[p]-k;
        }
        else{
            for(p=0; p<n-1 && (str[p+1]-k <'a'); p++)
                max_to_become_a = max(max_to_become_a, str[p]); 
            max_to_become_a = max(max_to_become_a, str[p]); 
            k -= (max_to_become_a - 'a');

            if(k && p<n-1){
                max_to_change = str[p+1];
                max_to_change_value = max_to_change - k;
                if(max_to_change_value <= max_to_become_a)
                    max_to_become_a = max_to_change;
            }
            else{
                max_to_change = 0;
                max_to_change_value = 0;
            }        
        }
        
        forj(str.size(), j){
            if(str[j] <= max_to_become_a)
                str[j] = 'a';
            else if(str[j] <= max_to_change && str[j] > max_to_change_value)
                str[j] = max_to_change_value;
        }
        arr[i] = str;
    }




    fori(t, i)
        cout << arr[i] << endl;
        
    return 0;
}