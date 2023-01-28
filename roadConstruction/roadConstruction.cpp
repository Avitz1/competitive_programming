#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

#define MAX 1e5
#define fori(n, i) for (int i = 0; i<n; i++)
#define forFrom1(n, i) for (int i = 1; i<=n; i++)

int findRepresentitive(vi& arr, int i){
    int parent = arr[i];
    if(arr[parent] == parent)
    {
        return parent;
    }
    return arr[i] = findRepresentitive(arr, parent);
}

void unionAB(vi& sizes, vi& parents, int a, int b) {
    if(sizes[a] > sizes[b])
        swap (a, b);

    parents[b] = a;
    sizes[a] += sizes[b];
}

int main() { 
    int n, m, a, b, maxSize = 1;
    cin >> n >> m;
    vi sizes(MAX + 1, 1), parents(MAX + 1);

    forFrom1(MAX, i) parents[i] = i;

    fori(m,i){
        cin >> a >> b;
        a = findRepresentitive(parents, a);
        b = findRepresentitive(parents, b);
        
        if(a != b){
            // unionAB(sizes, parents, a, b);
            if(sizes[a] > sizes[b])
                swap (a, b);

            parents[b] = a;
            sizes[a] += sizes[b];
            maxSize = max(maxSize, max(sizes[a], sizes[b]));
            n--;
        }

        cout << n << ' ' << maxSize << endl;
    }

    return 0;
}