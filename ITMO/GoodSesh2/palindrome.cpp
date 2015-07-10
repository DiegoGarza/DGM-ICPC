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
    // FILE *in, *out;
    // in = fopen("palindrome.in", "r");
    // out = fopen("palindrome.out", "w+");

    ifstream in;
    ofstream out;
    in.open("levenshtein.in");
    out.open("levenshtein.out");

    //STARTS
    int lcs[2001][2001] = {0};
    int n1, n2, intI;
    string a, b;

    getline(in,a);
    

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

    in.close();
    out.close();
    return 0;
}
