#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define F(i, a) for( int i = (0); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

int main(){
    FILE *in, *out;
    in = fopen("knapsack.in", "r");
    out = fopen("knapsack.out", "w+");

    //STARTS
    int n, m, intI;
    // int knap [1001][1000];
    vector<int> w;
    vector<int> c;

    fscanf(in, "%d%d", &n, &m);

    vector<vector <int> > knap(n+1, vector<int>(m+1, 0));

    for(int i=0; i<n; i++){
        fscanf(in,"%d", &intI);
        w.push_back(intI);
    }

    for(int i=0; i<n; i++){
        fscanf(in, "%d", &intI);
        c.push_back(intI);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(w[i-1]<=j){
                knap[i][j] = Max(knap[i-1][j], knap[i-1][j-w[i-1]] + c[i-1]);
            }
            else{
                knap[i][j] = knap[i-1][j];
            }
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout<<knap[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    stack<int> s;
    int i = n;
    int j = m;
    for(int i=n; i>0; i--){
        if(knap[i][j] > knap[i-1][j]){
            s.push(i);
            j -= w[i-1];
        }
    }
    fprintf(out, "%d\n", s.size());
    while(!s.empty())
    {
        fprintf(out, "%d ", s.top());
        s.pop();
    }
    fprintf(out, "\n");

    //END

    fclose(in);
    fclose(out);
    return 0;
}
