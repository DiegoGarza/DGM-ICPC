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

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    string s;
    while(getline(cin, s), s!="DONE"){
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] != '?' && s[i] != '!' && s[i] != ',' && s[i] != '.' && s[i] != ' '){
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    ans+=s[i]+('a' - 'A');
                }
                else{
                    ans+=s[i];
                }
            }
        }
        //cout<<ans<<endl;
        int l, r;
        l = ans.length() /2;
        r = l+1;
        if(ans.length() % 2 == 1){
            l--;
        }
        else{
            l--;
            r--;
        }
        //cout<<l<<" "<<r<<endl;
        bool notPal = false;
        while(l!=-1){
            if(ans[l] != ans[r]){
                notPal = true;
                break;
            }
            l--;
            r++;
        }
        if(notPal){
            cout<<"Uh oh.."<<endl;
        }
        else{
            cout<<"You won't be eaten!"<<endl;;
        }
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
