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

bool comp(const pair<string, int>& a, const pair<string, int>& b){
    return a.first < b.first;
}

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    string s;
    vector<string> norm;
    vector<pair <string, int> >low;
    int j=0;
    while(cin>>s){
        if(s == "#"){
            break;
        }
        string lower="";
        F(i, s.length()){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                lower+=s[i]-('A' - 'a');
            }
            else{
                lower+=s[i];
            }
        }
        sort(lower.begin(), lower.end());
        norm.push_back(s);
        low.push_back(make_pair(lower, j));
        j++;
    }

    sort(low.begin(), low.end(), comp);

    bool eraseNext = false;
    F(i, low.size()){
        //cout<<low[i].first<<" "<<low[i + 1].first<<endl;
        if(i+1 < low.size() && low[i].first == low[i+1].first){
            //cout<<"yes"<<endl;
            low.erase(low.begin()+i, low.begin()+i+1);
            eraseNext = true;
            i--;
        }
        else if(eraseNext){
            low.erase(low.begin()+i, low.begin()+i+1);
            eraseNext = false;
            i--;
        }
        //cout<<i<<endl;
    }

    vector<string> ans;
    F(i, low.size()){
        ans.push_back(norm[low[i].second]);
    }

    sort(ans.begin(), ans.end());

    F(i, ans.size()){
        cout<<ans[i]<<endl;
    }

    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
