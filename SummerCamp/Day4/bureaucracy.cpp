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

int laws[100005];
bitset<100005> cancelled;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    ifstream in("bureau.in");
    ofstream out("bureau.out");

    //STARTS
    int n;
    string s;
    in>>n;
    in.ignore();
    F(i,1,n+1){
        getline(in, s);
        if(s[0] == 'd'){
            laws[i] = 0;
        }
        else if(s[0] == 'c'){
            stringstream ss(s);
            string s1;
            int a;
            ss>>s1>>a;
            laws[i] = a;
        }
    }
    for(int i=n; i>0; i--){
        if(!cancelled[i]){
            if(laws[i]){
                cancelled[laws[i]] = 1;
            }
        }
    }
    int total = 0;
    F(i,1,n+1){
        if(!cancelled[i]) total++;
    }
    out<<total<<endl;
    F(i,1,n+1){
        if(!cancelled[i]) out<<i<<" ";
    }
    out<<endl;
    //END

    return 0;
}
