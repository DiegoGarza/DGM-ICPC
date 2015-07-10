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
#include <fstream>

#define F(i, a) for( int i = (0); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

int main(){
    // FILE *in, *out;
    // in = fopen("levenshtein.in", "r");
    // out = fopen("levenshtein.out", "w+");

    ifstream in;
    ofstream out;
    in.open("levenshtein.in");
    out.open("levenshtein.out");

    //STARTS
    string a, b;
    int arra[5001], arrb[5001];

    getline(in,a);
    getline(in,b);

    F(i, a.length()){
        arra[i]=(int)a[i];
    }

    F(i, b.length()){
        arrb[i]=(int)b[i];
    }

    vector<vector<int> > lev(a.length()+1, vector<int>(b.length()+1));

    for(int i=1; i<=a.length(); i++){
        lev[i][0] = i;
    }

    for(int i=1; i<=b.length(); i++){
        lev[0][i] = i;
    }
    // cout<<b<<endl;

    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            lev[i][j] = Min(lev[i][j-1] + 1, lev[i-1][j] + 1);
            lev[i][j] = Min(lev[i][j], lev[i-1][j-1] + 1);
            if(a[i-1]==b[j-1]){
                lev[i][j] = lev[i-1][j-1];
            }
        }
    }

    out<<lev[a.length()][b.length()]<<endl;

    //END

    in.close();
    out.close();
    return 0;
}
