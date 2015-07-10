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
    in = fopen("lcs.in", "r");
    out = fopen("lcs.out", "w+");

    //STARTS
    int lcs[2001][2001] = {0};
    int a[2001], b[2001];
    int n1, n2, intI;

    fscanf(in, "%d", &n1);

    F(i, n1){
        fscanf(in, "%d", &a[i+1]);
    }

    fscanf(in, "%d", &n2);

    F(i, n2){
        fscanf(in, "%d", &b[i+1]);
    }

    int max = 0, iMax, jMax;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            lcs[i][j] = Max(lcs[i-1][j], lcs[i][j-1]);
            if(a[i]==b[j]){
                lcs[i][j] = Max(lcs[i][j], 1 + lcs[i-1][j-1]);
                if(lcs[i][j]>max){
                    max = lcs[i][j];
                }
            }
        }
    }

    int i = n1;
    int j = n2;
    stack<int> s;

    fprintf(out, "%d\n", max);

    while(lcs[i][j]!=0){
        if(lcs[i-1][j]!=lcs[i][j]&&lcs[i][j-1]!=lcs[i][j]){
            s.push(a[i]);
            i--;
            j--;
        }
        else if(lcs[i-1][j]==lcs[i][j]){
            i--;
        }
        else if(lcs[i][j-1]==lcs[i][j]){
            j--;
        }
    }

    while(!s.empty()){
        fprintf(out, "%d ", s.top());
        s.pop();
    }
    fprintf(out, "\n");

    //END

    fclose(in);
    fclose(out);
    return 0;
}
