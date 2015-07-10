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

int maxSubArray(vector<int>& nums) {
    int max = MIN_INT;
    for(int i=0; i<nums.size(); i++){

    }
}

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    vector<int> v;
    v.push_back(-2);
    v.push_back(1);
    v.push_back(-3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-5);
    v.push_back(4);
    cout<<maxSubArray(v)<<endl;
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
