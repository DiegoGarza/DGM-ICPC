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
    multiset<string> ms;
    multiset<string>::iterator itlow,itup;
    int cases, words;
    string word;
    cin>>cases;
    F(i, 0, cases) {
        cin>>words;
        int total = 0;
        F(j, 0, words){
            cin>>word;
            if(ms.empty()) {
                total++;
                ms.insert(word);
            }
            else{
                string aux;
                itlow = ms.lower_bound (word);
                itup = ms.upper_bound (word);
                if(itlow == ms.end()) itlow--;
                if(itup == ms.end()) itup--;
                aux = *itlow;
                int lw = 0, up = 0;
                int k;
                for(k = 0; k<word.length() && aux[k] == word[k]; k++){
                    lw++;
                }
                if(k!=word.length()) lw++;
                if(*itup == *itlow && itlow != ms.begin()){
                    itup--;
                    aux = *itup;
                    for(k = 0; k<word.length() && aux[k] == word[k]; k++){
                        up++;
                    }
                    if(k!=word.length()) up++;
                }
                total+=Max(lw, up);
                ms.insert(word);
            }
        }
        ms.clear();
        cout<<"Case #"<<i+1<<": "<<total<<endl;
    }
    //END

    return 0;
}
