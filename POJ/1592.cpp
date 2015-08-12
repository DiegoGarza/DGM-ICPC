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

int n, m, ans;
string s;
int mat [100][100];

void paint(int i, int j){
    int arr [] = {-1, 0, 1};
    mat[i][j] = 0;
    F(k, 0, 3){
        F(l, 0, 3){
            if(i+arr[k] >= 0 && i+arr[k] < m &&
                j+arr[l] >= 0 && j+arr[l] < n &&
                mat[i+arr[k]][j+arr[l]]) {
                    paint(i+arr[k], j+arr[l]);
                }
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    while(cin>>m>>n, n || m){
        ans = 0;
        F(i, 0, m){
            cin>>s;
            F(j, 0, n){
                if(s[j] == '@') mat[i][j] = 1;
                else mat[i][j] = 0;
            }
        }
        F(i, 0, m){
            F(j, 0, n){
                if(mat[i][j]) {
                    paint(i, j);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    //END

    return 0;
}
