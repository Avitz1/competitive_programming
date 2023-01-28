#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fori(n, i) for (int i = 0; i<n; i++)
#define forj(n, j) for (int j = 0; j<n; j++) 

vector<int> parents, sizes;

int find(int parent){
    if(parents[parent] == parent)
        return parent;
    return parents[parent] = find(parents[parent]);
}

int onion(int i, int j){                                    //a union function that returns whether a union has occured
    int j_ancestor, i_ancestor;
    i_ancestor = find(i);
    j_ancestor = find(j);
    if(i_ancestor == j_ancestor)
        return 0;                                           //the number of sets hasn't change
    if(sizes[j_ancestor] > sizes[i_ancestor])
        swap(i_ancestor, j_ancestor);
    parents[j_ancestor] = i_ancestor;
    sizes[i_ancestor] += sizes[j_ancestor];
    return 1;                                               //it has been decreased by one
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> arr_rows(1000), arr_cols(1000);                //we keep track of who was here last

    int n, result = -1, tmp_x, tmp_y, x_set, y_set;
    cin >> n;

    fori(n, i){
        cin >> tmp_x >> tmp_y;
        x_set = arr_rows[tmp_x];
        y_set = arr_cols[tmp_y];

        if(!x_set || !y_set)                     
        {
            if(!x_set && !y_set)                    //we should create a new set
            {
                parents.push_back(parents.size());
                sizes.push_back(1);
                arr_rows[tmp_x] = parents.size();
                arr_cols[tmp_y] = parents.size();
                result++;
            }
            else{
                if(x_set)                                     //we enlarge an existing set
                    arr_cols[tmp_y] = x_set;
                else
                    arr_rows[tmp_x] = y_set;
            }
        }
        else if(x_set != y_set){                    //we unite 2 disjoint sets
            result -= onion(x_set-1, y_set-1);
        }
    }

    cout << result;

    return 0;
}