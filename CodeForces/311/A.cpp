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
#include <iterator>
#include <limits>
#include <fstream>

#define F(i, b, a) for( int i = (b); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int cleanRow(int row, vvi mat, int n){
    for(int j=0; j<n; j++){
        if(!mat[row][j]) {
            for(int i=0; i<n; i++){
                mat[i][j] = (mat[i][j] + 1) % 2;
            }
        }
    }
    int totalClean = 0;
    for(int i=0; i<n; i++){
        int j = 0;
        for(j = 0; j<n; j++){
            if(!mat[i][j]) break;
        }
        if(j==n) totalClean++;
    }
    return totalClean;
}

int main(){
    //STARTS
    int size;
    string s;
    cin>>size;
    vvi mat(size, vi(size));
    for(int i=0; i<size; i++){
        cin>>s;
        for(int j=0; j<size; j++){
            mat[i][j] = s[j] - '0';
        }
    }
    int max = 0, aux;
    for(int i=0; i<size; i++){
        aux = cleanRow(i, mat, size);
        if(aux > max) max = aux;
    }
    cout<<max<<endl;
    //END

    return 0;
}
