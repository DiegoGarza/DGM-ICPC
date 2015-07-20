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

struct Team{
    string name;
    int prob;
    int pen;
    Team() { name = ""; prob = 0; pen = 0; }
    Team(string s, int a, int b) { name = s; prob = a; pen = b; }
};

bool comp(const Team& a, const Team& b){
    if(a.prob == b.prob) return a.pen < b.pen;
    return a.prob > b.prob;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    vector<Team> v;
    int tests;
    cin>>tests;
    while(tests--){
        int teams;
        v.clear();
        cin>>teams;
        while(teams--){
            string s;
            int a, b;
            cin>>s>>a>>b;
            v.push_back(Team(s, a, b));
        }
        sort(v.begin(), v.end(), comp);
        cout<<v[0].name<<endl;
    }
    //END

    return 0;
}
