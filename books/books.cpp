#include <bits/stdc++.h>
using namespace std;
#define fori(n, i) for(int i=0; i<n; i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;



int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, pages;
    char c;

    queue<int> prints;
    stack<int> books;

    map<int, int> heapContent;

    cin >> q;

    fori(q, i){
        cin >> c;
        switch (c)
        {
        case '+':{
            cin >> pages;
            heapContent[pages]++;
            books.push(pages);
            break;
        }
        case '-':{
            prints.push(books.top());

            auto t = heapContent.find(books.top());
            if(!(--t->second))
                heapContent.erase(t);
            books.pop();
            break;
        }
        case '?':{
             prints.push(heapContent.begin()->first);
            break;
        }
        }
    }

    while(!prints.empty()){
        cout << prints.front() << endl;
        prints.pop();
    }
    
    return 0;
}