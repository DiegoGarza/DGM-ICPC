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
#include <fstream>

#define F(i, a) for( int i = (0); i < (a); i++ )
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

vs ans;

void dfs (int i, int j, string a, string b, stack<char>& s, string& curr){
    if(j >= b.length()){
        ans.push_back(curr);
    }
    else {
        for(int k = i; k<=a.length(); k++){
            string aux = curr;
            stack<char> auxStack = s;
            if(!s.empty() && s.top() == b[j]) {
                aux += "o";
                auxStack.pop();
                dfs (k, j+1, a, b, auxStack, aux);
            }
            curr += "i";
            if(k<a.length())
                s.push(a[k]);
        }
    }
}

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    string a, b;
    while(cin>>a){
        cin>>b;
        ans.clear();
        string curr = "";
        stack<char> s;
        dfs(0, 0, a, b, s, curr);
        sort(ans.begin(), ans.end());
        cout<<"["<<endl;
        F(i, ans.size()){
            F(j, ans[i].length()){
                cout<<ans[i][j];
                if(j != ans[i].length()-1){
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        cout<<"]"<<endl;
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
