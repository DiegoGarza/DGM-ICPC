#include <iostream>
#include <cstdio>
#include <algorithm>
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
    string s;
    cin>>cases;
    cin.ignore();
    while(cases--){
        getline(cin, s);
        int k = 0, curr = 0, size = 0;
        vector<string> sounds;
        while(k<=s.length()){
            if(s[k] == ' ' || k == s.length()) {
                if(k==s.length() || curr == 0) size++;
                sounds.push_back(s.substr(curr, size-1));
                curr = k+1;
                size = 0;
            }
            size++;
            k++;
        }
        map<string, string> dict;
        while(getline(cin, s) && s != "what does the fox say?"){
            k = 0, curr = 0, size = 0;
            vs temp;
            while(k<=s.length()){
                if(s[k] == ' ' || k == s.length()) {
                    temp.push_back(s.substr(curr, size));
                    curr = k+1;
                    size = 0;
                }
                size++;
                k++;
            }
            dict[temp[2]] = temp[0];
        }
        int count = 0;
        F(i, 0, sounds.size()){
            if(dict.find(sounds[i]) == dict.end()){
                if(count) cout<<" ";
                cout<<sounds[i];
                count++;
            }
        }
        cout<<endl;
    }
    //END

    return 0;
}
