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

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    int cases;
    string s;
    cin>>cases;
    cin.ignore();   //Ignore previous cin
    cin.ignore();   //Ignore first separating blank line
    while(cases--){
        map<string, double> m;
        double total = 0;
        while(getline(cin, s)){
            if(s == "") break;
            (m.find(s) == m.end()) ?
                m[s] = 1 : m[s]++;
            total++;
        }
        for (map<string, double>::iterator it = m.begin(); it != m.end(); it++){
            cout<<it->first<<" ";
            printf("%.4f\n", it->second/total*100);
        }
        if(cases)
            printf("\n");
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
