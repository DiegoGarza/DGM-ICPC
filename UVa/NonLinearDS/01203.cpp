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

class comp
{
public:
    bool operator()(const pair<int,int>& n1, const pair<int,int>& n2) {
        if(n1.second == n2.second) return n1.first > n2.first;
        return n1.second > n2.second;
    }
};

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    string s;
    priority_queue<pair<int,int>,vector<pair<int,int> >, comp> pq;
    map<int, int> initial;
    while(cin>>s, s!="#"){
        int id, period;
        cin>>id>>period;
        pq.push(make_pair(id, period));
        initial[id] = period;
    }
    int k;
    cin>>k;
    while(k--){
        cout<<pq.top().first<<endl;
        pq.push(make_pair(pq.top().first, pq.top().second + initial[pq.top().first]));
        pq.pop();
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
