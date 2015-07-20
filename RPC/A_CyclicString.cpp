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
    int cases;
    cin>>cases;
    while(cases--){
        string s;
        cin>>s;
        string aux, comp;
        F(i, 1, s.length()+1){
            aux = s.substr(0, i);
            // cout<<aux.length()<<endl;
            // cout<<aux<<endl;
            int j;
            for(j = i; j<s.length()+1; j = j + aux.length()){
                comp = s.substr(j, aux.length());
                // cout<<"comp "<<comp<<endl;
                if(aux != comp) break;
            }
            if(j>=s.length()) break;
        }
        cout<<aux.length()<<endl;
    }
    //END

    return 0;
}
