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

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int tests;
    cin>>tests;
    while(tests--){
        int streets;
        cin>>streets;
        char ch;
        vector<char> v(streets);
        string s, ans;
        cin>>s;
        F(i, 0 , streets){
            ans+='.';
        }
        F(i, 0 , streets){
            if(ans[i] != '*')
                ans[i] = s[i];
            if(s[i] == '*'){
                if(i > 0) ans[i-1] = '*';
                if(i < streets - 1) {
                    ans[i+1] = '*';
                }
            }
        }
        int total = 0;
        F(i, 0, streets) {
            if(ans[i] == '.'){
                int j = 0;
                while(ans[i] == '.' && i < streets){
                    j++;
                    i++;
                }
                total += j / 3;
                if(j % 3 != 0) total++;
            }
        }
        cout<<total<<endl;
    }
    //END

    return 0;
}
