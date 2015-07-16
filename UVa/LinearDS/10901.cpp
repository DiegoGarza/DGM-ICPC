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
    cin>>cases;
    while(cases--){
        int boatSide = 0, time = 0, travel, size, cars;
        cin>>size>> travel>> cars;
        queue<int> left, right;
        while(cars--){
            int arrival;
            string sside;
            cin>>arrival>>sside;
            (sside == "left") ? left.push(arrival) : right.push(arrival);
        }
        vi ans;
        int current = 0, currSide = 0;
        while(!left.empty() || !right.empty()){
            int nextL, nextR;
            int side;
            (!left.empty()) ? nextL = left.front() : nextL = -1;
            (!right.empty()) ? nextR = right.front() : nextR = -1;
            int next;
            if(nextL != -1 && nextR != -1){
                if(nextL == -1) next = nextR;
                else if(nextR == -1) next = nextL;
                else {
                    next = Min(nextR, nextL);
                }
                (nextL == next) ? side = 0 : side = 1;
                if(currSide != side) time += travel;
                currSide = side;
                (currSide == 0) ? left.pop() : right.pop();
                ans.push_back(time + travel);
            }
        }
        F(i, ans.size()){
            cout<<ans[i]<<endl;
        }
        //if(cases != 0)
            cout<<endl;
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
