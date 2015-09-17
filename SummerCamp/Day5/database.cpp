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

using namespace std;

#define F(i, b, a) for( int i = (b); i < (a); i++ )
#define Set(a, s) memset(a, s, sizeof (a))
#define INF (int)2e9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    ifstream in("database.in");
    ofstream out("database.out");

    //STARTS
    int n,m;
    string s;
    in>>n>>m;
    in.ignore();
    vector<vector<string> > mat(n, vector<string>(m));
    F(i,0,n){
        getline(in, s);
        int start = 0;
        int c = 0;
        F(j,0,s.length() + 1){
            if(s[j] == ',' || j == s.length()){
                mat[i][c] = s.substr(start, j - start);
                start = j + 1;
                c++;
            }
        }
    }
    map<string, int> ma;
    F(k,0,m){
        F(i,0,n){
            if(ma.find(mat[i][k]) == ma.end()) ma[mat[i][k]] = i;
            else {
                int j = ma[mat[i][k]];
                F(l, k+1, m){
                    if(mat[i][l] == mat[j][l]){
                        out<<"NO"<<endl;
                        out<<j+1<<" "<<i+1<<endl;
                        out<<k+1<<" "<<l+1<<endl;
                        return 0;
                    }
                }
            }
        }
        ma.clear();
    }
    out<<"YES"<<endl;
    //END

    return 0;
}
