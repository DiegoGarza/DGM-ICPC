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

    //STARTS
    int fibo [46], max;
    string cipher;
    fibo[0] = 1;
    fibo[1] = 2;
    F(i, 2, 46){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    map<int, ll> m;
    int cases, n;
    ll in;
    cin>>cases;
    while(cases--){
        m.clear();
        F(i, 0, 46){
            m[fibo[i]] = 0;
        }
        max = 0;
        string ans = "";
        cin>>n;
        F(i, 0, n){
            cin>>in;
            if(in > max) max = in;
            m[in] = i+1;
        }
        cin.ignore();
        getline(cin, cipher);
        string aux = "";
        F(i, 0, cipher.length()){
            if(cipher[i] >= 'A' && cipher[i] <= 'Z') aux += cipher[i];
        }
        for(map<int, ll>::iterator it = m.find(1); it != ++m.find(max); it++){
            if(!it->second) ans += ' ';
            else ans += aux[(it->second) - 1];
        }
        int i = ans.length() - 1;
        while(ans[i] == ' ') i--;
        string ans2 = "";
        for(int j=0; j<=i; j++){
            ans2+=ans[j];
        }
        cout<<ans2<<endl;
    }
    //END

    return 0;
}
